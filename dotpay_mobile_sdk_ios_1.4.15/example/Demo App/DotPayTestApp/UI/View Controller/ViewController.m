//
//  ViewController.m
//  DotPay Test
//
//  Created by Mateusz Maćkowiak on 24/07/15.
//  Copyright (c) 2015 DotPay. All rights reserved.
//

#import "ViewController.h"
#import "AdditionalInfoTableViewController.h"
#import "AdditionalInfo.h"
#import <DotPaySDK/DotPaySDK.h>
#import "UIAlertController+ShowOnTopViewController.h"

@interface ViewController () <UITextFieldDelegate, DPDotPayViewControllerDelegate, DPMasterpassPaymentDelegate, DPOneClickManagerDelegate, UIPickerViewDataSource, UIPickerViewDelegate>
@property (weak, nonatomic) IBOutlet UITextField *merchantIdTextField;
@property (weak, nonatomic) IBOutlet UITextField *amountTextField;
@property (weak, nonatomic) IBOutlet UITextField *currencyTextField;
@property (weak, nonatomic) IBOutlet UITextField *langTextField;
@property (weak, nonatomic) IBOutlet UITextField *descriptionTextField;
@property (weak, nonatomic) IBOutlet UITextField *nameTextField;
@property (weak, nonatomic) IBOutlet UITextField *lastNameTextField;
@property (weak, nonatomic) IBOutlet UITextField *emailTextField;
@property (weak, nonatomic) IBOutlet UITextField *streetNameTextField;
@property (weak, nonatomic) IBOutlet UITextField *streetNumberTextField;
@property (weak, nonatomic) IBOutlet UITextField *houseNumberTextField;
@property (weak, nonatomic) IBOutlet UITextField *cityTextField;
@property (weak, nonatomic) IBOutlet UITextField *postCodeTextField;
@property (weak, nonatomic) IBOutlet UITextField *phoneNumberTextField;
@property (weak, nonatomic) IBOutlet UITextField *customerIdTextField;

@property (weak, nonatomic) IBOutlet UISwitch *testServerSwitch;
@property (weak, nonatomic) IBOutlet UISwitch *enableCreditCardSwitch;
@property (weak, nonatomic) IBOutlet UISwitch *enableCVVStoreSwitch;
@property (weak, nonatomic) IBOutlet UISwitch *showDetailsOnSummaryScreenSwitch;
@property (weak, nonatomic) IBOutlet UISwitch *phoneNumberVerifiedSwitch;
@property (weak, nonatomic) IBOutlet UISwitch *ccDataSwitch;
@property (weak, nonatomic) IBOutlet UISwitch *internalCardsSwitch;
    
@property (weak, nonatomic) IBOutlet UIView *contentOfScrollView;
@property (weak, nonatomic) IBOutlet UIScrollView *scrollView;
@property (weak, nonatomic) IBOutlet UIBarButtonItem *historyBarButtonItem;
@property (weak, nonatomic) IBOutlet UIButton *clearCreditCardDataButton;
@property (weak, nonatomic) IBOutlet UIButton *clearCreditCardCVVDataButton;
@property (weak, nonatomic) IBOutlet UIButton *addCreditCardsButton;
@property (weak, nonatomic) IBOutlet UIButton *clearAddedCardsButton;
@property (weak, nonatomic) IBOutlet UILabel *versionLabel;

@property (strong, nonatomic) UIPickerView *langPicker;

@property (weak, nonatomic) UIResponder *currentResponder;

@property (nonatomic, strong) DPPaymentInfo *paymentInfo;
@property (nonatomic, strong) DPPaymentInfoValidator *paymentInfoValidator;

@property (nonatomic, strong) NSMutableArray * additionalInfos;
@property (nonatomic, strong) NSMutableArray<DPOneClickExternalPaymentCard *> *customCreditCards;

@property (nonatomic, strong) UITapGestureRecognizer *tapRecognizer;

@property (nonatomic, strong) NSArray *langPickerData;
@end

@implementation ViewController

- (void)dotpayViewController:(DPDotPayViewController *)dotpayViewController didFinishPaymentWithSummary:(DPPaymentSummary *)paymentSummary {
    NSLog(@"Did finish payment with paymentSummary %@",paymentSummary);
}

- (void)dotpayViewController:(DPDotPayViewController *)dotpayViewController didFailToFinishPaymentWithError:(NSError *)error {
    NSLog(@"Did fail with error %@",error);
}

