//
//  TestModalCardRegistrationViewController.m
//  DotPayTestApp
//
//  Created by dzajac on 10/10/16.
//  Copyright © 2016 CTM Mobiltek. All rights reserved.
//

#import "TestModalCardRegistrationViewController.h"
#import <DotPaySDK/DotPaySDK.h>
@interface TestModalCardRegistrationViewController ()

@end

@implementation TestModalCardRegistrationViewController

- (IBAction)didTapRegisterCard:(UIButton *)sender {
    DPOneClickPaymentCardInfo *info = [[DPOneClickPaymentCardInfo alloc] init];
    info.firstName = @"testFirstName";
    info.lastName = @"testLastName";
    info.email = @"test@email.com";
    info.merchantId = @"10000";
    info.creditCardNumber = @"4444111144441234";
    info.expirationYear = @"2018";
    info.expirationMonth = @"12";
    info.cvv = @"111";
    info.currency = @"PLN";

    [[DPOneClickManager sharedInstance] registerPaymentCardWithCardInfo:info withCompletion:^(DPOneClickPaymentCard *response, NSError *error) {
        NSLog(@"Response %@", response);
    }];
}

- (IBAction)didTapCloseButton:(id)sender {
    [self.presentingViewController dismissViewControllerAnimated:YES completion:nil];
}

@end
