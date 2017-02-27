//
//  DPOneClickManagerViewController.h
//  DotPaySDK
//
//  Created by dzajac on 16/08/16.
//  Copyright å© 2016 CTM Mobiltek. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface DPOneClickPaymentCardManagerViewController : UINavigationController

@property (nonatomic, strong) UIBarButtonItem *addButton;
@property (nonatomic, strong) NSString *merchantId;
@property (nonatomic, strong) NSString *currency;

- (instancetype)initWithMerchantId:(NSString *)merchantId currency:(NSString *)currency NS_DESIGNATED_INITIALIZER;

@end
