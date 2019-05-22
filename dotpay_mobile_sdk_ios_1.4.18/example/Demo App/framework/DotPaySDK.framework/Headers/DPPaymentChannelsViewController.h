//
//  DPPaymentChannelsViewController.h
//  DotPaySDK
//
//  Created by Mateusz Maćkowiak on 07/05/15.
//  Copyright (c) 2015 Dotpay. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "DPPaymentChannelSelectionViewControllerDelegate.h"
#import "DPPaymentChannelSelectionViewController.h"

@class DPPaymentDetails;

NS_ASSUME_NONNULL_BEGIN

@interface DPPaymentChannelsViewController : UIViewController <DPPaymentChannelSelectionViewController>

@property (nonatomic, strong) UIViewController *infoViewController;
@property (nonatomic, strong) UIViewController *channelListViewController;

@property (nonatomic, weak) id <DPPaymentChannelSelectionViewControllerDelegate> delegate;

@property (nonatomic, strong, readonly) NSArray *paymentChannelList;
@property (nonatomic, strong, readonly) DPPaymentDetails *paymentDetails;
@property (nonatomic, assign) BOOL clearCardMask;

- (instancetype)initWithPaymentChannelList:(NSArray *)paymentChannelList paymentDetails:(DPPaymentDetails *)paymentDetails;

- (instancetype)initWithPaymentChannelList:(NSArray *)paymentChannelList paymentDetails:(DPPaymentDetails *)paymentDetails andPaymentChannelSelected:(DPPaymentChannel*)channel forViewController:(UIViewController *)viewController;

- (void)paymentChannelSelectionViewController:(UIViewController *)viewController didSelectPaymentChannel:(DPPaymentChannel *)paymentChannel;

@end


@interface DPPaymentChannelsViewController (UISubclassingHooks)

- (void)createSubViews;

- (UIViewController *)createInfoViewControllerForPaymentDetails:(DPPaymentDetails *)paymentDetails;

- (UIViewController *)createChannelListViewControllerForChannelList:(NSArray *)paymentChannels;

@end

NS_ASSUME_NONNULL_END
