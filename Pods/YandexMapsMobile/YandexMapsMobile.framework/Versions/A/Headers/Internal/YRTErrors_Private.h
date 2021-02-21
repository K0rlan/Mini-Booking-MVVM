#import <YandexMapsMobile/YRTErrors.h>

#import <yandex/maps/runtime/network/errors.h>

#import <memory>

@interface YRTRemoteError ()

- (id)initWithWrappedNative:(NSValue *)native;
- (id)initWithNative:(const std::shared_ptr<::yandex::maps::runtime::network::RemoteError>&)native;

- (std::shared_ptr<::yandex::maps::runtime::network::RemoteError>)nativeRemoteError;

@end

@interface YRTBadRequestError ()

- (id)initWithWrappedNative:(NSValue *)native;
- (id)initWithNative:(const std::shared_ptr<::yandex::maps::runtime::network::BadRequestError>&)native;

- (std::shared_ptr<::yandex::maps::runtime::network::BadRequestError>)nativeBadRequestError;

@end

@interface YRTNotFoundError ()

- (id)initWithWrappedNative:(NSValue *)native;
- (id)initWithNative:(const std::shared_ptr<::yandex::maps::runtime::network::NotFoundError>&)native;

- (std::shared_ptr<::yandex::maps::runtime::network::NotFoundError>)nativeNotFoundError;

@end

@interface YRTRequestEntityTooLargeError ()

- (id)initWithWrappedNative:(NSValue *)native;
- (id)initWithNative:(const std::shared_ptr<::yandex::maps::runtime::network::RequestEntityTooLargeError>&)native;

- (std::shared_ptr<::yandex::maps::runtime::network::RequestEntityTooLargeError>)nativeRequestEntityTooLargeError;

@end

@interface YRTForbiddenError ()

- (id)initWithWrappedNative:(NSValue *)native;
- (id)initWithNative:(const std::shared_ptr<::yandex::maps::runtime::network::ForbiddenError>&)native;

- (std::shared_ptr<::yandex::maps::runtime::network::ForbiddenError>)nativeForbiddenError;

@end

@interface YRTUnauthorizedError ()

- (id)initWithWrappedNative:(NSValue *)native;
- (id)initWithNative:(const std::shared_ptr<::yandex::maps::runtime::network::UnauthorizedError>&)native;

- (std::shared_ptr<::yandex::maps::runtime::network::UnauthorizedError>)nativeUnauthorizedError;

@end

@interface YRTNetworkError ()

- (id)initWithWrappedNative:(NSValue *)native;
- (id)initWithNative:(const std::shared_ptr<::yandex::maps::runtime::network::NetworkError>&)native;

- (std::shared_ptr<::yandex::maps::runtime::network::NetworkError>)nativeNetworkError;

@end
