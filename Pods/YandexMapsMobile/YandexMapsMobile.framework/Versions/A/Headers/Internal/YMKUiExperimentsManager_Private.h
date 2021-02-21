#import <YandexMapsMobile/YMKUiExperimentsManager.h>
#import <YandexMapsMobile/YRTSubscription.h>

#import <yandex/maps/mapkit/experiments/ui_experiments_manager.h>
#import <yandex/maps/runtime/bindings/ios/to_native.h>
#import <yandex/maps/runtime/bindings/ios/to_platform.h>
#import <yandex/maps/runtime/ios/object.h>

#import <memory>

namespace yandex {
namespace maps {
namespace mapkit {
namespace experiments {
namespace ios {

class UiExperimentsListenerBinding : public ::yandex::maps::mapkit::experiments::UiExperimentsListener {
public:
    explicit UiExperimentsListenerBinding(
        id<YMKUiExperimentsListener> platformListener);

    virtual void onParametersUpdated() override;

    id<YMKUiExperimentsListener> platformReference() const { return platformListener_; }

private:
    __weak id<YMKUiExperimentsListener> platformListener_;
};

} // namespace ios
} // namespace experiments
} // namespace mapkit
} // namespace maps
} // namespace yandex

@interface YMKUiExperimentsManager ()

- (id)initWithWrappedNative:(NSValue *)native;
- (id)initWithNative:(const std::shared_ptr<::yandex::maps::mapkit::experiments::UiExperimentsManager>&)native;

- (std::shared_ptr<::yandex::maps::mapkit::experiments::UiExperimentsManager>)nativeUiExperimentsManager;
- (std::shared_ptr<::yandex::maps::mapkit::experiments::UiExperimentsManager>)native;

@end

namespace yandex {
namespace maps {
namespace runtime {
namespace bindings {
namespace ios {
namespace internal {

template <>
struct ToNative<std::shared_ptr<::yandex::maps::mapkit::experiments::UiExperimentsListener>, id<YMKUiExperimentsListener>, void> {
    static std::shared_ptr<::yandex::maps::mapkit::experiments::UiExperimentsListener> from(
        id<YMKUiExperimentsListener> platformUiExperimentsListener);
};
template <typename PlatformType>
struct ToNative<std::shared_ptr<::yandex::maps::mapkit::experiments::UiExperimentsListener>, PlatformType> {
    static std::shared_ptr<::yandex::maps::mapkit::experiments::UiExperimentsListener> from(
        PlatformType platformUiExperimentsListener)
    {
        return ToNative<std::shared_ptr<::yandex::maps::mapkit::experiments::UiExperimentsListener>, id<YMKUiExperimentsListener>>::from(
            platformUiExperimentsListener);
    }
};

template <>
struct ToPlatform<std::shared_ptr<::yandex::maps::mapkit::experiments::UiExperimentsListener>> {
    static id<YMKUiExperimentsListener> from(
        const std::shared_ptr<::yandex::maps::mapkit::experiments::UiExperimentsListener>& nativeUiExperimentsListener);
};

} // namespace internal
} // namespace ios
} // namespace bindings
} // namespace runtime
} // namespace maps
} // namespace yandex
