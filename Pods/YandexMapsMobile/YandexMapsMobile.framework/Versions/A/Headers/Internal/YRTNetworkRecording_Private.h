#import <YandexMapsMobile/YRTNetworkRecording.h>

#import <yandex/maps/runtime/network/internal/network_recording.h>

#import <memory>

namespace yandex {
namespace maps {
namespace runtime {
namespace network {
namespace internal {
namespace ios {

OnSuccess onSuccess(
    YRTFileOperationsListener handler);
OnError onError(
    YRTFileOperationsListener handler);

} // namespace ios
} // namespace internal
} // namespace network
} // namespace runtime
} // namespace maps
} // namespace yandex

@interface YRTNetworkRecorder ()

- (id)initWithWrappedNative:(NSValue *)native;
- (id)initWithNative:(const std::shared_ptr<::yandex::maps::runtime::network::internal::NetworkRecorder>&)native;

- (std::shared_ptr<::yandex::maps::runtime::network::internal::NetworkRecorder>)nativeNetworkRecorder;
- (std::shared_ptr<::yandex::maps::runtime::network::internal::NetworkRecorder>)native;

@end

@interface YRTNetworkPlayer ()

- (id)initWithWrappedNative:(NSValue *)native;
- (id)initWithNative:(const std::shared_ptr<::yandex::maps::runtime::network::internal::NetworkPlayer>&)native;

- (std::shared_ptr<::yandex::maps::runtime::network::internal::NetworkPlayer>)nativeNetworkPlayer;
- (std::shared_ptr<::yandex::maps::runtime::network::internal::NetworkPlayer>)native;

@end