- (void)viewDidLoad {
    [super viewDidLoad];
    [self setupLangPicker];
    self.customCreditCards = [[NSMutableArray alloc] init];
    self.edgesForExtendedLayout = UIRectEdgeNone;
    self.paymentInfo = [[DPPaymentInfo alloc] init];
    [DPOneClickManager sharedInstance].delegate = self;
    self.paymentInfoValidator = [[DPPaymentInfoValidator alloc] init];
    self.title = @"DotPay";
    self.additionalInfos = [NSKeyedUnarchiver unarchiveObjectWithData:[[NSUserDefaults standardUserDefaults] objectForKey:kAddititionalInfoKey]];
    if (!self.additionalInfos) {
        self.additionalInfos = [[NSMutableArray alloc] init];
    }
    self.versionLabel.text = [NSString stringWithFormat:@"Framework ver.: %@",[DotPay sharedInstance].sdkShortVersionString];
    [DotPay sharedInstance].debugMode = YES;
    [self setUpDelegatesForTextFields];
    [self addTapGestureRecognizer];
}

- (void)addTapGestureRecognizer {
    self.tapRecognizer = [[UITapGestureRecognizer alloc] initWithTarget:self action:@selector(tapGestureRecognized:)];
    [self.scrollView addGestureRecognizer:self.tapRecognizer];
}

- (void)setupLangPicker{
    // has to be 2 letters
    self.langPickerData = @[@"pl", @"en", @"sk", @"cs"];
    UIPickerView* picker = [[UIPickerView alloc] init];
    picker.delegate = self;
    picker.dataSource = self;
    self.langTextField.inputView = picker;
}

- (void)viewDidAppear:(BOOL)animated {
    [super viewDidAppear:animated];
    self.historyBarButtonItem.enabled = [DPPaymentHistory sharedInstance].paymentHistory.count > 0;
    self.testServerSwitch.on = [DotPay sharedInstance].debugMode;
    self.clearCreditCardDataButton.enabled = [DPOneClickManager sharedInstance].isDataAvailable;
    self.showDetailsOnSummaryScreenSwitch.on = [DotPay sharedInstance].showDetailsOnSummaryScreen;
}

- (void)configureOneClickManagerWithExternalCCData:(BOOL)shouldConfigure {
    NSArray<DPOneClickExternalPaymentCard *> *cards = shouldConfigure ? self.customCreditCards : @[];
    NSString *customerId = shouldConfigure ? self.customerIdTextField.text : NULL;
    [[DPOneClickManager sharedInstance] configureWithExternalCards:cards forCustomerId:customerId];
}

- (void)setUpDelegatesForTextFields{
    self.merchantIdTextField.delegate = self;
    self.amountTextField.delegate = self;
    self.currencyTextField.delegate = self;
    self.langTextField.delegate = self;
    self.descriptionTextField.delegate = self;
    self.nameTextField.delegate = self;
    self.emailTextField.delegate = self;
    self.streetNameTextField.delegate = self;
    self.streetNumberTextField.delegate = self;
    self.houseNumberTextField.delegate = self;
    self.cityTextField.delegate = self;
    self.postCodeTextField.delegate = self;
    self.lastNameTextField.delegate = self;
    self.phoneNumberTextField.delegate = self;
    self.customerIdTextField.delegate = self;
}

- (void)tapGestureRecognized:(UITapGestureRecognizer *)recognizer {
    [self.currentResponder resignFirstResponder];
}

- (BOOL)textFieldShouldReturn:(UITextField *)textField{
    if (textField == self.customerIdTextField) {
        [self configureOneClickManagerWithExternalCCData:self.ccDataSwitch.isOn];
    }
    [self.currentResponder resignFirstResponder];
    return YES;
}

- (BOOL)textFieldShouldEndEditing:(UITextField *)textField {
    return YES;
}

- (void)textFieldDidBeginEditing:(UITextField *)textField{
    self.currentResponder = textField;
}

