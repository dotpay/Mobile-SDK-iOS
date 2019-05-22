//
//  DPPaymentChannelGroup.h
//  DotPaySDK
//
//  Created by Mateusz Maćkowiak on 08/05/15.
//  Copyright (c) 2015 Dotpay. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface DPPaymentChannelGroup : NSObject

-(instancetype)initWithGroup:(NSString*)group andGroupName:(NSString*)groupName;

@property (nonatomic, strong, readonly) NSString *group;
@property (nonatomic, strong, readonly) NSString *groupName;

@property (nonatomic, strong, readonly) NSMutableArray *channels;

@end

NS_ASSUME_NONNULL_END