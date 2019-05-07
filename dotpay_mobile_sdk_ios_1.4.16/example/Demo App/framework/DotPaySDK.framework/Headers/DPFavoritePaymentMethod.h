//
//  DPFavoritePaymentMethod.h
//  DotPaySDK
//
//  Created by dzajac on 30/08/16.
//  Copyright å© 2016 CTM Mobiltek. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef enum DPPaymentMethodType : NSUInteger {
    DPPaymentMethodTypeCard,
    DPPaymentMethodTypePaymentChannel
} DPPaymentMethodType;

@protocol DPFavoritePaymentMethod <NSObject>
- (NSString *)favoritePaymentMethodId;
- (NSString *)favoritePaymentMethodLogo;
- (NSString *)favoritePaymentMethodTitle;
- (NSString *)favoritePaymentMethodDetailText;
@end

@interface DPFavoritePaymentMethod : NSObject <NSCoding>

- (instancetype)initWithPaymentMethodId:(NSString *)paymentMethodId type:(DPPaymentMethodType)type;

@property (nonatomic, strong) NSString *paymentMethodId;
@property (nonatomic, strong) NSDate *dateUpdated;
@property (nonatomic, assign) DPPaymentMethodType type;

@end
