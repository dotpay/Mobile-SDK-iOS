//
//  DPPaymentDetails.h
//  DotPaySDK
//
//  Created by Mateusz Maćkowiak on 28/04/15.
//  Copyright (c) 2015 Dotpay. All rights reserved.
//

#import <Foundation/Foundation.h>

@class DPCurrency;

NS_ASSUME_NONNULL_BEGIN

@interface DPPaymentDetails : NSObject <NSCopying, NSCoding>

@property (nonatomic, strong, readonly) NSString *receiver;
@property (nonatomic, strong, readonly) NSString *receiverEmail;
@property (nonatomic, assign, readonly) BOOL isExchanged;
@property (nonatomic, strong, readonly) NSDecimalNumber *amount;
@property (nonatomic, strong, readonly) DPCurrency *currency;
@property (nonatomic, strong, readonly) NSString *money;

@property (nonatomic, strong, readonly) NSString *merchantID;
@property (nonatomic, strong, readonly) NSString *language;
@property (nonatomic, strong, readonly) NSString *textDescription;

@property (nonatomic, strong, readonly, nullable) NSString *exchange;
@property (nonatomic, strong, readonly, nullable) NSNumber *exchangeRate;
@property (nonatomic, strong, readonly, nullable) NSString *exchangeReverse;
@property (nonatomic, strong, readonly, nullable) NSDecimalNumber *originalAmount;
@property (nonatomic, strong, readonly, nullable) DPCurrency *originalCurrency;
@property (nonatomic, strong, readonly, nullable) NSString *originalMoney;
@property (nonatomic, strong, readonly, nullable) NSDictionary *senderInformation;
@property (nonatomic, strong, readonly, nullable) NSString *urlc;
@property (nonatomic, strong, readonly, nullable) NSString *control;
@property (nonatomic, strong, readonly, nullable) NSDictionary* additionalInformation;

@end

NS_ASSUME_NONNULL_END