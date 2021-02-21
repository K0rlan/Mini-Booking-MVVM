#import <YandexMapsMobile/YRTError.h>

/**
 * :nodoc:
 * The XToken is not valid anymore. The password must be re-entered.
 */
@interface YRTAuthPasswordRequiredError : YRTError
@property (nonatomic, readonly, nonnull) id data;

@end

/**
 * :nodoc:
 * User is not authenticated
 */
@interface YRTAuthAuthRequiredError : YRTError

@end
