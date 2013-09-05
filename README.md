#CJA Macros
Collection of daily used Macros in my iOS Projects  
  
[![Build Status](https://travis-ci.org/carlj/CJAMacros.png?branch=master)](https://travis-ci.org/carlj/CJAMacros)

##Installation
Just drag&drop the ```CJAMarcos.h``` and ```CJAMarcos.m``` files in your XCode Project. 
For global usage you can import the ```CJAMarcos.h``` in your projects ```-Prefix.pch``` file.

##Usage
First check out the example Project for further examples

``` objc
//Should output the current function fingerprint
kNSLogFunction

//Should output the current function fingerprint + the given object description
kNSLogFunctionWithObject(@"My test log");
kNSLogFunctionWithObject(self);

//Use the Error Log to log statements in RELEASE mode
ErrorLog(@"Always print this");

//Localization Shortcut
NSString *localString = _(@"MyTestLocalizationStrinKey");
kNSLogFunctionWithObject(localString);

//Notification Shortcuts
static NSString *testNotificationName = @"TestNotificationName";

addObserver(testNotificationName, self, testNotification:, nil);

notify(testNotificationName, nil, nil);

removeObserver(self);

//Main thread shortcuts
onMainThread(
  //post a notification on the main thread
  kNSLogFunctionWithObject(@"This should be on the Main Thread");
  notify(@"NotificationOnMainThread", nil, nil);
);

//runtime system version checks
if (SYSTEM_VERSION_GREATER_THAN_OR_EQUAL_TO( _iOS_7_0) ) {
  kNSLogFunctionWithObject(@"Why are on iOS 7")
}

//you can always use the normal NSFoundationVersionNumber's
if (SYSTEM_VERSION_GREATER_THAN_OR_EQUAL_TO( NSFoundationVersionNumber_iOS_7_0)) {
  kNSLogFunctionWithObject(@"same runtime check as above")
}

if (SYSTEM_VERSION_LESS_THAN( _iOS_7_0) ) {
  kNSLogFunctionWithObject(@"We are on iOS 6, 5, 4, 3 or 2");
}

//Device Checks
if (DEVICE_IS_IPAD) {
	kNSLogFunctionWithObject(@"The current device is an iPad");
}

if (DEVICE_IS_IPHONE) {
	kNSLogFunctionWithObject(@"The current device is an iPhone (incl. iPhone 5 and iPod Touch's)");
}

if (DEVICE_IS_IPHONE_5) {
	kNSLogFunctionWithObject(@"The current device is an iPhone 5 or iPod Touch 5 Gen.");
}
```

##License
MIT License
