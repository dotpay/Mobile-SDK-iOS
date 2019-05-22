//
// Created by Mateusz Maćkowiak on 14/05/15.
// Copyright (c) 2015 Dotpay. All rights reserved.
//

#import <UIKit/UIKit.h>

@class DPPaymentHistory;
@class DPPaymentSummary;

NS_ASSUME_NONNULL_BEGIN

@protocol DPPaymentHistoryTableViewControllerDelegate

- (void)didSelectPaymentSummary:(DPPaymentSummary *)paymentSummary;

@end

@interface DPPaymentHistoryTableViewController : UITableViewController

@property (nonatomic, weak) id <DPPaymentHistoryTableViewControllerDelegate> delegate;

@property (nonatomic, strong) UIBarButtonItem *deleteBarButtonItem;
@property (nonatomic, assign, getter=isRefreshable) BOOL refreshable;

/**
* By default uses [DPPaymentHistory sharedInstance]
*/
@property (nonatomic, strong, readonly) DPPaymentHistory *paymentHistory;

- (instancetype)initWithPaymentHistory:(DPPaymentHistory *)paymentHistory;

- (instancetype)initWithStyle:(UITableViewStyle)style paymentHistory:(DPPaymentHistory *)paymentHistory;

@end


@interface DPPaymentHistoryTableViewController (UISubclassingHooks)

- (nullable DPPaymentSummary *)summaryForIndexPath:(NSIndexPath *)indexPath;

- (void)registerClasses;

- (void)removeSelectedElements;

- (nullable NSIndexPath *)indexPathForPaymentSummary:(DPPaymentSummary *)summary;

@end

NS_ASSUME_NONNULL_END