-(void)updatePaymentInfoFromForm {
    [DotPay sharedInstance].defaultLanguage = self.langTextField.text;

    self.paymentInfo.amount = [NSDecimalNumber decimalNumberWithString:self.amountTextField.text];
    self.paymentInfo.merchantID = self.merchantIdTextField.text;
    self.paymentInfo.currency = [DPCurrency currencyWithCode:self.currencyTextField.text];
    self.paymentInfo.textDescription = self.descriptionTextField.text;
    
    NSString *phoneNumber = [self.phoneNumberTextField.text length] > 8 ? self.phoneNumberTextField.text : nil;
    BOOL phoneNumberVerified = phoneNumber ? self.phoneNumberVerifiedSwitch.on : NO;
    NSString *phoneNumberVerifiedString = phoneNumberVerified ? @"YES" : @"NO";
    self.paymentInfo.senderInformation = @{@"firstname": self.nameTextField.text,
                                      @"lastname": self.lastNameTextField.text,
                                      @"phone": self.phoneNumberTextField.text,
                                      @"phone_verified": phoneNumberVerifiedString,
                                      @"street": self.streetNameTextField.text,
                                      @"street_n1": self.streetNumberTextField.text,
                                      @"postcode":  self.postCodeTextField.text,
                                      @"city": self.cityTextField.text,
                                      @"email": self.emailTextField.text};
    self.paymentInfo.additionalInformation = [self convertAdditionalInfoToDictionary:self.additionalInfos];
}

- (NSDictionary *)creditCardInfoToDict:(NSString *)creditCardInfo {
    NSData *data = [creditCardInfo dataUsingEncoding:NSUTF8StringEncoding];
    NSError *error;
    NSDictionary *jsonDict = [NSJSONSerialization JSONObjectWithData:data options:NSJSONReadingAllowFragments error:&error];
    if (jsonDict[@"credit_card"]) {
        return jsonDict[@"credit_card"];
    } else {
        return jsonDict;
    }
}

-(NSDictionary *)convertAdditionalInfoToDictionary:(NSArray *)additionalInfos {
    NSMutableDictionary * addi = [NSMutableDictionary dictionary];
    for (AdditionalInfo *additionalInfo in additionalInfos) {
        if(additionalInfo.key.length < 1 || additionalInfo.value.length < 1){
            continue;
        }
        addi[additionalInfo.key] = additionalInfo.value;
    }
    return addi;
}

- (void)showChannelList {
    __weak __typeof(self) weakSelf = self;
    [[DotPay sharedInstance] getChannelListForPaymentInfo:self.paymentInfo withCompletion:^(NSArray *channelList, DPPaymentDetails *paymentDetails, NSError *error) {
        dispatch_async(dispatch_get_main_queue(), ^{
            if (!channelList) {
                [weakSelf showMessage:[NSString stringWithFormat:@"Error getting channel list: %@", error.localizedDescription] title:@"Error"];
                return;
            }
            __strong __typeof(weakSelf) strongSelf = weakSelf;
            DPDotPayViewController *dotPayViewController = [[DPDotPayViewController alloc] initWithPaymentChannelList:channelList paymentDetails:paymentDetails];
            dotPayViewController.paymentControllerDelegate = weakSelf;
            dotPayViewController.masterpassPaymentDelegate = weakSelf;
            [strongSelf presentViewController:dotPayViewController animated:YES completion:NULL];
        });
    }];
}

- (void)showMessage:(NSString *)message title:(NSString*)title{
    UIAlertView *alertView = [[UIAlertView alloc] initWithTitle:title message:message delegate:nil cancelButtonTitle:@"OK" otherButtonTitles:nil];
    [alertView show];
}

#pragma mark - action method

- (IBAction)oneClickSwitchValueChanged:(UISwitch *)sender {
    [DPOneClickManager sharedInstance].enabled = sender.isOn;
}

- (IBAction)ccDataSwitchValueChanged:(UISwitch *)sender {
    [self configureOneClickManagerWithExternalCCData:sender.isOn];
}

- (IBAction)treatCvvAsPasswordSwitchValueChanged:(UISwitch *)sender {
    [DPOneClickManager sharedInstance].treatsCvvAsPassword = sender.isOn;
}

- (IBAction)showDetailsOnSummaryScreenSwitchChanged:(UISwitch *)sender {
    [DotPay sharedInstance].showDetailsOnSummaryScreen = sender.isOn;
}

- (IBAction)clearCreditCardDataButtonTapped:(UIButton *)sender {
    [[DPOneClickManager sharedInstance] clearData];
    sender.enabled = [DPOneClickManager sharedInstance].isDataAvailable;
}

