//
//  DPPaymentInstruction.h
//  DotPaySDK
//
//  Created by Rafał Prążyński on 22/07/15.
//  Copyright (c) 2015 Dotpay. All rights reserved.
//

#import <Foundation/Foundation.h>

@class DPPaymentDetails;
@class DPPaymentInstructionOperation;

NS_ASSUME_NONNULL_BEGIN

@interface DPPaymentInstruction : NSObject

@property (nonatomic, strong, readonly) NSArray *instructionResources;
@property (nonatomic, strong, readonly) NSArray *instruction;
@property (nonatomic, strong, readonly) NSString *apiInstructionUrl;

@property (nonatomic, strong, readonly) DPPaymentInstructionOperation *operation;
@property (nonatomic, strong, readonly) DPPaymentDetails *paymentDetails;

@end

NS_ASSUME_NONNULL_END