#import <Foundation/Foundation.h>

@class YRTTokenDelegate;

/**
 * :nodoc:
 */
@protocol YRTAccount <NSObject>

/**
 * Get the user's UID
 */
- (nonnull NSString *)uid;

/**
 * Makes a token request for the provider. See @{TokenListener} for
 * additional information.
 */
- (void)requestTokenWithTokenListener:(nonnull YRTTokenDelegate *)tokenListener;

/**
 * Invalidates the OAuth token for an active account. The next token
 * request occurs on a new OAuth token request from XToken.
 */
- (void)invalidateToken:(nonnull NSString *)token;

/**
 * Creates the HTTP authorization header for requests. return null if
 * default authorization needed ('OAuth token').
 */
- (nullable NSString *)httpAuthWithToken:(nonnull NSString *)token;

@end

/**
 * :nodoc:
 */
@interface YRTTokenDelegate : NSObject

/**
 * Token was received.
 */
- (void)onTokenReceivedWithToken:(nonnull NSString *)token;

/**
 * XToken is not valid anymore. Password must be re-entered.
 *
 * @param data Contains platform-specific data for user input.
 */
- (void)onPasswordRequiredWithData:(nonnull id)data;

/**
 * An error occurred during OAuth token refresh (it might be a network
 * error or an invalid response from the authentication server).
 */
- (void)onTokenRefreshFailedWithMessage:(nonnull NSString *)message;

@end
