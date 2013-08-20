//
//  CJAAppDelegate.m
//  CJAMacros
//
//  Created by Carl Jahn on 20.08.13.
//  Copyright (c) 2013 Carl Jahn. All rights reserved.
//

#import "CJAAppDelegate.h"
#import "DemoViewController.h"

@implementation CJAAppDelegate

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
  
  self.window = [[UIWindow alloc] initWithFrame:[[UIScreen mainScreen] bounds]];
  
  self.window.rootViewController = [DemoViewController new];
  self.window.backgroundColor = [UIColor whiteColor];
  [self.window makeKeyAndVisible];
  return YES;
}



@end
