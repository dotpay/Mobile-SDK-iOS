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
@protocol DPFavoritePaymentMethod;

NS_ASSUME_NONNULL_BEGIN

extern NSString * const kDPPaymentChannelCollectionViewCellReuseIdentifier;
extern NSString * const kDPPaymentChannelCollectionViewHeaderReuseIdentifier;
extern NSString * const kDPFavoritesManagerFavoritesDidUpdateNotification;

@interface DPPaymentChannelsCollectionViewController : UICollectionViewController

@property (nonatomic, weak) id<DPPaymentChannelSelectionViewControllerDelegate> delegate;

@property (nonatomic, assign, getter=isGrouped) BOOL grouped;
@property (nonatomic, assign) BOOL clearCardMask;
@property (nonatomic, strong, readonly) NSArray *channelList;
@property (nonatomic, strong, readonly) NSArray<id<DPFavoritePaymentMethod>> *favoritePaymentMethods;

- (instancetype)initWithPaymentChannelList:(NSArray *)paymentChannelList;

- (instancetype)initWithCollectionViewLayout:(UICollectionViewLayout *)layout paymentChannelList:(NSArray *)paymentChannelList;

@end


@interface DPPaymentChannelsCollectionViewController (UISubclassingHooks)

-(NSArray*)groupPaymentChannels:(NSArray*)paymentChannels;

-(nullable DPPaymentChannelGroup*)groupForSection:(NSUInteger)section;

-(nullable DPPaymentChannel*)channelForIndexPath:(NSIndexPath*)indexPath;

-(void)registerClasses;

- (void)scrollToTop;

@end

NS_ASSUME_NONNULL_END
