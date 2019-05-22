//
//  DPPaymentChannelListViewController.h
//  DotPaySDK
//
//  Created by Mateusz Maćkowiak on 07/05/15.
//  Copyright (c) 2015 Dotpay. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "DPPaymentChannelSelectionViewControllerDelegate.h"

@class DPPaymentChannelGroup;

NS_ASSUME_NONNULL_BEGIN

extern NSString * const kDPPaymentChannelCollectionViewCellReuseIdentifier;
extern NSString * const kDPPaymentChannelCollectionViewHeaderReuseIdentifier;

@interface DPPaymentChannelsCollectionViewController : UICollectionViewController

@property (nonatomic, weak) id<DPPaymentChannelSelectionViewControllerDelegate> delegate;

@property (nonatomic, assign, getter=isGrouped) BOOL grouped;

@property (nonatomic, strong, readonly) NSArray* paymentChannelList;

- (instancetype)initWithPaymentChannelList:(NSArray *)paymentChannelList;

- (instancetype)initWithCollectionViewLayout:(UICollectionViewLayout *)layout paymentChannelList:(NSArray *)paymentChannelList NS_DESIGNATED_INITIALIZER;

@end


@interface DPPaymentChannelsCollectionViewController (UISubclassingHooks)

-(NSArray*)groupPaymentChannels:(NSArray*)paymentChannels;

-(nullable DPPaymentChannelGroup*)groupForSection:(NSUInteger)section;

-(nullable DPPaymentChannel*)channelForIndexPath:(NSIndexPath*)indexPath;

-(void)registerClasses;

@end

NS_ASSUME_NONNULL_END