//
//  AdditionalInfoCellTableViewCell.h
//  DotPayTestApp
//
//  Created by mmackowiak on 09.10.2015.
//  Copyright © 2015 CTM Mobiltek. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "AdditionalInfo.h"

@interface AdditionalInfoCellTableViewCell : UITableViewCell

@property (weak, nonatomic) AdditionalInfo* additionalInfo;

@property (weak, nonatomic) IBOutlet UITextField *keyTextField;
@property (weak, nonatomic) IBOutlet UITextField *valueTextField;

@end