- (IBAction)historyTapped:(id)sender {
    [DotPay sharedInstance].defaultLanguage = self.langTextField.text;
    DPPaymentHistoryViewController *historyController = [[DPPaymentHistoryViewController alloc] initWithPaymentHistory:nil];
    [self presentViewController:historyController animated:YES completion:NULL];
}

- (IBAction)didTapCardsButton:(UIBarButtonItem *)sender {
    DPOneClickPaymentCardManagerViewController *vc = [[DPOneClickPaymentCardManagerViewController alloc] initWithMerchantId:self.merchantIdTextField.text currency:self.currencyTextField.text firstName:self.nameTextField.text lastName:self.lastNameTextField.text email:self.emailTextField.text];
    [self presentViewController:vc animated:YES completion:nil];
}

- (IBAction)clearCardsTapped:(UIButton *)sender {
    [self.customCreditCards removeAllObjects];
    [self.addCreditCardsButton setTitle:@"Add credit card (0 added)" forState:UIControlStateNormal];
}

- (IBAction)addCreditCardTapped:(UIButton *)sender {
    UIAlertController *alert = [UIAlertController alertControllerWithTitle:@"Wprowadź dane karty" message:NULL preferredStyle:UIAlertControllerStyleAlert];
    [alert addTextFieldWithConfigurationHandler:^(UITextField * _Nonnull textField) {
        textField.placeholder = @"credit_card_id";
    }];
    [alert addTextFieldWithConfigurationHandler:^(UITextField * _Nonnull textField) {
        textField.placeholder = @"masked_number";
    }];
    [alert addTextFieldWithConfigurationHandler:^(UITextField * _Nonnull textField) {
        textField.placeholder = @"brand_name";
    }];
    UIAlertAction *okAction = [UIAlertAction actionWithTitle:@"Ok" style:UIAlertActionStyleDefault handler:^(UIAlertAction * _Nonnull action) {
        NSString *creditCardId = alert.textFields[0].text;
        NSString *maskedNumber = alert.textFields[1].text;
        NSString *brandName = alert.textFields[2].text;
        if (!creditCardId.length || !maskedNumber.length || !brandName.length) {
            [self showFormNotFilledAlert];
        } else {
            [self.customCreditCards addObject:[self buildCreditCardWithCreditCardId:creditCardId maskedNumber:maskedNumber brandName:brandName]];
            [sender setTitle:[NSString stringWithFormat:@"Add credit card (%ld added)", (unsigned long) self.customCreditCards.count] forState:UIControlStateNormal];
            [self configureOneClickManagerWithExternalCCData:self.ccDataSwitch.isOn];
        }
    }];
    UIAlertAction *cancelAction = [UIAlertAction actionWithTitle:@"Anuluj" style:UIAlertActionStyleCancel handler:NULL];
    
    [alert addAction:okAction];
    [alert addAction:cancelAction];
    [self presentViewController:alert animated:YES completion:nil];
}

- (void)showFormNotFilledAlert {
    UIAlertController *alert = [UIAlertController alertControllerWithTitle:@"Wprowadzone dane są niekompletne" message:NULL preferredStyle:UIAlertControllerStyleAlert];
    UIAlertAction *okAction = [UIAlertAction actionWithTitle:@"Anuluj" style:UIAlertActionStyleCancel handler:NULL];
    [alert addAction:okAction];
    [self presentViewController:alert animated:YES completion:nil];
}

- (DPOneClickExternalPaymentCard *)buildCreditCardWithCreditCardId:(NSString *)creditCardId maskedNumber:(NSString *)maskedNumber brandName:(NSString *)brandName {
    BOOL isVisa = [[brandName lowercaseString] isEqualToString:@"visa"];
    brandName = isVisa ? @"Visa" : @"Mastercard";
    NSString *brandCodename = isVisa ? @"visa" : @"mastercard";
    NSString *logo = isVisa ? @"https://ssl.dotpay.pl/test_payment/cloudfs2/magellan_media/credit_card_brand/5a8d4dffdadfce585bc79787/Visa_logo_200x100.png" :
                              @"https://ssl.dotpay.pl/test_payment/cloudfs2/magellan_media/credit_card_brand/5a8d4c1cdadfce585bc79785/Mastercard_200x100.png";
    return [[DPOneClickExternalPaymentCard alloc] initWithCreditCardId:creditCardId maskedNumber:maskedNumber brandName:brandName brandCodename:brandCodename logoUrlPath:logo];
}

