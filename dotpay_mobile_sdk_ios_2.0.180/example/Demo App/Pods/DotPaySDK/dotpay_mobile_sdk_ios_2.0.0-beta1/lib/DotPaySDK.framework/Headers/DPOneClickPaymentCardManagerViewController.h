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
@property (nonatomic, strong) NSString *phone;
@property (nonatomic, strong) NSString *street;
@property (nonatomic, strong) NSString *street_n1;
@property (nonatomic, strong) NSString *houseNumber;
@property (nonatomic, strong) NSString *postcode;
@property (nonatomic, strong) NSString *city;

- (instancetype)initWithMerchantId:(NSString *)merchantId currency:(NSString *)currency NS_DESIGNATED_INITIALIZER;
- (instancetype)initWithMerchantId:(NSString *)merchantId currency:(NSString *)currency firstName:(NSString *)firstName lastName:(NSString *)lastName email:(NSString *)email NS_DESIGNATED_INITIALIZER;
- (instancetype)initWithMerchantId:(NSString *)merchantId currency:(NSString *)currency firstName:(NSString *)firstName lastName:(NSString *)lastName email:(NSString *)email phone:(NSString *)phone street:(NSString *)street street_n1:(NSString *)street_n1 houseNumber:(NSString *)houseNumber postcode:(NSString *)postcode city:(NSString *)city NS_DESIGNATED_INITIALIZER;

@end
