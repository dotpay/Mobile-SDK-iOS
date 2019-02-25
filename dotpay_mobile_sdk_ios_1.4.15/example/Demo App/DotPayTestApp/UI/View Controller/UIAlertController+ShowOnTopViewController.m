//
//  UIAlertController+ShowOnTopViewController.m
//  DotPayTestApp
//
//  Created by Mateusz Mularski on 23.08.2018.
//  Copyright © 2018 CTM Mobiltek. All rights reserved.
//

#import "UIAlertController+ShowOnTopViewController.h"

@implementation UIAlertController(ShowOnTopViewController)

- (void)showOnTop {
    UIWindow *topWindow = [[UIWindow alloc] initWithFrame:[UIScreen mainScreen].bounds];
    UIViewController *topVC = [[UIViewController alloc] init];
    topVC.view.backgroundColor = [UIColor clearColor];
    topWindow.rootViewController = topVC;
    topWindow.windowLevel = UIWindowLevelAlert + 1;
    [topWindow makeKeyAndVisible];
    [topVC presentViewController:self animated:YES completion:NULL];
}

- (void)hide {
    [self dismissViewControllerAnimated:YES completion:NULL];
}

@end
