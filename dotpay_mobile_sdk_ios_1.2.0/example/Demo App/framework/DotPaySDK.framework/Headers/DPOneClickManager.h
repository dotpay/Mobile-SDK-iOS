//
// Created by Mateusz Maćkowiak on 22/07/15.
// Copyright (c) 2015 Dotpay. All rights reserved.
//

#import <Foundation/Foundation.h>

@class DPOneClickPaymentCard;
@class DPOneClickPaymentCardInfo;
extern NSString * const kOneClickUniqueIdentifierServiceKey;
extern NSInteger kDPOneClickPaymentCardPaymentChannelId;

@interface DPOneClickManager : NSObject

+ (instancetype)sharedInstance;

- (instancetype)init __attribute__((unavailable("DPOneClickManager is a Singelton use sharedInstance")));

@property (nonatomic, getter=isEnabled) BOOL enabled;

@property (nonatomic, readonly) BOOL isDataAvailable;

- (void)clearData;

/*!
 * Returns the registered payment cards
 */
- (NSArray<DPOneClickPaymentCard *> *)paymentCards;

/*!
 * Register a one click payment card
 * @param registrationInfo cannot be nil
 * @param completion can be nil
 */
- (void)registerPaymentCardWithCardInfo:(DPOneClickPaymentCardInfo *)cardInfo withCompletion:(void (^)(DPOneClickPaymentCard *response, NSError *error))completion;

/*!
 * Remove a payment card
 *
 * @param cardId cannot be nil
 * @param completion can be nil
 */
- (void)unregisterPaymentCardWithId:(NSString *)cardId withCompletion:(void (^)(NSDictionary *response, NSError *error))completion;

/*!
 * Set a default one click payment card
 * @param card cannot be nil
 */
- (void)setDefaultOneClickPaymentCardWithId:(NSString *)cardId;

/*!
 * Returns the default one click payment card
 */
- (DPOneClickPaymentCard *)defaultOneClickPaymentCard;


@end