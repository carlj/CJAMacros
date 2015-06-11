//
//  CJAMacros.h
//  CJAMacros
//
//  Created by Carl Jahn
//  Copyright (c) 2013 Carl Jahn. All rights reserved.
//

#import <Foundation/Foundation.h>
#include <Availability.h>


///---------------------------
/// @name Localization
///---------------------------

/**
 Simple Shortcut for your NSLocalizedString(@"..", @"..")
 */
#define CJALocalize(_key) NSLocalizedString( _key , nil);


///---------------------------
/// @name NSNotificationCenter
///---------------------------

/**
 Shortcut for [[NSNotificationCenter ...] postNotificationName: ...]
 @param notificationName - The notification name you want to post
 @param obj - The object for the notification
 @param userInfoDictionary - The NSDictionary for the userInfo
 */
#define notify(_notificationName, _obj, _userInfoDictionary) [[NSNotificationCenter defaultCenter] postNotificationName: _notificationName object: _obj userInfo: _userInfoDictionary];

/**
 Shortcut for [[NSNotificationCenter ...] addObserver: ...]
 @param notificationName - The notification name you want to post
 @param observer - The observer object
 @param observerSelector - The current selector for the notificaton
 */
#define addObserver(_notificationName, _observer, _observerSelector, _obj) [[NSNotificationCenter defaultCenter] addObserver:_observer selector:@selector(_observerSelector) name:_notificationName object: _obj];

/**
 Shortcut for [[NSNotificationCenter ...] removeObserver: ...]
 @param observer - The observer object that should be remove from the NSNotificationCenter
 */
#define removeObserver(_observer) [[NSNotificationCenter defaultCenter] removeObserver: _observer];


///---------------------------
/// @name Main Thread
///---------------------------

/**
 Shortcut for perform a code snippet on the main thread
 @lambda - your code snippet that shuld execute on the main thread
 */
#define onMainThread(_lambda) \
if([NSThread isMainThread]){ \
_lambda \
} else { \
dispatch_async(dispatch_get_main_queue(), ^{ \
_lambda \
}); \
}

///---------------------------
/// @name Constant Defines
///---------------------------

#define DECLARE_KEY( key ) FOUNDATION_EXPORT NSString *const key;
#define DEFINE_KEY( key ) NSString *const key = @ #key;
#define DEFINE_KEY_WITH_VALUE( key, property ) NSString *const key = @ #property;

///---------------------------
/// @name Device Checks
///---------------------------

#define DEVICE_SCREEN_HAS_LENGTH(_frame, _length) ( fabs( MAX(CGRectGetHeight(_frame), CGRectGetWidth(_frame)) - _length) < DBL_EPSILON )

/**
 Runtime check for the current device.
 checks if the current device is an iPhone 4 or an Device with 480 Screen height
 */
#define DEVICE_IS_IPHONE_4 DEVICE_SCREEN_HAS_LENGTH([UIScreen mainScreen].bounds, 480.)

/**
 Runtime check for the current device.
 checks if the current device is an iPhone 5 or iPod Touch 5 Gen, or an Device with 1136 Screen height
 */
#define DEVICE_IS_IPHONE_5 DEVICE_SCREEN_HAS_LENGTH([UIScreen mainScreen].bounds, 568.)

/**
 Runtime check for the current device.
 checks if the current device is an iPhone 6
 */
#define DEVICE_IS_IPHONE_6 DEVICE_SCREEN_HAS_LENGTH([UIScreen mainScreen].bounds, 667.)

/**
 Runtime check for the current device.
 checks if the current device is an iPhone 6 Plus
 */
#define DEVICE_IS_IPHONE_6_PLUS DEVICE_SCREEN_HAS_LENGTH([UIScreen mainScreen].bounds, 736.)

/**
 Runtime check for the current device.
 checks if the current device is an iPhone or iPod Touch
 */
