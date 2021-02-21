#import <Foundation/Foundation.h>

@class YRTLogMessage;
@class YRTLogging;

/**
 * :nodoc:
 */
@protocol YRTLogListener <NSObject>

- (void)onMessageRecievedWithMessage:(nonnull YRTLogMessage *)message;

@end

/**
 * :nodoc:
 */
typedef NS_ENUM(NSUInteger, YRTLogMessageLogLevel) {
    YRTLogMessageLogLevelError,
    YRTLogMessageLogLevelWarning,
    YRTLogMessageLogLevelInfo,
    YRTLogMessageLogLevelDebug
};

/**
 * :nodoc:
 */
@interface YRTLogMessage : NSObject

@property (nonatomic, readonly, nonnull) NSDate *time;

@property (nonatomic, readonly) YRTLogMessageLogLevel level;

@property (nonatomic, readonly, nonnull) NSString *scope;

@property (nonatomic, readonly, nonnull) NSString *message;

@property (nonatomic, readonly, nonnull) NSString *verboseInfo;


+ (nonnull YRTLogMessage *)logMessageWithTime:(nonnull NSDate *)time
                                        level:( YRTLogMessageLogLevel)level
                                        scope:(nonnull NSString *)scope
                                      message:(nonnull NSString *)message
                                  verboseInfo:(nonnull NSString *)verboseInfo;


@end

/**
 * :nodoc:
 */
@interface YRTLogging : NSObject

- (void)subscribeWithLogListener:(nonnull id<YRTLogListener>)logListener;

- (void)unsubscribeWithLogListener:(nonnull id<YRTLogListener>)logListener;

/**
 * Tells if this object is valid or no. Any method called on an invalid
 * object will throw an exception. The object becomes invalid only on UI
 * thread, and only when its implementation depends on objects already
 * destroyed by now. Please refer to general docs about the interface for
 * details on its invalidation.
 */
@property (nonatomic, readonly, getter=isValid) BOOL valid;

@end

/// :nodoc:
@interface YRTLoggingFactory : NSObject

+ (nonnull YRTLogging *)getLogging;

@end

