//
//  DPPaymentFormValidationDelegate.h
//  DotPaySDK
//
//  Created by Mateusz Maćkowiak on 08/05/15.
//  Copyright (c) 2015 Dotpay. All rights reserved.
//

#import <Foundation/Foundation.h>

@class DPPayment;

NS_ASSUME_NONNULL_BEGIN

@protocol DPPaymentFormValidationDelegate <NSObject>

@optional

- (void)paymentFormViewController:(UIViewController *)viewController didValidatePayment:(DPPayment*)payment;

- (void)paymentFormViewController:(UIViewController *)viewController didFailToValidatePayment:(DPPayment*)payment;

@end

NS_ASSUME_NONNULL_END