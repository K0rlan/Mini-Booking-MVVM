#import <Foundation/Foundation.h>

@class YRTNetworkPlayer;
@class YRTNetworkRecorder;

typedef void(^YRTFileOperationsListener)(
    NSError * _Nullable error);

/**
 * :nodoc:
 * Allows to record network requests.
 */
@interface YRTNetworkRecorder : NSObject

- (void)start;

- (void)stop;

- (void)dumpWithFilepath:(nonnull NSString *)filepath
  fileOperationsListener:(nonnull YRTFileOperationsListener)fileOperationsListener;

/**
 * Tells if this object is valid or no. Any method called on an invalid
 * object will throw an exception. The object becomes invalid only on UI
 * thread, and only when its implementation depends on objects already
 * destroyed by now. Please refer to general docs about the interface for
 * details on its invalidation.
 */
@property (nonatomic, readonly, getter=isValid) BOOL valid;

@end

/**
 * :nodoc:
 * Allows to play records from YRTNetworkRecorder.
 */
@interface YRTNetworkPlayer : NSObject

- (void)playWithFilepath:(nonnull NSString *)filepath
  fileOperationsListener:(nonnull YRTFileOperationsListener)fileOperationsListener;

- (void)stop;

/**
 * Tells if this object is valid or no. Any method called on an invalid
 * object will throw an exception. The object becomes invalid only on UI
 * thread, and only when its implementation depends on objects already
 * destroyed by now. Please refer to general docs about the interface for
 * details on its invalidation.
 */
@property (nonatomic, readonly, getter=isValid) BOOL valid;

@end

@interface YRTNetworkRecording : NSObject

/**
 * :nodoc:
 */
+ (nullable YRTNetworkRecorder *)createRecorder;

/**
 * :nodoc:
 */
+ (nullable YRTNetworkPlayer *)createPlayer;

@end

