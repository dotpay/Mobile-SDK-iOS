//
//  DPCurrency.h
//  DotPaySDK
//
//  Created by Mariusz Śpiewak on 10.03.2015.
//  Copyright (c) 2015 Dotpay. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface DPCurrency : NSObject <NSCopying, NSCoding>

+ (instancetype)PLN;

@property (nonatomic, copy, readonly) NSString *currencyCode;

+ (instancetype)currencyWithCode:(NSString *)currencyCode;

- (instancetype)initWithCode:(NSString *)currencyCode NS_DESIGNATED_INITIALIZER;

- (instancetype)init __attribute__((unavailable("use initWithCode")));

- (BOOL)isEqualToCurrency:(DPCurrency *)currency;



@end

NS_ASSUME_NONNULL_END
