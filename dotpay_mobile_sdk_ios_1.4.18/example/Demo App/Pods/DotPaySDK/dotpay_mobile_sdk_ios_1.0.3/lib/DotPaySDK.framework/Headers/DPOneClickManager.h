//
// Created by Mateusz Maćkowiak on 22/07/15.
// Copyright (c) 2015 Dotpay. All rights reserved.
//

#import <Foundation/Foundation.h>

extern NSString * const kOneClickUniqueIdentifierServiceKey;

@interface DPOneClickManager : NSObject

+ (instancetype)sharedInstance;

- (instancetype)init __attribute__((unavailable("DPOneClickManager is a Singelton use sharedInstance")));

@property (nonatomic, getter=isEnabled) BOOL enabled;

@property (nonatomic, getter=isCVVStoreEnabled) BOOL cvvStoreEnabled;

@property (nonatomic, readonly) BOOL isDataAvailable;

@property (nonatomic, readonly) BOOL isCVVDataAvailable;

-(void)clearCVVData;

-(void)clearData;

@end