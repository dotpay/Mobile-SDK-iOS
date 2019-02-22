//
// Created by Mateusz Maćkowiak on 29/07/15.
// Copyright (c) 2015 Dotpay. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface DPOneClickPaymentCardBrand : NSObject <NSCoding, NSCopying>

@property (nonatomic, strong, readonly) NSString * name;
@property (nonatomic, strong, readonly) NSString * codeName;
@property (nonatomic, strong, readonly) NSString * logo;

@end