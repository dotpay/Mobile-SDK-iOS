//
//  DPDotPayViewController.h
//  DotPaySDK
//
//  Created by Mateusz Maćkowiak on 07/05/15.
//  Copyright (c) 2015 Dotpay. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "DPPaymentChannelSelectionViewController.h"

@class DPPaymentDetails;
@class DPPaymentChannel;
@class DPDotPayViewController;
@class DPPaymentSummary;

NS_ASSUME_NONNULL_BEGIN

@protocol DPDotPayViewControllerDelegate <NSObject>

- (void)dotpayViewController:(DPDotPayViewController *)dotpayViewController didFinishPaymentWithSummary:(DPPaymentSummary *)paymentSummary;

- (void)dotpayViewController:(DPDotPayViewController *)dotpayViewController didFailToFinishPaymentWithError:(NSError *)error;

@optional

- (BOOL)dotpayViewController:(DPDotPayViewController *)dotpayViewController shouldDismissViewControllerForPaymentSummary:(DPPaymentSummary *)paymentSummary;

- (BOOL)dotpayViewController:(DPDotPayViewController *)dotpayViewController shouldDismissViewControllerForError:(NSError *)error;

- (BOOL)dotpayViewController:(DPDotPayViewController *)dotpayViewController shouldShowViewControllerForPaymentSummary:(DPPaymentSummary *)paymentSummary;

- (void)dotpayViewController:(DPDotPayViewController *)dotpayViewController didSelectPaymentChannel:(DPPaymentChannel *)paymentChannel;

- (BOOL)dotpayViewController:(DPDotPayViewController *)dotpayViewController shouldSelectPaymentChannel:(DPPaymentChannel *)paymentChannel;

@end


@interface DPDotPayViewController : UINavigationController

@property (nonatomic, weak) id <DPDotPayViewControllerDelegate> paymentControllerDelegate;

/*!
 *  Default YES
 */
@property (nonatomic, assign) BOOL addCloseButton;

@property (nonatomic, strong) UIBarButtonItem *closeButton;

/*!
 *  Default YES if initWithPaymentChannelList:paymentDetails: or initWithPaymentChannelList:paymentDetails:
 */
@property (nonatomic, assign) BOOL useLastChannelSelection;

@property (nonatomic, strong, readonly) NSArray *paymentChannelList;

@property (nonatomic, strong, readonly) DPPaymentDetails *paymentDetails;

- (instancetype)initWithPaymentChannelList:(NSArray *)paymentChannelList paymentDetails:(DPPaymentDetails *)paymentDetails;

- (instancetype)initWithPaymentChannelSelectionController:(id<DPPaymentChannelSelectionViewController>)controller paymentDetails:(DPPaymentDetails *)paymentDetails;

- (instancetype)initWithPaymentChannel:(DPPaymentChannel *)paymentChannel paymentDetails:(DPPaymentDetails *)paymentDetails;

@end


@interface DPDotPayViewController (UISubclassingHooks)

- (nullable DPPaymentChannel *)lastSelectedChannel;

- (nullable NSNumber *)lastSelectedChannelIdentifier;

@end

NS_ASSUME_NONNULL_END