//
//  ViewController.m
//  DotPaySDK-Demo
//
//  Created by Karol Magier on 07.08.2015.
//  Copyright (c) 2015 DotPay. All rights reserved.
//

#import "ViewController.h"
#import <DotPaySDK/DotPaySDK.h>

@interface ViewController () <DPDotPayViewControllerDelegate>
@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    [DotPay sharedInstance].debugMode = YES;
}

- (IBAction)payButtonPressed:(id)sender {
    
    DPPaymentInfo *paymentInfo = [[DPPaymentInfo alloc] init];
    paymentInfo.currency = [DPCurrency currencyWithCode:@"pln"];
    paymentInfo.amount = [[NSDecimalNumber alloc] initWithFloat:399.f];
    paymentInfo.merchantID = @"777777";
    paymentInfo.textDescription = @"Description of payment";
    paymentInfo.senderInformation = @{@"firstname" : @"Jan", @"lastname" : @"Kowalski", @"email" : @"jan.kowalski@test.pl"};
    
    [[DotPay sharedInstance] getChannelListForPaymentInfo:paymentInfo
                                           withCompletion:^(NSArray *channelList, DPPaymentDetails *paymentDetails, NSError *error) {
                                               dispatch_async(dispatch_get_main_queue(), ^{
                                                   DPDotPayViewController *dotPayViewController = [[DPDotPayViewController alloc] initWithPaymentChannelList:channelList
                                                                                                                                              paymentDetails:paymentDetails];
                                                   dotPayViewController.useLastChannelSelection = NO;
                                                   dotPayViewController.paymentControllerDelegate = self;
                                                   [self presentViewController:dotPayViewController animated:YES completion:NULL];
                                               });
                                           }];
}

- (IBAction)historyButtonPressed:(id)sender {
    
    DPPaymentHistoryViewController *historyController = [[DPPaymentHistoryViewController alloc] initWithPaymentHistory:nil];
    [self presentViewController:historyController animated:YES completion:NULL];
}

-(void) dotpayViewController: (DPDotPayViewController *)viewController didFinishPaymentWithSummary: (DPPaymentSummary *)paymentSummary {
    
    if([paymentSummary.type isEqualToString: kDPPaymentSummaryStatusCompleted]) {
        NSLog(@"Płatność zakończona pomyślnie.");
    } else if ([paymentSummary.type isEqualToString: kDPPaymentSummaryStatusRejected]) {
        NSLog(@"Płatność zakończona odmową.");
    } else {
        NSLog(@"Płatność w trakcie realizacji.");
    }
    
}

-(void)dotpayViewController: (DPDotPayViewController *)viewController didFailToFinishPaymentWithError: (NSError *)error {
    NSLog(@"Błąd procesu płatnoci.");
}

@end
