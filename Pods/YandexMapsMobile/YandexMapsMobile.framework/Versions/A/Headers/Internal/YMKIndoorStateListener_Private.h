#import <YandexMapsMobile/YMKIndoorStateListener.h>

#import <yandex/maps/mapkit/indoor/indoor_state_listener.h>
#import <yandex/maps/runtime/bindings/ios/to_native.h>
#import <yandex/maps/runtime/bindings/ios/to_platform.h>

namespace yandex {
namespace maps {
namespace mapkit {
namespace indoor {
namespace ios {

class IndoorStateListenerBinding : public ::yandex::maps::mapkit::indoor::IndoorStateListener {
public:
    explicit IndoorStateListenerBinding(
        id<YMKIndoorStateListener> platformListener);

    virtual void onActivePlanFocused(
        std::shared_ptr<::yandex::maps::mapkit::indoor::IndoorPlan>& activePlan) override;

    virtual void onActivePlanLeft() override;

    virtual void onActiveLevelChanged(
        const std::string& activeLevelId) override;

    id<YMKIndoorStateListener> platformReference() const { return platformListener_; }

private:
    __weak id<YMKIndoorStateListener> platformListener_;
};

} // namespace ios
} // namespace indoor
} // namespace mapkit
} // namespace maps
} // namespace yandex

namespace yandex {
namespace maps {
namespace runtime {
namespace bindings {
namespace ios {
namespace internal {

template <>
struct ToNative<std::shared_ptr<::yandex::maps::mapkit::indoor::IndoorStateListener>, id<YMKIndoorStateListener>, void> {
    static std::shared_ptr<::yandex::maps::mapkit::indoor::IndoorStateListener> from(
        id<YMKIndoorStateListener> platformIndoorStateListener);
};
template <typename PlatformType>
struct ToNative<std::shared_ptr<::yandex::maps::mapkit::indoor::IndoorStateListener>, PlatformType> {
    static std::shared_ptr<::yandex::maps::mapkit::indoor::IndoorStateListener> from(
        PlatformType platformIndoorStateListener)
    {
        return ToNative<std::shared_ptr<::yandex::maps::mapkit::indoor::IndoorStateListener>, id<YMKIndoorStateListener>>::from(
            platformIndoorStateListener);
    }
};

template <>
struct ToPlatform<std::shared_ptr<::yandex::maps::mapkit::indoor::IndoorStateListener>> {
    static id<YMKIndoorStateListener> from(
        const std::shared_ptr<::yandex::maps::mapkit::indoor::IndoorStateListener>& nativeIndoorStateListener);
};

} // namespace internal
} // namespace ios
} // namespace bindings
} // namespace runtime
} // namespace maps
} // namespace yandex
