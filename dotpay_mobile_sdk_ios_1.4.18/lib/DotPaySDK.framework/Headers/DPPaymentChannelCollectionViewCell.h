//
//  DPPaymentChannelCollectionViewCell.h
//  DotPaySDK
//
//  Created by Mateusz Maćkowiak on 07/05/15.
//  Copyright (c) 2015 Dotpay. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface DPPaymentChannelCollectionViewCell : UICollectionViewCell

@property (nonatomic, strong) UIImageView *imageView;
@property (nonatomic, strong) UILabel *titleLabel;
@property (nonatomic, strong) UIView *dimView;

@property (nonatomic, assign, getter=isDisabled) BOOL disabled;
@property (nonatomic, assign, getter=isOffline) BOOL offline;
@end

NS_ASSUME_NONNULL_END