#import <Foundation/Foundation.h>

/**
 * :nodoc:
 */
typedef void(^YMKCoverageIsCoveredSessionResponseHandler)(
    BOOL isCovered,
    NSError * _Nullable error);

/**
 * :nodoc:
 * Allows to repeat or cancel the request in Coverage.
 */
@interface YMKCoverageIsCoveredSession : NSObject

/**
 * Repeats the specified request with the same parameters.
 */
- (void)retryWithResponseHandler:(nonnull YMKCoverageIsCoveredSessionResponseHandler)responseHandler;

/**
 * Cancels the request.
 */
- (void)cancel;

@end
