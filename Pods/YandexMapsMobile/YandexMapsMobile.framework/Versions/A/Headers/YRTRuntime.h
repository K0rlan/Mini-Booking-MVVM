#import <Foundation/Foundation.h>

/**
 * :nodoc:
 */
typedef void(^YRTFailedAssertionListener)(
    NSString * _Nonnull file,
    NSInteger line,
    NSString * _Nonnull condition,
    NSString * _Nonnull message,
    NSArray<NSString *> * _Nonnull stack);

/// :nodoc:
@interface YRTRuntime : NSObject

+ (nonnull NSString *)version;

+ (void)setFailedAssertionListener:(nonnull YRTFailedAssertionListener)failedAssertionListener;

@end