#define DEVICE_IS_IPHONE ( UIUserInterfaceIdiomPhone == UI_USER_INTERFACE_IDIOM() )

/**
 Runtime check for the current device.
 checks if the current device is an iPad
 */
#define DEVICE_IS_IPAD ( UIUserInterfaceIdiomPad == UI_USER_INTERFACE_IDIOM())

///---------------------------
/// @name Runtime Checks
///---------------------------

#ifndef __IPHONE_5_0
#define __IPHONE_5_0     50000
#endif
#ifndef __IPHONE_5_1
#define __IPHONE_5_1     50100
#endif
#ifndef __IPHONE_6_0
#define __IPHONE_6_0     60000
#endif
#ifndef __IPHONE_6_1
#define __IPHONE_6_1     60100
#endif
#ifndef __IPHONE_7_0
#define __IPHONE_7_0     70000
#endif
#ifndef __IPHONE_7_1
#define __IPHONE_7_1     70100
#endif
#ifndef __IPHONE_8_0
#define __IPHONE_8_0     80000
#endif

//If the symbol for iOS 5 isnt defined, define it.
#ifndef NSFoundationVersionNumber_iOS_5_0
#define NSFoundationVersionNumber_iOS_5_0 881.00
#endif

#ifdef NSFoundationVersionNumber_iOS_5_0
#define _iOS_5_0 NSFoundationVersionNumber_iOS_5_0
#endif

//If the symbol for iOS 5.1 isnt defined, define it.
#ifndef NSFoundationVersionNumber_iOS_5_1
#define NSFoundationVersionNumber_iOS_5_1 890.10
#endif

#ifdef NSFoundationVersionNumber_iOS_5_1
#define _iOS_5_1 NSFoundationVersionNumber_iOS_5_1
#endif

//If the symbol for iOS 6.0 isnt defined, define it.
#ifndef NSFoundationVersionNumber_iOS_6_0
#define NSFoundationVersionNumber_iOS_6_0 993.00 //extracted from iOS 7 Header
#endif

#ifdef NSFoundationVersionNumber_iOS_6_0
#define _iOS_6_0 NSFoundationVersionNumber_iOS_6_0
#endif

//If the symbol for iOS 6.1 isnt defined, define it.
#ifndef NSFoundationVersionNumber_iOS_6_1
#define NSFoundationVersionNumber_iOS_6_1 993.00 //extracted from iOS 7 Header
#endif

#ifdef NSFoundationVersionNumber_iOS_6_1
#define _iOS_6_1 NSFoundationVersionNumber_iOS_6_1
#endif

//If the symbol for iOS 7 isnt defined, define it.
#ifndef NSFoundationVersionNumber_iOS_7_0
#define NSFoundationVersionNumber_iOS_7_0 1047.00 //extracted from iOS 7 Header
#endif

#ifdef NSFoundationVersionNumber_iOS_7_0
#define _iOS_7_0 NSFoundationVersionNumber_iOS_7_0
#endif

//If the symbol for iOS 7.1 isnt defined, define it.
#ifndef NSFoundationVersionNumber_iOS_7_1
#define NSFoundationVersionNumber_iOS_7_1 1047.25 //extracted from iOS 8 Header
#endif

#ifdef NSFoundationVersionNumber_iOS_7_1
#define _iOS_7_1 NSFoundationVersionNumber_iOS_7_1
#endif

//If the symbol for iOS 8 isnt defined, define it.
#ifndef NSFoundationVersionNumber_iOS_8_0
#define NSFoundationVersionNumber_iOS_8_0 1134.10 //extracted with NSLog(@"%f", NSFoundationVersionNumber)
#endif

#ifdef NSFoundationVersionNumber_iOS_8_0
#define _iOS_8_0 NSFoundationVersionNumber_iOS_8_0
#endif

/**
 Runtime check for the current version Nummer.
 checks ( CURRENT_VERSION_NUMBR == GIVEN_VERSION_NUMBER)
 @_gVersion - the given Version Number. aka (_iOS_7_0 or NSFoundationVersionNumber_iOS_7_0 and so on)
 */
