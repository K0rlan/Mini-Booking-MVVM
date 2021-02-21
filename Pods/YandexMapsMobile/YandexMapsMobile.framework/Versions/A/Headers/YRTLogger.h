#import <Foundation/Foundation.h>

/// :nodoc:
@interface YRTLogger : NSObject

+ (void)errorWithStr:(nonnull NSString *)str;

+ (void)warnWithStr:(nonnull NSString *)str;

+ (void)infoWithStr:(nonnull NSString *)str;

+ (void)debugWithStr:(nonnull NSString *)str;

@end

