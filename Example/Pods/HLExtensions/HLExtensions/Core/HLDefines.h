//
//  HLDefines.h
//  HLPodSpec
//
//  Created by Liang on 2018/1/9.
//

#ifndef HLDefines_h
#define HLDefines_h

#import "RACEXTScope.h"
#import "NSDate+Utilities.h"
#import "NSDictionary+Description.h"
#import "NSArray+Description.h"

#ifdef  DEBUG
#define HLLog(fmt,...) {printf("%s\n", [NSString stringWithFormat:@"%@ - %@", [NSDate date].standardString,  [NSString stringWithFormat:fmt, ##__VA_ARGS__]].UTF8String);}
#else
#define HLLog(...)
#endif

#define HLDefineLazyPropertyInitialization(propertyType, propertyName) \
-(propertyType *)propertyName { \
if (_##propertyName) { \
return _##propertyName; \
} \
_##propertyName = [[propertyType alloc] init]; \
return _##propertyName; \
}

#define HLSafelyCallBlock(block,...) \
if (block) block(__VA_ARGS__);

#define HLSafelyCallBlockAndRelease(block,...) \
if (block) { block(__VA_ARGS__); block = nil;};

#define HLDeclareSingletonMethod(methodName) \
+ (instancetype)methodName;

#define HLSynthesizeSingletonMethod(methodName) \
+ (instancetype)methodName { \
static id _methodName; \
static dispatch_once_t onceToken; \
dispatch_once(&onceToken, ^{\
_methodName = [[self alloc] init]; \
}); \
return _methodName; \
}

#define HLAssociatedButtonWithActionByPassOriginalSender(button, action) \
__weak typeof(self) button##WeakSelf = self; \
[button bk_addEventHandler:^(id sender) { \
__strong typeof(button##WeakSelf) button##StrongSelf = button##WeakSelf; \
HLSafelyCallBlock(button##StrongSelf.action, sender); \
} forControlEvents:UIControlEventTouchUpInside];

#define HLAssociatedButtonWithAction(button, action) \
__weak typeof(self) button##WeakSelf = self; \
[button bk_addEventHandler:^(id sender) { \
__strong typeof(button##WeakSelf) button##StrongSelf = button##WeakSelf; \
HLSafelyCallBlock(button##StrongSelf.action, button##StrongSelf); \
} forControlEvents:UIControlEventTouchUpInside];

#define HLAssociatedViewWithTapAction(view, action) \
__weak typeof(self) view##WeakSelf = self; \
[view bk_whenTapped:^{ \
__strong typeof(view##WeakSelf) view##StrongSelf = view##WeakSelf; \
HLSafelyCallBlock(view##StrongSelf.action, self); \
}];

#define kScreenHeight     [ [ UIScreen mainScreen ] bounds ].size.height
#define kScreenWidth      [ [ UIScreen mainScreen ] bounds ].size.width

typedef void (^HLAction)(id obj);
typedef void (^HLCompletionHandler)(BOOL success, id obj);


#endif /* HLDefines_h */
