//
// Created by mmackowiak on 09.10.2015.
// Copyright (c) 2015 CTM Mobiltek. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "AddInfoViewController.h"

extern NSString * const kAddititionalInfoKey;
@interface AdditionalInfoTableViewController : UITableViewController <AddInfoViewControllerDelegate>

@property (nonatomic, strong) NSMutableArray *additionalInfos;
@property (nonatomic, strong) NSUserDefaults *additionalInfoStore;

@end
