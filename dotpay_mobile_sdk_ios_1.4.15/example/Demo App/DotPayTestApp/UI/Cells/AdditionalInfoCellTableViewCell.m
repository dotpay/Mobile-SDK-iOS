//
//  AdditionalInfoCellTableViewCell.m
//  DotPayTestApp
//
//  Created by mmackowiak on 09.10.2015.
//  Copyright © 2015 CTM Mobiltek. All rights reserved.
//

#import "AdditionalInfoCellTableViewCell.h"

@interface AdditionalInfoCellTableViewCell () <UITextFieldDelegate>

@end


@implementation AdditionalInfoCellTableViewCell

- (void)setAdditionalInfo:(AdditionalInfo *)additionalInfo {
    _additionalInfo = additionalInfo;
    self.keyTextField.text = additionalInfo.key;
    self.keyTextField.delegate = self;
    self.valueTextField.text = additionalInfo.value;
    self.valueTextField.delegate = self;
}

- (void)textFieldDidEndEditing:(UITextField *)textField {
    if(textField.tag == 1){
        self.additionalInfo.value = textField.text;
    } else {
        self.additionalInfo.key = textField.text;
    }
}

@end
