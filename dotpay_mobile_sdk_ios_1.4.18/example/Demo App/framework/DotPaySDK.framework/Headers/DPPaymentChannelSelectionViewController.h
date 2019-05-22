//
// Created by Mateusz Maćkowiak on 20/07/15.
// Copyright (c) 2015 Dotpay. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol DPPaymentChannelSelectionViewControllerDelegate;

@protocol DPPaymentChannelSelectionViewController <NSObject>

@property (nonatomic, weak) id<DPPaymentChannelSelectionViewControllerDelegate> delegate;

@end

NS_ASSUME_NONNULL_END