#define SYSTEM_VERSION_EQUAL_TO(_gVersion)                  ( fabs(NSFoundationVersionNumber - _gVersion) < DBL_EPSILON )

/**
 Runtime check for the current version Nummer.
 checks CURRENT_VERSION_NUMBER > GIVEN_VERSION_NUMBER
 @_gVersion - the given Version Number. aka (_iOS_7_0 or NSFoundationVersionNumber_iOS_7_0 and so on)
 */
#define SYSTEM_VERSION_GREATER_THAN(_gVersion)              ( NSFoundationVersionNumber >  _gVersion )

/**
 Runtime check for the current version Nummer.
 checks CURRENT_VERSION_NUMBER >= GIVEN_VERSION_NUMBER
 @_gVersion - the given Version Number. aka (_iOS_7_0 or NSFoundationVersionNumber_iOS_7_0 and so on)
 */
#define SYSTEM_VERSION_GREATER_THAN_OR_EQUAL_TO(_gVersion)  ( NSFoundationVersionNumber > _gVersion || SYSTEM_VERSION_EQUAL_TO(_gVersion) )


/**
 Runtime check for the current version Nummer.
 checks CURRENT_VERSION_NUMBER < GIVEN_VERSION_NUMBER
 @_gVersion - the given Version Number. aka (_iOS_7_0 or NSFoundationVersionNumber_iOS_7_0 and so on)
 */
#define SYSTEM_VERSION_LESS_THAN(_gVersion)                 ( NSFoundationVersionNumber <  _gVersion )


/**
 Runtime check for the current version Nummer.
 checks CURRENT_VERSION_NUMBER <= GIVEN_VERSION_NUMBER
 @_gVersion - the given Version Number. aka (_iOS_7_0 or NSFoundationVersionNumber_iOS_7_0 and so on)
 */
#define SYSTEM_VERSION_LESS_THAN_OR_EQUAL_TO(_gVersion)     ( NSFoundationVersionNumber < _gVersion || SYSTEM_VERSION_EQUAL_TO(_gVersion)  )


///---------------------------
/// @name Singleton Macros
///---------------------------

/**
 Add a Singelton implementation to the .m File
 */
#define CJAMacrosSingletonImplemantion \
+ (instancetype)sharedInstance { \
\
static dispatch_once_t onceToken; \
static id sharedInstance = nil; \
dispatch_once(&onceToken, ^{ \
sharedInstance = [self.class new]; \
}); \
\
return sharedInstance; \
}

/**
 Add a Singelton interface declaration to the .h File
 */
#define CJAMacrosSingletonInterface + (instancetype)sharedInstance;

///---------------------------
/// @name Block Vars
///---------------------------

/**
 Define a weak for an object with a given name.
 */
#define CJAWeakWithNameAndObject(_obj, _name) __weak typeof(_obj) weak##_name = _obj

/**
 Define a weak for a given object.
 */
#define CJAWeak(_obj) CJAWeakWithNameAndObject(_obj, _obj)

/**
 Define a weak self.
 */
#define CJAWeakSelf CJAWeak(self)

/**
 Define a strong for an object with a given name.
 */
#define CJAStrongWithNameAndObject(_obj, _name) __strong typeof(_obj) strong##_name = _obj

/**
 Define a strong for a given object.
 */
#define CJAStrong(_obj) CJAStrongWithNameAndObject(_obj, _obj)

/**
 Define a strong self.
 */
#define CJAStrongSelf CJAStrong(self)

/**
 Typicall isKindOfClass Check
 */
#define CJAIsKindOfClass(_object, _class) [_object isKindOfClass: [_class class]]


///---------------------------
/// @name Float compare
///---------------------------

/**
 Compare two float objects
 */
#define CJAFloatEqual(_first, _second) (fabsf( _first - _second ) < FLT_EPSILON)
