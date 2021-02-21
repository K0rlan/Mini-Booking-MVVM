#import <YandexMapsMobile/YMKLocationSimulator.h>
#import <YandexMapsMobile/YRTSubscription.h>

#import <yandex/maps/mapkit/location/location_simulator.h>
#import <yandex/maps/runtime/bindings/ios/to_native.h>
#import <yandex/maps/runtime/bindings/ios/to_platform.h>
#import <yandex/maps/runtime/ios/object.h>

#import <memory>

namespace yandex {
namespace maps {
namespace mapkit {
namespace location {
namespace ios {

class LocationSimulatorListenerBinding : public ::yandex::maps::mapkit::location::LocationSimulatorListener {
public:
    explicit LocationSimulatorListenerBinding(
        id<YMKLocationSimulatorListener> platformListener);

    virtual void onSimulationFinished() override;

    id<YMKLocationSimulatorListener> platformReference() const { return platformListener_; }

private:
    __weak id<YMKLocationSimulatorListener> platformListener_;
};

} // namespace ios
} // namespace location
} // namespace mapkit
} // namespace maps
} // namespace yandex

@interface YMKLocationSimulator ()

- (id)initWithWrappedNative:(NSValue *)native;
- (id)initWithNative:(const std::shared_ptr<::yandex::maps::mapkit::location::LocationSimulator>&)native;

- (std::shared_ptr<::yandex::maps::mapkit::location::LocationSimulator>)nativeLocationSimulator;

@end

namespace yandex {
namespace maps {
namespace runtime {
namespace bindings {
namespace ios {
namespace internal {

template <>
struct ToNative<std::shared_ptr<::yandex::maps::mapkit::location::LocationSimulatorListener>, id<YMKLocationSimulatorListener>, void> {
    static std::shared_ptr<::yandex::maps::mapkit::location::LocationSimulatorListener> from(
        id<YMKLocationSimulatorListener> platformLocationSimulatorListener);
};
template <typename PlatformType>
struct ToNative<std::shared_ptr<::yandex::maps::mapkit::location::LocationSimulatorListener>, PlatformType> {
    static std::shared_ptr<::yandex::maps::mapkit::location::LocationSimulatorListener> from(
        PlatformType platformLocationSimulatorListener)
    {
        return ToNative<std::shared_ptr<::yandex::maps::mapkit::location::LocationSimulatorListener>, id<YMKLocationSimulatorListener>>::from(
            platformLocationSimulatorListener);
    }
};

template <>
struct ToPlatform<std::shared_ptr<::yandex::maps::mapkit::location::LocationSimulatorListener>> {
    static id<YMKLocationSimulatorListener> from(
        const std::shared_ptr<::yandex::maps::mapkit::location::LocationSimulatorListener>& nativeLocationSimulatorListener);
};

} // namespace internal
} // namespace ios
} // namespace bindings
} // namespace runtime
} // namespace maps
} // namespace yandex
