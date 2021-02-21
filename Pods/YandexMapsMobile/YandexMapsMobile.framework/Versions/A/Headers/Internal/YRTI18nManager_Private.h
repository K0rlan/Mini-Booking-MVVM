#import <YandexMapsMobile/YRTI18nManager.h>

#import <yandex/maps/runtime/bindings/ios/to_native.h>
#import <yandex/maps/runtime/bindings/ios/to_platform.h>
#import <yandex/maps/runtime/i18n/i18n_manager.h>

#import <memory>

namespace yandex {
namespace maps {
namespace runtime {
namespace i18n {
namespace ios {

OnLocaleReceived onLocaleReceived(
    YRTLocaleDelegate handler);

} // namespace ios
} // namespace i18n
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
struct ToNative<::yandex::maps::runtime::i18n::CanonicalUnit, YRTCanonicalUnit, void> {
    static ::yandex::maps::runtime::i18n::CanonicalUnit from(
        YRTCanonicalUnit* platformCanonicalUnit);
};

template <typename PlatformType>
struct ToNative<::yandex::maps::runtime::i18n::CanonicalUnit, PlatformType,
        typename std::enable_if<
            std::is_convertible<PlatformType, YRTCanonicalUnit*>::value>::type> {
    static ::yandex::maps::runtime::i18n::CanonicalUnit from(
        PlatformType platformCanonicalUnit)
    {
        return ToNative<::yandex::maps::runtime::i18n::CanonicalUnit, YRTCanonicalUnit>::from(
            platformCanonicalUnit);
    }
};

template <>
struct ToPlatform<::yandex::maps::runtime::i18n::CanonicalUnit> {
    static YRTCanonicalUnit* from(
        const ::yandex::maps::runtime::i18n::CanonicalUnit& canonicalUnit);
};

} // namespace internal
} // namespace ios
} // namespace bindings
} // namespace runtime
} // namespace maps
} // namespace yandex

@interface YRTI18nManager ()

- (id)initWithWrappedNative:(NSValue *)native;
- (id)initWithNative:(const std::shared_ptr<::yandex::maps::runtime::i18n::I18nManager>&)native;

- (std::shared_ptr<::yandex::maps::runtime::i18n::I18nManager>)nativeI18nManager;
- (std::shared_ptr<::yandex::maps::runtime::i18n::I18nManager>)native;

@end


