//
//  DPPaymentInfoValidator.h
//  DotPaySDK
//
//  Created by Mateusz Maćkowiak on 07/05/15.
//  Copyright (c) 2015 Dotpay. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class DPPaymentInfo;

extern NSString * const kDPPaymentInfoValidationErrorDomainKey;

extern NSInteger const kDPPaymentInfoMissingPaymentInfoErrorCode;
extern NSInteger const kDPPaymentInfoMissingMerchantErrorCode;
extern NSInteger const kDPPaymentInfoInvalidCurrencyErrorCode;
extern NSInteger const kDPPaymentInfoInvalidAmountErrorCode;
extern NSInteger const kDPPaymentInfoInvalidSenderInformationErrorCode;
extern NSInteger const kDPPaymentInfoInvalidAdditionalInformationErrorCode;


@interface DPPaymentInfoValidator : NSObject

- (BOOL)validatePaymentInfo:(DPPaymentInfo *)paymentInfo;

- (BOOL)validatePaymentInfo:(DPPaymentInfo *)paymentInfo error:(NSError**)error;

@end

NS_ASSUME_NONNULL_END