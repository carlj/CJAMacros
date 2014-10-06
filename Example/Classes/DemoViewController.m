//
//  DemoViewController.m
//  CJAMacros
//
//  Created by Carl Jahn on 20.08.13.
//  Copyright (c) 2013 Carl Jahn. All rights reserved.
//

DEFINE_KEY(kTestKey)
DECLARE_KEY(kTestKey)

DEFINE_KEY_WITH_VALUE(kNewTestKey, CustomValue)

#import "DemoViewController.h"

@interface DemoViewController ()

@end

@implementation DemoViewController

CJAMacrosSingletonImplemantion


- (void)viewDidLoad {
    [super viewDidLoad];
    
    [self performLocalizationMacro];
    [self performMainThreadMacro];
    [self performRuntimeChecks];
    [self performDeviceChecks];
    [self performKeyDeclaration];
    [self performWeakDeclarations];
    [self perfomKindOfClassChecks];
    [self perfomFloatChecks];
}

- (void)performLocalizationMacro {
    
    //Localization Shortcut
    NSString *localString = CJALocalize(@"MyTestLocalizationStrinKey");
    NSLog(@"%s %@", __FUNCTION__, localString);
}

- (void)performNotificationMacros {
    
    //Notification Shortcuts
    static NSString *testNotificationName = @"TestNotificationName";
    
    addObserver(testNotificationName, self, testNotification:, nil);
    
    notify(testNotificationName, nil, nil);
    
    removeObserver(self);
}

- (void)testNotification:(NSNotification *)notification {
    NSLog(@"%s %@", __FUNCTION__, notification.name);
}


- (void)performMainThreadMacro {
    
    //Main thread shortcuts
    onMainThread(
                 NSLog(@"This should be on the Main Thread");
                 notify(@"NotificationOnMainThread", nil, nil);
                 );
    
}

- (void)performRuntimeChecks {
    
    if (SYSTEM_VERSION_GREATER_THAN_OR_EQUAL_TO( _iOS_7_0) ) {
        NSLog(@"Why are on iOS 7 or greater");
    }
    
    //you can always use the normal NSFoundationVersionNumber's
    if (SYSTEM_VERSION_GREATER_THAN_OR_EQUAL_TO( NSFoundationVersionNumber_iOS_7_0)) {
        NSLog(@"same runtime check as above");
    }
    
    if (SYSTEM_VERSION_LESS_THAN( _iOS_7_0) ) {
        NSLog(@"Why are on iOS 6, 5, 4, 3 or 2");
    }
    
}

- (void)performDeviceChecks {
    
    if (DEVICE_IS_IPAD) {
        NSLog(@"The current device is an iPad");
    }
    
    if (DEVICE_IS_IPHONE) {
        NSLog(@"The current device is an iPhone (incl. iPhone 5 and iPod Touch's)");
    }
    
    if (DEVICE_IS_IPHONE_5) {
        NSLog(@"The current device is an iPhone 5 or iPod Touch 5 Gen.");
    }
    
    if (DEVICE_IS_IPHONE_6) {
        NSLog(@"The current device is an iPhone 6");
    }
    
    if (DEVICE_IS_IPHONE_6_PLUS) {
        NSLog(@"The current device is an iPhone 6 Plus");
    }
}

- (void)performKeyDeclaration {
    
    
    NSLog(kTestKey);
    NSLog(kNewTestKey);
}

- (void)performWeakDeclarations {
    // Test self weak.
    CJAWeakSelf;
    NSAssert([weakself isEqual:self], @"Objects should be equal");
    
    CJAStrongSelf;
    NSAssert([strongself isEqual:self], @"Objects should be equal");
    
    // Test weak strings.
    NSString *text = @"Example";
    CJAWeak(text);
    NSAssert([weaktext isEqual:text], @"NSString objects should be equal");
    
    CJAStrong(text);
    NSAssert([strongtext isEqual:text], @"NSString objects should be equal");
    
    // Test weak numbers
    NSNumber *number = @(1);
    CJAWeakWithNameAndObject(number, Number);
    NSAssert([weakNumber isEqual:number], @"NSNumber objects should be equal");
    
    CJAStrongWithNameAndObject(number, Number);
    NSAssert([strongNumber isEqual:number], @"NSNumber objects should be equal");
    
}

- (void)perfomKindOfClassChecks {
    
    NSAssert(CJAIsKindOfClass(self, UIViewController), @"self isnt Kind of UIViewController Subclass ");
    NSAssert(!CJAIsKindOfClass(self, UIView), @"self shouldnt be a UIView Subclass ");
}

- (void)perfomFloatChecks {

    NSAssert(CJAFloatEqual(1.0f, 1.0f), @"floats should be equal");
    NSAssert(!CJAFloatEqual(1.0001f, 1.0f), @"floats shouldnt be equal");
}

@end
