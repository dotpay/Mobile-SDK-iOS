/*!
 *  @header DotPaySDK.h
 *  dotpay-sdk
 *
 *  Created by Mariusz Śpiewak on 05.03.2015.
 *  Copyright (c) 2015 Dotpay. All rights reserved.
 */

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@class DPPaymentInfo;
@class DPPaymentDetails;
@class DPOneClickPaymentCardInfo;
@class DPOneClickPaymentCard;
@class DPPaymentSummary;

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

/*  color of payment button (default is #ab191e)
 */
@property (nonatomic, strong) UIColor *paymentButtonColor;

- (void)setPaymentButtonColor:(UIColor * _Nonnull)paymentButtonColor;
/* text color of payment button (default is white)
 */
@property (nonatomic, strong) UIColor *paymentButtonFontColor;

- (void)setPaymentButtonFontColor:(UIColor * _Nonnull)paymentButtonFontColor;

/* color of payment details header (default is #ab191e)
 */
@property (nonatomic, strong) UIColor *paymentHeaderDetailsColor;

- (void)setPaymentHeaderDetailsColor:(UIColor * _Nonnull)paymentHeaderDetailsColor;

/* text color of payment details header (default is white)
 */
@property (nonatomic, strong) UIColor *paymentHeaderDetailsFontColor;

- (void)setPaymentHeaderDetailsFontColor:(UIColor * _Nonnull)paymentHeaderDetailsFontColor;

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

/*!
 *  gets summary of payment
 *
 *  @param paymentInfo cannot be nil
 *  @param paymentCard can be nil
 *  @param completion cannot be nil
 */
- (void)oneClickPaymentWithPaymentInfo:(DPPaymentInfo *)paymentInfo paymentCard:(nullable DPOneClickPaymentCard *)paymentCard withCompletion:(void (^)(DPPaymentSummary *_Nullable paymentSummary, NSError * _Nullable error))completion;


@end

NS_ASSUME_NONNULL_END
