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

@interface DPPaymentChanelInfoViewController : UITableViewController

@property (nonatomic, strong) UIViewController *paymentDetailsViewController;

@property (nonatomic, strong, readonly) DPPaymentDetails *paymentDetails;

- (instancetype)initWithPaymentDetails:(DPPaymentDetails *)paymentDetails;

@end


@interface DPPaymentChanelInfoViewController (UISubclassingHooks)

- (UIViewController *)createPaymentDetailsViewControllerForPaymentDetails:(DPPaymentDetails *)paymentDetails;

@end

NS_ASSUME_NONNULL_END
