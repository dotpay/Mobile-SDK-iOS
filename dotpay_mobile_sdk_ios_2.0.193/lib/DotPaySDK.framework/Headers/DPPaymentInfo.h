//
//  DPPaymentInfo.h
//  DotPaySDK
//
//  Created by Mariusz Śpiewak on 16.03.2015.
//  Copyright (c) 2015 Dotpay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <DotPaySDK/DPCurrency.h>

NS_ASSUME_NONNULL_BEGIN

@interface DPPaymentInfo : NSObject <NSCopying, NSCoding>

- (instancetype)initWithMerchantId:(NSString *)merchantID amount:(NSDecimalNumber *)amount senderInformation:(NSDictionary *)senderInformation currency:(DPCurrency *)currency textDescription:(NSString *)description;

@property (nonatomic, strong) NSString *merchantID;
@property (nonatomic, strong) NSDecimalNumber *amount;
@property (nonatomic, strong) NSDictionary *senderInformation;
@property (nonatomic, strong) DPCurrency *currency;
@property (nonatomic, strong) NSString *urlc;
@property (nonatomic, strong) NSString *control;
@property (nonatomic, strong, readonly) NSString *language;
@property (nonatomic, strong) NSString *textDescription;
@property (nonatomic, strong) NSDictionary* additionalInformation;

@end

NS_ASSUME_NONNULL_END
