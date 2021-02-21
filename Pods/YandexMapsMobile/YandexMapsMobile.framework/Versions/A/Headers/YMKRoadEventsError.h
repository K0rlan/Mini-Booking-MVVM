#import <YandexMapsMobile/YRTError.h>

/**
 * :nodoc:
 */
typedef NS_ENUM(NSUInteger, YMKRoadEventsRoadEventFailedErrorCode) {
    /**
     * The server returned an error that is not known in the API version you
     * are using.
     */
    YMKRoadEventsRoadEventFailedErrorCodeUnknown,
    /**
     * The user has been banned.
     */
    YMKRoadEventsRoadEventFailedErrorCodeBanned,
    /**
     * The user is too far from the event.
     */
    YMKRoadEventsRoadEventFailedErrorCodeTooFar,
    /**
     * The user is performing certain actions too often. Wait a bit and try
     * again.
     */
    YMKRoadEventsRoadEventFailedErrorCodeTooOften,
    /**
     * Cannot process request because of local laws. For example
     * authorization with a bounded phone number may be required
     */
    YMKRoadEventsRoadEventFailedErrorCodeLegalReasons
};

/**
 * :nodoc:
 */
@interface YMKRoadEventsRoadEventFailedError : YRTError
@property (nonatomic, readonly) YMKRoadEventsRoadEventFailedErrorCode code;
/**
 * Localized error description suitable for end user.
 */
@property (nonatomic, readonly, nonnull) NSString *description;

@end
