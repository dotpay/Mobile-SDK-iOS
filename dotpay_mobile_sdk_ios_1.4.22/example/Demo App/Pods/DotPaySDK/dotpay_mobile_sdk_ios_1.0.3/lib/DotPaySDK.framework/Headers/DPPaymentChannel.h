//
//  DPPaymentChannel.h
//  DotPaySDK
//
//  Created by Mariusz Śpiewak on 10.03.2015.
//  Copyright (c) 2015 Dotpay. All rights reserved.
//

#import <Foundation/Foundation.h>

@class DPCurrency;

NS_ASSUME_NONNULL_BEGIN

@interface DPPaymentChannel : NSObject <NSCoding>

@property (nonatomic, assign, readonly) NSInteger channelIdentifier;
@property (nonatomic, strong, readonly) NSString *group;
@property (nonatomic, strong, readonly) NSString *groupName;
@property (nonatomic, assign, readonly) BOOL isDisabled;
@property (nonatomic, assign, readonly) BOOL isNotOnline;
@property (nonatomic, strong, readonly) NSString *logoUrl;
@property (nonatomic, strong, readonly) NSString *channelName;
@property (nonatomic, strong, readonly) NSString *channelShortName;
@property (nonatomic, assign, readonly) BOOL isWarrantyAvailable;
@property (nonatomic, strong, readonly, nullable) NSDecimalNumber *warrantyAmount;
@property (nonatomic, strong, readonly, nullable) DPCurrency *warrantyCurrency;
@property (nonatomic, strong, readonly, nullable) NSString *warrantyMoneyLiteral;
@property (nonatomic, strong, readonly, nullable) NSString *not_online_message;
@property (nonatomic, strong, readonly, nullable) NSString *disable_message;

@end

NS_ASSUME_NONNULL_END