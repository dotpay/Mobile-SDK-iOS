//
//  DPOneClickExternalPaymentCard.h
//  DotPaySDK
//
//  Created by Mateusz Mularski on 27.06.2018.
//  Copyright © 2018 CTM Mobiltek. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface DPOneClickExternalPaymentCard : NSMutableDictionary<NSString *, id>

@property (strong, nonatomic, nonnull) NSString *creditCardId;
@property (strong, nonatomic, nonnull) NSString *maskedNumber;
@property (strong, nonatomic, nonnull) NSString *brandName;
@property (strong, nonatomic, nonnull) NSString *brandCodename;
@property (strong, nonatomic, nonnull) NSString *logoUrlPath;

- (instancetype)init __attribute__((unavailable("Use parameterized init")));
- (instancetype)initWithCreditCardId:(NSString * _Nonnull)creditCardId maskedNumber:(NSString * _Nonnull)maskedNumber brandName:(NSString * _Nonnull)brandName brandCodename:(NSString * _Nonnull)brandCodename logoUrlPath:(NSString * _Nonnull)logoUrlPath;

- (NSDictionary *)toDictionary;

@end
