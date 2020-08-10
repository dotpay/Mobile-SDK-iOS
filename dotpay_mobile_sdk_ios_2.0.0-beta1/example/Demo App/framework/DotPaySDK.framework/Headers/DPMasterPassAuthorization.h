//
//  DPMasterPassAuthorization.h
//  DotPaySDK
//
//  Created by Jan Posz on 16.11.2017.
//  Copyright © 2017 CTM Mobiltek. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol DPMasterpassAuthorization <NSObject>

- (void)didCreateAuthorization:(BOOL)successful andError:(NSError *)error;

- (void)didAuthorizeUser:(BOOL)successful andError:(NSError *)error;

@end
