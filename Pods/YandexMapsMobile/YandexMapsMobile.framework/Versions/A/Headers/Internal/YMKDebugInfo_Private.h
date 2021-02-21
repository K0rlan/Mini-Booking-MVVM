#import <YandexMapsMobile/YMKDebugInfo.h>

#import <yandex/maps/mapkit/map/debug_info.h>
#import <yandex/maps/runtime/bindings/ios/to_native.h>
#import <yandex/maps/runtime/bindings/ios/to_platform.h>

namespace yandex {
namespace maps {
namespace runtime {
namespace bindings {
namespace ios {
namespace internal {

template <>
struct ToNative<::yandex::maps::mapkit::map::DebugInfo, YMKDebugInfo, void> {
    static ::yandex::maps::mapkit::map::DebugInfo from(
        YMKDebugInfo* platformDebugInfo);
};

template <typename PlatformType>
struct ToNative<::yandex::maps::mapkit::map::DebugInfo, PlatformType,
        typename std::enable_if<
            std::is_convertible<PlatformType, YMKDebugInfo*>::value>::type> {
    static ::yandex::maps::mapkit::map::DebugInfo from(
        PlatformType platformDebugInfo)
    {
        return ToNative<::yandex::maps::mapkit::map::DebugInfo, YMKDebugInfo>::from(
            platformDebugInfo);
    }
};

template <>
struct ToPlatform<::yandex::maps::mapkit::map::DebugInfo> {
    static YMKDebugInfo* from(
        const ::yandex::maps::mapkit::map::DebugInfo& debugInfo);
};

} // namespace internal
} // namespace ios
} // namespace bindings
} // namespace runtime
} // namespace maps
} // namespace yandex
