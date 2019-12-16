//
//  DPPaymentHistory.h
//  DotPaySDK
//
//  Created by Rafał Prążyński on 25/03/15.
//  Copyright (c) 2015 Dotpay. All rights reserved.
//

#import <Foundation/Foundation.h>

@class DPPaymentHistory;
@class DPPaymentSummary;

NS_ASSUME_NONNULL_BEGIN

@protocol DPPaymentHistoryObserver <NSObject>

@optional

- (void)willUpdatePaymentSummariesForPaymentHistory:(DPPaymentHistory *)paymentHistory;

- (void)didUpdatePaymentSummariesForPaymentHistory:(DPPaymentHistory *)paymentHistory;

- (void)paymentHistory:(DPPaymentHistory *)paymentHistory willRemovePaymentSummary:(DPPaymentSummary *)paymentSummary;

- (void)paymentHistory:(DPPaymentHistory *)paymentHistory didRemovePaymentSummary:(DPPaymentSummary *)paymentSummary;

- (void)paymentHistory:(DPPaymentHistory *)paymentHistory willAddPaymentSummary:(DPPaymentSummary *)paymentSummary;

- (void)paymentHistory:(DPPaymentHistory *)paymentHistory didAddPaymentSummary:(DPPaymentSummary *)paymentSummary;

- (void)paymentHistory:(DPPaymentHistory *)paymentHistory didUpdatePaymentSummary:(DPPaymentSummary *)paymentSummary;

- (void)paymentHistory:(DPPaymentHistory *)paymentHistory didFailedToUpdatePaymentSummary:(DPPaymentSummary *)paymentSummary withError:(NSError *)error;

@end

@interface DPPaymentHistory : NSObject

/*!
 *  Updates details for single payment summary
 */
- (void)refreshPaymentSummaryDetails:(DPPaymentSummary*)paymentSummary withCompletion:(void (^)(BOOL success))completion;

@property (nonatomic, strong, readonly) NSString *filePath;

/*!
 *  @return Singleton instance of DPPaymentHistory object.
 */
+ (instancetype)sharedInstance;

/*!
 *  @param filePath path at which history will be saved
 *  capacity will be set to default value (kDPPaymentDefaultHistoryCapacity)
 */
- (instancetype)initWithFilePath:(NSString *)filePath;

/*!
 *  History of payments
 *
 *  @param filePath path at which history will be saved
 *  @param capacity maximum number of elements in history
 *
 */
- (instancetype)initWithFilePath:(NSString *)filePath capacity:(NSUInteger)capacity;

/*!
 *  maximum number of elements in history
 */
@property (nonatomic, assign, readonly) NSUInteger capacity;

/*!
 *  full payment history
 *
 *  @return NSArray that contains history
 */
@property (nonatomic, readonly) NSArray *paymentHistory;

/*!
 *  Use this method to save history
 */
- (void)save;

/*!
 *  Use this method to add elements to history
 *
 *  @param payment DPPaymentSummary object
 */
- (void)addPaymentSummary:(DPPaymentSummary *)paymentSummary;

/*!
 *  Use this method to remove elements to history
 *
 *  @param payment DPPaymentSummary object
 */
- (void)removePaymentSummary:(DPPaymentSummary *)paymentSummary;

/*!
 *  Use this method to clean all history
 */
- (void)clear;


- (void)update;

- (void)updatePaymentSummary:(DPPaymentSummary *)paymentSummary;

@end


@interface DPPaymentHistory (Observers)

@property (nonatomic, readonly) NSArray *observers;

- (void)registerObserver:(id <DPPaymentHistoryObserver>)observer;

- (void)unRegisterObserver:(id <DPPaymentHistoryObserver>)observer;

@end

NS_ASSUME_NONNULL_END