//
//  DPPaymentSummary.h
//  DotPaySDK
//
//  Created by Mariusz Śpiewak on 10.03.2015.
//  Copyright (c) 2015 Dotpay. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
extern NSString *const kDPPaymentSummaryStatusNew;
extern NSString *const kDPPaymentSummaryStatusProcessing;
extern NSString *const kDPPaymentSummaryStatusRejected;
extern NSString *const kDPPaymentSummaryStatusCompleted;
extern NSString *const kDPPaymentSummaryStatusProcessingRealizationWaiting;
extern NSString *const kDPPaymentSummaryStatusProcessingRealization;
@class DPCurrency;


@interface DPPaymentSummary : NSObject <NSCoding, NSCopying>

- (instancetype)init __attribute__((unavailable("DPPaymentSummary must be created by DPPaymentSummaryFactory")));

- (BOOL)isEqual:(nullable id)other;

- (BOOL)isEqualToSummary:(DPPaymentSummary *)summary;

@property (nonatomic, strong, readonly) NSDate *creationDate;
@property (nonatomic, strong, readonly) NSDecimalNumber *amount;
@property (nonatomic, strong, readonly) DPCurrency *currency;
@property (nonatomic, strong, readonly) NSString *money;
@property (nonatomic, strong, readonly) NSDecimalNumber *originalAmount;
@property (nonatomic, strong, readonly) DPCurrency *originalCurrency;
@property (nonatomic, strong, readonly) NSString *originalMoney;
@property (nonatomic, assign, readonly) BOOL isExchanged;
@property (nonatomic, strong, readonly) NSString *exchange;
@property (nonatomic, strong, readonly) NSString *exchangeReverse;
@property (nonatomic, strong, readonly) NSNumber *exchangeRate;
@property (nonatomic, strong, readonly) NSString *status;
@property (nonatomic, strong, readonly) NSString *type;
@property (nonatomic, strong, readonly) NSString *statusI18n;
@property (nonatomic, strong, readonly) NSString *typeI18n;
@property (nonatomic, strong, readonly) NSString *token;
@property (nonatomic, strong, readonly) NSString *number;
@property (nonatomic, strong, readonly, nullable) NSString *textDescription;
@property (nonatomic, strong, readonly, nullable) NSString *additionalInfoText;
@property (nonatomic, strong, readonly, nullable) NSString *additionalInfoHtml;
/**** Example: ":[{"label":"Numer kuponu", "value":"756753856367546"},{"label":"Kwota kuponu", "value":"12,12 PLN"},]***/
@property (nonatomic, strong, readonly) NSArray *additionalInfoParams;
///of type DPPaymentSummary
@property (nonatomic, strong, readonly) NSArray *relatedOperations;

@property (nonatomic, strong, readonly) NSString *merchantID;
@property (nonatomic, strong, readonly) NSString *language;
@property (nonatomic, strong, readonly) NSString *receiver;
@property (nonatomic, strong, readonly) NSString *receiverEmail;
@property (nonatomic, strong, readonly) NSString *control;
@property (nonatomic, strong, readonly) NSString *channelId;

@end

NS_ASSUME_NONNULL_END
