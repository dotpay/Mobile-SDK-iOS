//
//  AddInfoViewController.m
//  DotPayTestApp
//
//  Created by Diana Komolova on 20.09.2016.
//  Copyright © 2016 CTM Mobiltek. All rights reserved.
//

#import "AddInfoViewController.h"
#import "AdditionalInfo.h"

@interface AddInfoViewController ()
@property (strong, nonatomic) UIBarButtonItem *saveButton;
@property (strong, nonatomic) UIBarButtonItem *cancelButton;
@end

@implementation AddInfoViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    self.title = @"Additional Info";
    self.saveButton = [[UIBarButtonItem alloc] initWithTitle:@"Save" style:UIBarButtonItemStylePlain  target:self action:@selector(saveButtonTapped)];
    self.cancelButton = [[UIBarButtonItem alloc] initWithTitle:@"Cancel" style:UIBarButtonItemStylePlain  target:self action:@selector(cancelButtonTapped)];
    self.navigationItem.rightBarButtonItem = self.saveButton;
    self.navigationItem.leftBarButtonItem = self.cancelButton;
    if (self.info) {
        self.keyTextField.text = self.info.key;
        self.valueTextField.text = self.info.value;
    }
}

- (void) saveButtonTapped{
    if (!self.info) {
        self.info = [[AdditionalInfo alloc] init];
    }
    self.info.key = self.keyTextField.text;
    self.info.value = self.valueTextField.text;
    
    [self.delegate addInfoViewController:self saveInfo:self.info atIndexPath:self.indexPath];
    [self.navigationController popViewControllerAnimated:YES];
}

- (void) cancelButtonTapped {
    [self.navigationController popViewControllerAnimated:YES];
}

- (void)textFieldDidEndEditing:(UITextField *)textField{
    if([textField isEqual:self.keyTextField]){
        self.info.key = textField.text;
    }
    if ([textField isEqual:self.valueTextField]) {
        self.info.value = textField.text;
    }
}

@end
