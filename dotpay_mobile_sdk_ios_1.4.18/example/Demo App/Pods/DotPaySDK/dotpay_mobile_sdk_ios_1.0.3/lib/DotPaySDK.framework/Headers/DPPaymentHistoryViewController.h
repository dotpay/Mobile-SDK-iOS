//
// Created by Mateusz Maćkowiak on 14/05/15.
// Copyright (c) 2015 Dotpay. All rights reserved.
//

#import <UIKit/UIKit.h>

@class DPPaymentHistory;
@class DPPaymentSummary;

NS_ASSUME_NONNULL_BEGIN

@interface DPPaymentHistoryViewController : UINavigationController

/**
* By default uses [DPPaymentHistory sharedInstance]
*/
@property (nonatomic, strong, readonly) DPPaymentHistory *paymentHistory;

- (instancetype)initWithPaymentHistory:(DPPaymentHistory *)paymentHistory;

/*!
 *  Default YES
 */
@property (nonatomic, assign) BOOL addCloseButton;

@property (nonatomic, strong) UIBarButtonItem *closeButton;

@property (nonatomic, assign, getter=isRefreshable) BOOL refreshable;

@end

@interface DPPaymentHistoryViewController (Overridable)

- (void)closeButtonItemWasTapped:(UIBarButtonItem *)closeButtonItem;

- (void)didSelectPaymentSummary:(DPPaymentSummary *)paymentSummary;

@end

NS_ASSUME_NONNULL_END