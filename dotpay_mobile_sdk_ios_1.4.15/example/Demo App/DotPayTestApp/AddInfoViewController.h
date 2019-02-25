//
//  AddInfoViewController.h
//  DotPayTestApp
//
//  Created by Diana Komolova on 20.09.2016.
//  Copyright © 2016 CTM Mobiltek. All rights reserved.
//

#import "ViewController.h"
#import "AdditionalInfo.h"

@class AddInfoViewController;
@protocol AddInfoViewControllerDelegate <NSObject>
@required

- (void) addInfoViewController:(AddInfoViewController *)viewController saveInfo:(AdditionalInfo *)info atIndexPath: (NSIndexPath *)indexPath;

@end

@interface AddInfoViewController : ViewController <UITextFieldDelegate>
@property (strong, nonatomic) IBOutlet UITextField *keyTextField;
@property (strong, nonatomic) IBOutlet UITextField *valueTextField;
@property (strong, nonatomic) AdditionalInfo *info;
@property (strong, nonatomic) NSIndexPath *indexPath;
@property (weak, nonatomic) id <AddInfoViewControllerDelegate> delegate;

@end
