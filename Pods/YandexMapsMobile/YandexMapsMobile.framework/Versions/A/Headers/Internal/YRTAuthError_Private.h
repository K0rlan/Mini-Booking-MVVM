#import <YandexMapsMobile/YRTAuthError.h>

#import <yandex/maps/runtime/auth/error.h>

#import <memory>

@interface YRTAuthPasswordRequiredError ()

- (id)initWithWrappedNative:(NSValue *)native;
- (id)initWithNative:(const std::shared_ptr<::yandex::maps::runtime::auth::PasswordRequiredError>&)native;

- (std::shared_ptr<::yandex::maps::runtime::auth::PasswordRequiredError>)nativePasswordRequiredError;

@end

@interface YRTAuthAuthRequiredError ()

- (id)initWithWrappedNative:(NSValue *)native;
- (id)initWithNative:(const std::shared_ptr<::yandex::maps::runtime::auth::AuthRequiredError>&)native;

- (std::shared_ptr<::yandex::maps::runtime::auth::AuthRequiredError>)nativeAuthRequiredError;

@end
