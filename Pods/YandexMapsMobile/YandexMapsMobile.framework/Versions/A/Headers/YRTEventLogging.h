#import <Foundation/Foundation.h>

@class YRTEventLogging;

/**
 * :nodoc:
 */
typedef NS_ENUM(NSUInteger, YRTLoggingLevel) {
    YRTLoggingLevelNormal,
    YRTLoggingLevelVerbose
};

/**
 * :nodoc:
 */
@protocol YRTEventListener <NSObject>

- (void)onEventWithEvent:(nonnull NSString *)event
                    data:(nonnull NSDictionary<NSString *, NSString *> *)data;

@end

/**
 * :nodoc:
 */
@interface YRTEventLogging : NSObject

/**
 * Subscribes to events with LoggingLevel.Normal
 */
- (void)subscribeWithEventListener:(nonnull id<YRTEventListener>)eventListener;

/**
 * Subscribes to events with the given level
 */
- (void)subscribeWithEventListener:(nonnull id<YRTEventListener>)eventListener
                             level:(YRTLoggingLevel)level;

- (void)unsubscribeWithEventListener:(nonnull id<YRTEventListener>)eventListener;

/**
 * Tells if this object is valid or no. Any method called on an invalid
 * object will throw an exception. The object becomes invalid only on UI
 * thread, and only when its implementation depends on objects already
 * destroyed by now. Please refer to general docs about the interface for
 * details on its invalidation.
 */
@property (nonatomic, readonly, getter=isValid) BOOL valid;

@end

@interface YRTEventLoggingFactory : NSObject

/**
 * :nodoc:
 */
+ (nonnull YRTEventLogging *)getEventLogging;

@end

