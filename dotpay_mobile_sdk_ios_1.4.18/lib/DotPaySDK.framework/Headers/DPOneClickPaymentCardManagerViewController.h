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
@property (nonatomic, strong) NSString *firstName;
@property (nonatomic, strong) NSString *lastName;
@property (nonatomic, strong) NSString *email;

- (instancetype)initWithMerchantId:(NSString *)merchantId currency:(NSString *)currency NS_DESIGNATED_INITIALIZER;
- (instancetype)initWithMerchantId:(NSString *)merchantId currency:(NSString *)currency firstName:(NSString *)firstName lastName:(NSString *)lastName email:(NSString *)email NS_DESIGNATED_INITIALIZER;

@end
