//
// Created by Mateusz Maćkowiak on 22/07/15.
// Copyright (c) 2015 Dotpay. All rights reserved.
//

#import <Foundation/Foundation.h>

@class DPOneClickExternalPaymentCard;
@class DPOneClickPaymentCard;
@class DPOneClickPaymentCardInfo;
@class DPOneClickCardRegistrationData;

extern NSString * const kOneClickUniqueIdentifierServiceKey;
extern NSInteger kDPOneClickPaymentCardPaymentChannelId;

@protocol DPOneClickManagerDelegate;

@interface DPOneClickManager : NSObject

@property (assign, nonatomic) id<DPOneClickManagerDelegate> delegate;

+ (instancetype)sharedInstance;

- (instancetype)init __attribute__((unavailable("DPOneClickManager is a Singelton use sharedInstance")));

@property (nonatomic, getter=isEnabled) BOOL enabled;
@property (nonatomic) BOOL useInternalCards;

/// Set to YES by default. SecureTextEntry properties of the CCV/CVV text fields are set to the same value.
@property (nonatomic) BOOL treatsCvvAsPassword;
    
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

/*!
 * Saves Masterpass Refresh Token and Transaction Type (payment or wallet selector) for further use
 */
- (void)saveMasterpassRefreshToken:(NSString *)token andTransactionType:(NSString *)transactionType;

/*!
 * Returns Saved Masterpass Refresh Token and Transaction Type (payment or wallet selector)
 */
- (NSDictionary *)masterpassRefreshTokenAndTransactionType;

/*!
 * Configures manager with cards registered for particular customer Id.
 * Setting customerId to NULL or empty string clears external CC data.
 */
- (void)configureWithExternalCards:(NSArray<DPOneClickExternalPaymentCard *> *)externalCards forCustomerId:(NSString *)customerId;

/*!
 * Convenience method.
 * Same as invoking configureWithExternalCards:forCustomerId: with NULL customerId parameter.
 */
- (void)clearExternalCardsData;

@end

@protocol DPOneClickManagerDelegate
- (void)oneClickManager:(DPOneClickManager *)manager didRegisterNewCreditCard:(DPOneClickCardRegistrationData *)cardRegistrationData;
- (void)oneClickManager:(DPOneClickManager *)manager didChangeDefaultOneClickPaymentCard:(DPOneClickPaymentCard *)newDefaultCard;
@end
