//
//  DPPaymentFormInfoViewController.h
//  DotPaySDK
//
//  Created by Mateusz Maćkowiak on 29/04/15.
//  Copyright (c) 2015 Dotpay. All rights reserved.
//

#import <UIKit/UIKit.h>

@class DPPaymentChannel;
@class DPPaymentDetails;

NS_ASSUME_NONNULL_BEGIN

@protocol DPChangePaymentChannelDelegate <NSObject>

- (void)changePaymentChannel;

@end

@interface DPPaymentChanelInfoViewController : UITableViewController

@property (nonatomic, strong) UIViewController *paymentDetailsViewController;

@property (nonatomic, strong) DPPaymentChannel *paymentChannel;
@property (nonatomic, strong, readonly) DPPaymentDetails *paymentDetails;
@property (nonnull, strong) id<DPChangePaymentChannelDelegate> delegate;

- (instancetype)initWithPaymentChannel:(DPPaymentChannel *)paymentChannel paymentDetails:(DPPaymentDetails *)paymentDetails NS_DESIGNATED_INITIALIZER;

@end


@interface DPPaymentChanelInfoViewController (UISubclassingHooks)

- (UIViewController *)createPaymentDetailsViewControllerForPaymentDetails:(DPPaymentDetails *)paymentDetails;

@end

NS_ASSUME_NONNULL_END