- (IBAction)startPaymentTapped:(id)sender {
    [self.currentResponder resignFirstResponder];
    [self updatePaymentInfoFromForm];
    NSError *error = nil;
    if (![self.paymentInfoValidator validatePaymentInfo:self.paymentInfo error:&error]) {
        [self showMessage:error.localizedDescription title:@"Payment info Validation"];
        return;
    }
    [self showChannelList];
}

- (IBAction)makeOneClickPaymentTapped:(id)sender {
    [self updatePaymentInfoFromForm];
    [[DotPay sharedInstance] oneClickPaymentWithPaymentInfo:self.paymentInfo paymentCard:nil withCompletion:^(DPPaymentSummary * _Nonnull summary, NSError * _Nonnull error) {
        NSString *message;
        if (summary) {
            message = @"Payment sent successfully";
        } else {
            message = @"Error received from server";
        }
        UIAlertController *alert = [UIAlertController alertControllerWithTitle:nil message:message preferredStyle:UIAlertControllerStyleAlert];
        UIAlertAction *cancel = [UIAlertAction actionWithTitle:@"Ok" style:UIAlertActionStyleDefault handler:nil];
        [alert addAction:cancel];
        dispatch_async(dispatch_get_main_queue(), ^{
            [self presentViewController:alert animated:YES completion:nil];
        });
    }];
}

- (IBAction)type4Tapped:(id)sender {
    [self.currentResponder resignFirstResponder];
    [self updatePaymentInfoFromForm];
    NSError *error = nil;
    if (![self.paymentInfoValidator validatePaymentInfo:self.paymentInfo error:&error]) {
        [self showMessage:error.localizedDescription title:@"Payment info Validation"];
        return;
    }
    [self showInsertPaymentIdAlert];
}

- (void)showInsertPaymentIdAlert {
    UIAlertController *alert = [UIAlertController alertControllerWithTitle:@"Podaj kanał" message:@"Podaj ID wybranego kanału płatności" preferredStyle:UIAlertControllerStyleAlert];
    [alert addTextFieldWithConfigurationHandler:^(UITextField * _Nonnull textField) {
        textField.placeholder = @"ID kanału";
    }];
    UIAlertAction *okAction = [UIAlertAction actionWithTitle:@"Ok" style:UIAlertActionStyleDefault handler:^(UIAlertAction * _Nonnull action) {
        [self onPaymentIdInserted:alert.textFields.firstObject.text];
    }];
    UIAlertAction *cancelAction = [UIAlertAction actionWithTitle:@"Anuluj" style:UIAlertActionStyleCancel handler:NULL];
    
    [alert addAction:okAction];
    [alert addAction:cancelAction];
    [self presentViewController:alert animated:YES completion:nil];
}

- (void)onPaymentIdInserted:(NSString *)idString {
    NSInteger paymentId = [idString integerValue];
    if (idString.length == 0) {
        [self showInsertPaymentIdAlert];
        return;
    }
    
    [[DotPay sharedInstance] fastPaymentWithPaymentInfo:self.paymentInfo paymentChannelId:@(paymentId) showingDefaultSummary:YES withCompletion:^(DPPaymentSummary * _Nonnull summary, NSError * _Nonnull error) {
        NSString *message;
        if (summary) {
            message = @"Payment sent successfully";
        } else {
            message = @"Error received from server";
        }
        UIAlertController *alert = [UIAlertController alertControllerWithTitle:nil message:message preferredStyle:UIAlertControllerStyleAlert];
        UIAlertAction *cancel = [UIAlertAction actionWithTitle:@"Ok" style:UIAlertActionStyleDefault handler:nil];
        [alert addAction:cancel];
        dispatch_async(dispatch_get_main_queue(), ^{
            [self presentViewController:alert animated:YES completion:nil];
        });
    }];
}

- (IBAction)debugModeSwitchValueChanged:(UISwitch*)sender {
    [DotPay sharedInstance].debugMode = sender.isOn;
}

- (IBAction)internalCardsSwitchValueChanged:(UISwitch *)sender {
    [DPOneClickManager sharedInstance].useInternalCards = sender.isOn;
}
    
- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(nullable id)sender {
    if(![segue.identifier isEqualToString:@"AdditionalInfoSegue"]){
        return;
    }
    AdditionalInfoTableViewController * additionalInfoTableViewController = (AdditionalInfoTableViewController*)segue.destinationViewController;
    additionalInfoTableViewController.additionalInfos = self.additionalInfos;
}

