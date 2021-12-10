//
//  DPOneClickNewCreditCardViewController.h
//  DotPaySDK
//
//  Created by dzajac on 19/08/16.
//  Copyright © 2016 CTM Mobiltek. All rights reserved.
//

#import <UIKit/UIKit.h>

@class DPOneClickPaymentCard;
@class DPPaymentFormField;

@protocol DPNewOneClickPaymentCardDelegate <NSObject, UITextViewDelegate>

- (void)oneClickPaymentCardRegistered:(DPOneClickPaymentCard *)paymentCard withError:(NSError *)error;

@end

@interface DPNewOneClickPaymentCardViewController : UIViewController

- (instancetype)initWithMerchantId:(NSString *)merchantId currency:(NSString *)currency;
- (instancetype)initWithMerchantId:(NSString *)merchantId currency:(NSString *)currency firstName:(NSString *)firstName lastName:(NSString *)lastName email:(NSString *)email;
- (instancetype)initWithMerchantId:(NSString *)merchantId currency:(NSString *)currency firstName:(NSString *)firstName lastName:(NSString *)lastName email:(NSString *)email phone:(NSString *)phone street:(NSString *)street street_n1:(NSString *)street_n1 houseNumber:(NSString *)houseNumber postcode:(NSString *)postcode city:(NSString *)city;

@property (nonatomic, weak) id<DPNewOneClickPaymentCardDelegate> delegate;
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
@property (nonatomic, strong) NSNumber *paymentChannelId;
@property (nonatomic, strong) NSString *merchantName;
@property (nonatomic, strong) DPPaymentFormField *regulationsFormField;
@end
