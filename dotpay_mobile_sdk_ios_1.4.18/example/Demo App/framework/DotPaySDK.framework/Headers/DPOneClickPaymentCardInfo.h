//
//  CreditCardRegistrationForm.h
//  DotPaySDK
//
//  Created by dzajac on 29/08/16.
//  Copyright © 2016 CTM Mobiltek. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class DPCurrency;

@interface DPOneClickPaymentCardInfo : NSObject

- (instancetype)initWithMerchantId:(NSString *)merchantId currency:(DPCurrency *)currency creditCardNumber:(NSString *)cardNumber cvv:(NSString *)cvv expirationMonth:(NSString *)expirationMonth expirationYear:(NSString *)expirationYear firstName:(NSString *)firstName lastName:(NSString *)lastName email:(NSString *)email;

@property (nonatomic, strong) NSString *creditCardNumber;
@property (nonatomic, strong) NSString *cvv;
@property (nonatomic, strong) NSString *firstName;
@property (nonatomic, strong) NSString *lastName;
@property (nonatomic, strong) NSString *email;
@property (nonatomic, strong) NSString *expirationMonth;
@property (nonatomic, strong) NSString *expirationYear;
@property (nonatomic, strong) NSString *merchantId;
@property (nonatomic, strong) NSString *currency;

- (NSDictionary *)getAsDictionary;

@end

NS_ASSUME_NONNULL_END
