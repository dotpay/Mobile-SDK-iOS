//
//  DPOneClickNewCreditCardViewController.h
//  DotPaySDK
//
//  Created by dzajac on 19/08/16.
//  Copyright © 2016 CTM Mobiltek. All rights reserved.
//

#import <UIKit/UIKit.h>

@class DPOneClickPaymentCard;

@protocol DPNewOneClickPaymentCardDelegate <NSObject, UITextViewDelegate>

- (void)oneClickPaymentCardRegistered:(DPOneClickPaymentCard *)paymentCard withError:(NSError *)error;

@end

@interface DPNewOneClickPaymentCardViewController : UIViewController

- (instancetype)initWithMerchantId:(NSString *)merchantId currency:(NSString *)currency;
- (instancetype)initWithMerchantId:(NSString *)merchantId currency:(NSString *)currency firstName:(NSString *)firstName lastName:(NSString *)lastName email:(NSString *)email;

@property (nonatomic, weak) id<DPNewOneClickPaymentCardDelegate> delegate;
@property (nonatomic, strong) NSString *merchantId;
@property (nonatomic, strong) NSString *currency;
@property (nonatomic, strong) NSString *firstName;
@property (nonatomic, strong) NSString *lastName;
@property (nonatomic, strong) NSString *email;
@property (nonatomic, strong) NSNumber *paymentChannelId;
@property (nonatomic, strong) NSString *merchantName;
@property (nonatomic, strong) NSString *merchantRegulationsURLString;
@end