#pragma mark - DPMasterpassPaymentDelegate

- (void)masterpassPaymentShouldCreateAuthorizationOn:(UIViewController<DPMasterpassAuthorization> *)viewController {
    UIAlertController *alert = [UIAlertController alertControllerWithTitle:@"Autoryzacja" message:@"Proszę utworzyć kod pin dla użytkownika" preferredStyle:UIAlertControllerStyleAlert];
    UIAlertAction *okAction = [UIAlertAction actionWithTitle:@"Ok" style:UIAlertActionStyleDefault handler:^(UIAlertAction * _Nonnull action) {
        [viewController didCreateAuthorization:YES andError:nil];
    }];
    UIAlertAction *cancelAction = [UIAlertAction actionWithTitle:@"Anuluj" style:UIAlertActionStyleCancel handler:^(UIAlertAction * _Nonnull action) {
        [viewController didCreateAuthorization:NO andError:nil];
    }];
    
    [alert addAction:okAction];
    [alert addAction:cancelAction];
    [viewController presentViewController:alert animated:YES completion:nil];
}

- (void)masterpassPaymentShouldAuthorizeUserPaymentOn:(UIViewController<DPMasterpassAuthorization> *)viewController {
    UIAlertController *alert = [UIAlertController alertControllerWithTitle:@"Autoryzacja" message:@"Kliknij Ok aby autoryzować użytkownika" preferredStyle:UIAlertControllerStyleAlert];
    UIAlertAction *okAction = [UIAlertAction actionWithTitle:@"Ok" style:UIAlertActionStyleDefault handler:^(UIAlertAction * _Nonnull action) {
        [viewController didAuthorizeUser:YES andError:nil];
    }];
    
    UIAlertAction *cancelAction = [UIAlertAction actionWithTitle:@"Anuluj" style:UIAlertActionStyleCancel handler:^(UIAlertAction * _Nonnull action) {
        [viewController didAuthorizeUser:NO andError:nil];
    }];
    [alert addAction:okAction];
    [alert addAction:cancelAction];
    [viewController presentViewController:alert animated:YES completion:nil];
}

#pragma mark - DPOneClickManagerDelegate
- (void)oneClickManager:(DPOneClickManager *)manager didChangeDefaultOneClickPaymentCard:(DPOneClickPaymentCard *)newDefaultCard {
    UIAlertController *alert = [UIAlertController alertControllerWithTitle:@"Domyslna karta" message:[NSString stringWithFormat:@"Zmieniono domyślną kartę na kartę: %@", newDefaultCard.maskedNumber] preferredStyle:UIAlertControllerStyleAlert];
    UIAlertAction *okAction = [UIAlertAction actionWithTitle:@"Ok" style:UIAlertActionStyleCancel handler:NULL];
    [alert addAction:okAction];
    dispatch_async(dispatch_get_main_queue(), ^{
        [alert showOnTop];
    });
}

- (void)oneClickManager:(DPOneClickManager *)manager didRegisterNewCreditCard:(DPOneClickCardRegistrationData *)cardRegistrationData {
    UIAlertController *alert = [UIAlertController alertControllerWithTitle:@"Zarejestrowano kartę" message:[NSString stringWithFormat:@"Zarejestrowano kartę (%@) dla customer_id: %@", cardRegistrationData.maskedNumber, cardRegistrationData.customerId] preferredStyle:UIAlertControllerStyleAlert];
    UIAlertAction *okAction = [UIAlertAction actionWithTitle:@"Ok" style:UIAlertActionStyleCancel handler:NULL];
    [alert addAction:okAction];
    dispatch_async(dispatch_get_main_queue(), ^{
        [alert showOnTop];
    });
}

- (NSInteger)numberOfComponentsInPickerView:(UIPickerView *)pickerView {
    return 1;
}

- (NSInteger)pickerView:(nonnull UIPickerView *)pickerView numberOfRowsInComponent:(NSInteger)component {
    return self.langPickerData.count;
}

- (NSString *)pickerView:(UIPickerView *)pickerView titleForRow:(NSInteger)row forComponent:(NSInteger)component{
    return self.langPickerData[row];
}

- (void)pickerView:(UIPickerView *)pickerView didSelectRow:(NSInteger)row inComponent:(NSInteger)component{
    self.langTextField.text = self.langPickerData[row];
}

@end
