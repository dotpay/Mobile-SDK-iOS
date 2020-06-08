/*!
 *  @header DotPaySDK.h
 *  dotpay-sdk
 *
 *  Created by Mariusz Śpiewak on 05.03.2015.
 *  Copyright (c) 2015 Dotpay. All rights reserved.
 */

#import <Foundation/Foundation.h>

@class DPPaymentInfo;
@class DPPaymentDetails;

NS_ASSUME_NONNULL_BEGIN

@interface DotPay : NSObject

// Framework version number.
@property (nonatomic, strong, readonly) NSString *sdkShortVersionString;
@property (nonatomic, strong, readonly) NSString *sdkBundleVersion;

@property (nonatomic, assign, getter=isDebugMode) BOOL debugMode;
@property (nonatomic, assign) BOOL showDetailsOnSummaryScreen;

- (instancetype)init __attribute__((unavailable("DotPay is a Singelton use sharedInstance")));

/*!
 *  Typical sharedInstance.
 *
 *  @return Singleton instance of DotPay object.
 */
+ (instancetype)sharedInstance;

/*!
 *  Payment form will be describe in selected language.
 *  By default it's set as current device language.
 */
@property (nonatomic, strong) NSString *defaultLanguage;

/*!
 *  gets available list of DPPaymentChannels for payment info
 *
 *  @param paymentInfo cannot be nil
 *  @param completion cannot be nil
 */
- (void)getChannelListForPaymentInfo:(DPPaymentInfo *)paymentInfo withCompletion:(void (^)(NSArray *channelList, DPPaymentDetails *paymentDetails, NSError *error))completion;

/*!
 *  gets available list of DPPaymentChannels for payment info
 *
 *  @param paymentInfo cannot be nil
 *  @param online filter by online status
 *  @param completion cannot be nil
 */
- (void)getChannelListForPaymentInfo:(DPPaymentInfo *)paymentInfo online:(BOOL)online withCompletion:(void (^)(NSArray *channelList, DPPaymentDetails *paymentDetails, NSError *error))completion;

/*!
 *  gets available list of DPPaymentChannels for payment info
 *
 *  @param paymentInfo cannot be nil
 *  @param ids filter by ids
 *  @param completion cannot be nil
 */
- (void)getChannelListForPaymentInfo:(DPPaymentInfo *)paymentInfo withIds:(NSArray*)ids withCompletion:(void (^)(NSArray *channelList, DPPaymentDetails *paymentDetails, NSError *error))completion;

/*!
 *  gets available list of DPPaymentChannels for payment info
 *
 *  @param paymentInfo cannot be nil
 *  @param group filter by group
 *  @param completion cannot be nil
 */
- (void)getChannelListForPaymentInfo:(DPPaymentInfo *)paymentInfo group:(NSString*)group withCompletion:(void (^)(NSArray *channelList, DPPaymentDetails *paymentDetails, NSError *error))completion;


/*!
 *  gets available list of DPCurrencies
 *
 *  @param completion cannot be nil
 */
- (void)getCurrencyListWithCompletion:(void (^)(NSArray *currencyList, NSError *error))completion;

/*!
 *  gets available list of supported languages
 *
 *  @param completion cannot be nil
 */
- (void)getLanguageListWithCompletion:(void (^)(NSArray *languageList, NSError *error))completion;

/*!
 *  gets summary of payment
 *
 *  @param paymentToken cannot be nil
 *  @param paymentNumber cannot be nil
 *  @param merchantId cannot be nil
 *  @param completion cannot be nil
 */
- (void)getSummaryStatusForPaymentToken:(NSString *)paymentToken paymentNumber:(NSString *)paymentNumber merchantId:(NSString *)merchantId withCompletion:(void (^)(NSDictionary *jsonSummary, NSError *error))completion;

@end

NS_ASSUME_NONNULL_END
