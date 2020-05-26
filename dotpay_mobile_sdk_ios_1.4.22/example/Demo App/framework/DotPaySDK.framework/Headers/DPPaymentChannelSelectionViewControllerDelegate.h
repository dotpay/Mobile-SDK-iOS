//
//  DPPaymentChannelListSelectionDelegate.h
//  DotPaySDK
//
//  Created by Mateusz Maćkowiak on 07/05/15.
//  Copyright (c) 2015 Dotpay. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class DPPaymentChannel;

@protocol DPPaymentChannelSelectionViewControllerDelegate <NSObject>

-(void)paymentChannelSelectionViewController:(UIViewController *)viewController didSelectPaymentChannel:(DPPaymentChannel*)paymentChannel;

@optional

-(BOOL)paymentChannelSelectionViewController:(UIViewController *)viewController shouldSelectPaymentChannel:(DPPaymentChannel*)paymentChannel;
-(void)paymentChannelSelectionViewController:(UIViewController *)viewController didHideCardDataForChannel:(DPPaymentChannel *)paymentChannel;


@end

NS_ASSUME_NONNULL_END
