//
// Created by Mateusz Maćkowiak on 28/07/15.
// Copyright (c) 2015 Dotpay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "DPFavoritePaymentMethod.h"

@class DPOneClickPaymentCardBrand;

@interface DPOneClickPaymentCard : NSObject <NSCoding, NSCopying, DPFavoritePaymentMethod>

@property (nonatomic, strong, readonly) NSString *cvv;

@property (nonatomic, strong, readonly) DPOneClickPaymentCardBrand * brand;
@property (nonatomic, strong, readonly) NSString * maskedNumber;
@property (nonatomic, strong, readonly) NSString * cardId;

- (void)clearCvv;

@end
