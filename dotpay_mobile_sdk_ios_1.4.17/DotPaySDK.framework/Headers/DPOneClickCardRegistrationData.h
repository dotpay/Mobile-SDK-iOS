//
//  DPCardRegistrationData.h
//  DotPaySDK
//
//  Created by Mateusz Mularski on 23.08.2018.
//  Copyright © 2018 CTM Mobiltek. All rights reserved.
//

#import <Foundation/Foundation.h>

@class DPOneClickPaymentCard;
@class DPOneClickPaymentCardBrand;

@interface DPOneClickCardRegistrationData : NSObject

@property (nonatomic, strong, readonly) NSString *transactionNumber;
@property (nonatomic, strong, readonly) NSString *unregisterUrl;
@property (nonatomic, strong, readonly) NSString *maskedNumber;
@property (nonatomic, strong, readonly) NSString *cardId;
@property (nonatomic, strong, readonly) NSString *cvv;
@property (nonatomic, strong, readonly) DPOneClickPaymentCardBrand *brand;
@property (nonatomic, strong, readonly) NSNumber *paymentChannelId;
@property (nonatomic, strong, readonly) NSString *customerId;

- (instancetype)initWithPaymentCard:(DPOneClickPaymentCard *)paymentCard transactionNumber:(NSString *)transactionNumber;

@end
