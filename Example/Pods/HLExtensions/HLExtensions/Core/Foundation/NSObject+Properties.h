//
//  NSObject+Properties.h
//  HLPodSpec
//
//  Created by Liang on 2018/1/9.
//

#import <Foundation/Foundation.h>

@interface NSObject (Properties)

+ (NSArray *)propertiesOfClass:(Class)cls;
- (NSArray *)allProperties;

@end
