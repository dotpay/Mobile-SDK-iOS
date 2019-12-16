//
//  DPPaymentChannelGroupHelper.h
//  DotPaySDK
//
//  Created by Mateusz Maćkowiak on 08/05/15.
//  Copyright (c) 2015 Dotpay. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface DPPaymentChannelGroupHelper : NSObject

/*!
 *  Groups list of payment channels in to groups
 *
 *  @param paymentChannels List of DPPaymentChannel objects
 *
 *  @return Array of DPPaymentChannelGroup objects based on DPPaymentChannel group
 */
- (NSArray *)groupPaymentChannels:(NSArray *)paymentChannels;

@end

NS_ASSUME_NONNULL_END