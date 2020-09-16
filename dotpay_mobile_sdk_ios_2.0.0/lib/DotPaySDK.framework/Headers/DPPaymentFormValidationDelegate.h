//
//  DPPaymentFormValidationDelegate.h
//  DotPaySDK
//
//  Created by Mateusz Maćkowiak on 08/05/15.
//  Copyright (c) 2015 Dotpay. All rights reserved.
//

#import <Foundation/Foundation.h>

@class DPPayment;
@class DPPaymentChannel;
@class DPOneClickPaymentCard;

NS_ASSUME_NONNULL_BEGIN

@protocol DPPaymentFormValidationDelegate <NSObject>

@optional

- (void)paymentFormViewController:(UIViewController *)viewController didValidatePayment:(DPPayment*)payment;

- (void)paymentFormViewController:(UIViewController *)viewController didFailToValidatePayment:(DPPayment*)payment;

- (void)paymentFormViewController:(UIViewController *)viewController paymentCardNotRegistered:(DPOneClickPaymentCard *)paymentCard;

- (void)authorizePaymentClickOnPaymentFormViewController:(UIViewController *)viewController;
- (void)didFailToAuthorizePaymentClick;

- (void)paymentFormViewController:(UIViewController *)viewController didSucceedVisaCheckoutForPayment:(DPPayment*)payment visaCallId:(NSString *)callId;
- (void)paymentFormViewController:(UIViewController *)viewController didFailVisaCheckoutForPayment:(DPPayment*)payment;

- (void)paymentFormViewController:(UIViewController *)viewController didSucceedMasterpassPaymentForPayment:(DPPayment*)payment token:(NSString *)token;

- (void)shouldRefreshView;
@end

NS_ASSUME_NONNULL_END
