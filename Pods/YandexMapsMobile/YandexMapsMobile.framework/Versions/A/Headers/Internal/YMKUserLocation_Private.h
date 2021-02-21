#import <YandexMapsMobile/YMKUserLocation.h>
#import <YandexMapsMobile/YRTSubscription.h>

#import <yandex/maps/mapkit/user_location/user_location.h>
#import <yandex/maps/runtime/bindings/ios/to_native.h>
#import <yandex/maps/runtime/bindings/ios/to_platform.h>
#import <yandex/maps/runtime/ios/object.h>

#import <memory>

namespace yandex {
namespace maps {
namespace mapkit {
namespace user_location {
namespace ios {

class UserLocationObjectListenerBinding : public ::yandex::maps::mapkit::user_location::UserLocationObjectListener {
public:
    explicit UserLocationObjectListenerBinding(
        id<YMKUserLocationObjectListener> platformListener);

    virtual void onObjectAdded(
        ::yandex::maps::mapkit::user_location::UserLocationView* view) override;

    virtual void onObjectRemoved(
        ::yandex::maps::mapkit::user_location::UserLocationView* view) override;

    virtual void onObjectUpdated(
        ::yandex::maps::mapkit::user_location::UserLocationView* view,
        ::yandex::maps::mapkit::layers::ObjectEvent* event) override;

    id<YMKUserLocationObjectListener> platformReference() const { return platformListener_; }

private:
    __weak id<YMKUserLocationObjectListener> platformListener_;
};

class UserLocationTapListenerBinding : public ::yandex::maps::mapkit::user_location::UserLocationTapListener {
public:
    explicit UserLocationTapListenerBinding(
        id<YMKUserLocationTapListener> platformListener);

    virtual void onUserLocationObjectTap(
        const ::yandex::maps::mapkit::geometry::Point& point) override;

    id<YMKUserLocationTapListener> platformReference() const { return platformListener_; }

private:
    __weak id<YMKUserLocationTapListener> platformListener_;
};

} // namespace ios
} // namespace user_location
} // namespace mapkit
} // namespace maps
} // namespace yandex

@interface YMKUserLocationView ()

- (id)initWithWrappedNative:(NSValue *)native;
- (id)initWithNative:(const std::shared_ptr<::yandex::maps::mapkit::user_location::UserLocationView>&)native;

- (std::shared_ptr<::yandex::maps::mapkit::user_location::UserLocationView>)nativeUserLocationView;
- (std::shared_ptr<::yandex::maps::mapkit::user_location::UserLocationView>)native;

@end

@interface YMKUserLocationIconChanged ()

- (id)initWithWrappedNative:(NSValue *)native;
- (id)initWithNative:(const std::shared_ptr<::yandex::maps::mapkit::user_location::UserLocationIconChanged>&)native;

- (std::shared_ptr<::yandex::maps::mapkit::user_location::UserLocationIconChanged>)nativeUserLocationIconChanged;

@end

@interface YMKUserLocationAnchorChanged ()

- (id)initWithWrappedNative:(NSValue *)native;
- (id)initWithNative:(const std::shared_ptr<::yandex::maps::mapkit::user_location::UserLocationAnchorChanged>&)native;

- (std::shared_ptr<::yandex::maps::mapkit::user_location::UserLocationAnchorChanged>)nativeUserLocationAnchorChanged;

@end

@interface YMKUserLocationLayer ()

- (id)initWithWrappedNative:(NSValue *)native;
- (id)initWithNative:(const std::shared_ptr<::yandex::maps::mapkit::user_location::UserLocationLayer>&)native;

- (std::shared_ptr<::yandex::maps::mapkit::user_location::UserLocationLayer>)nativeUserLocationLayer;
- (std::shared_ptr<::yandex::maps::mapkit::user_location::UserLocationLayer>)native;

@end

namespace yandex {
namespace maps {
namespace runtime {
namespace bindings {
namespace ios {
namespace internal {

template <>
struct ToNative<std::shared_ptr<::yandex::maps::mapkit::user_location::UserLocationObjectListener>, id<YMKUserLocationObjectListener>, void> {
    static std::shared_ptr<::yandex::maps::mapkit::user_location::UserLocationObjectListener> from(
        id<YMKUserLocationObjectListener> platformUserLocationObjectListener);
};
template <typename PlatformType>
struct ToNative<std::shared_ptr<::yandex::maps::mapkit::user_location::UserLocationObjectListener>, PlatformType> {
    static std::shared_ptr<::yandex::maps::mapkit::user_location::UserLocationObjectListener> from(
        PlatformType platformUserLocationObjectListener)
    {
        return ToNative<std::shared_ptr<::yandex::maps::mapkit::user_location::UserLocationObjectListener>, id<YMKUserLocationObjectListener>>::from(
            platformUserLocationObjectListener);
    }
};

template <>
struct ToPlatform<std::shared_ptr<::yandex::maps::mapkit::user_location::UserLocationObjectListener>> {
    static id<YMKUserLocationObjectListener> from(
        const std::shared_ptr<::yandex::maps::mapkit::user_location::UserLocationObjectListener>& nativeUserLocationObjectListener);
};

} // namespace internal
} // namespace ios
} // namespace bindings
} // namespace runtime
} // namespace maps
} // namespace yandex

namespace yandex {
namespace maps {
namespace runtime {
namespace bindings {
namespace ios {
namespace internal {

template <>
struct ToNative<std::shared_ptr<::yandex::maps::mapkit::user_location::UserLocationTapListener>, id<YMKUserLocationTapListener>, void> {
    static std::shared_ptr<::yandex::maps::mapkit::user_location::UserLocationTapListener> from(
        id<YMKUserLocationTapListener> platformUserLocationTapListener);
};
template <typename PlatformType>
struct ToNative<std::shared_ptr<::yandex::maps::mapkit::user_location::UserLocationTapListener>, PlatformType> {
    static std::shared_ptr<::yandex::maps::mapkit::user_location::UserLocationTapListener> from(
        PlatformType platformUserLocationTapListener)
    {
        return ToNative<std::shared_ptr<::yandex::maps::mapkit::user_location::UserLocationTapListener>, id<YMKUserLocationTapListener>>::from(
            platformUserLocationTapListener);
    }
};

template <>
struct ToPlatform<std::shared_ptr<::yandex::maps::mapkit::user_location::UserLocationTapListener>> {
    static id<YMKUserLocationTapListener> from(
        const std::shared_ptr<::yandex::maps::mapkit::user_location::UserLocationTapListener>& nativeUserLocationTapListener);
};

} // namespace internal
} // namespace ios
} // namespace bindings
} // namespace runtime
} // namespace maps
} // namespace yandex
