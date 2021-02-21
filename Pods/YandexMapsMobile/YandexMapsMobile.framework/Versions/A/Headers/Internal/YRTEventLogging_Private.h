#import <YandexMapsMobile/YRTEventLogging.h>
#import <YandexMapsMobile/YRTSubscription.h>

#import <yandex/maps/runtime/bindings/ios/to_native.h>
#import <yandex/maps/runtime/bindings/ios/to_platform.h>
#import <yandex/maps/runtime/ios/object.h>
#import <yandex/maps/runtime/recording/event_logging.h>

#import <memory>

namespace yandex {
namespace maps {
namespace runtime {
namespace recording {
namespace ios {

class EventListenerBinding : public ::yandex::maps::runtime::recording::EventListener {
public:
    explicit EventListenerBinding(
        id<YRTEventListener> platformListener);

    virtual void onEvent(
        const std::string& event,
        const std::shared_ptr<::yandex::maps::runtime::bindings::StringDictionary<std::string>>& data) override;

    id<YRTEventListener> platformReference() const { return platformListener_; }

private:
    __weak id<YRTEventListener> platformListener_;
};

} // namespace ios
} // namespace recording
} // namespace runtime
} // namespace maps
} // namespace yandex

@interface YRTEventLogging ()

- (id)initWithWrappedNative:(NSValue *)native;
- (id)initWithNative:(const std::shared_ptr<::yandex::maps::runtime::recording::EventLogging>&)native;

- (std::shared_ptr<::yandex::maps::runtime::recording::EventLogging>)nativeEventLogging;
- (std::shared_ptr<::yandex::maps::runtime::recording::EventLogging>)native;

@end



namespace yandex {
namespace maps {
namespace runtime {
namespace bindings {
namespace ios {
namespace internal {

template <>
struct ToNative<std::shared_ptr<::yandex::maps::runtime::recording::EventListener>, id<YRTEventListener>, void> {
    static std::shared_ptr<::yandex::maps::runtime::recording::EventListener> from(
        id<YRTEventListener> platformEventListener);
};
template <typename PlatformType>
struct ToNative<std::shared_ptr<::yandex::maps::runtime::recording::EventListener>, PlatformType> {
    static std::shared_ptr<::yandex::maps::runtime::recording::EventListener> from(
        PlatformType platformEventListener)
    {
        return ToNative<std::shared_ptr<::yandex::maps::runtime::recording::EventListener>, id<YRTEventListener>>::from(
            platformEventListener);
    }
};

template <>
struct ToPlatform<std::shared_ptr<::yandex::maps::runtime::recording::EventListener>> {
    static id<YRTEventListener> from(
        const std::shared_ptr<::yandex::maps::runtime::recording::EventListener>& nativeEventListener);
};

} // namespace internal
} // namespace ios
} // namespace bindings
} // namespace runtime
} // namespace maps
} // namespace yandex
