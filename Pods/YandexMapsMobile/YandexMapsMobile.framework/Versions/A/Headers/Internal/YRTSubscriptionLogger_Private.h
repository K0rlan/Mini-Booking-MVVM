#import <YandexMapsMobile/YRTSubscription.h>
#import <YandexMapsMobile/YRTSubscriptionLogger.h>

#import <yandex/maps/runtime/bindings/ios/to_native.h>
#import <yandex/maps/runtime/bindings/ios/to_platform.h>
#import <yandex/maps/runtime/ios/object.h>
#import <yandex/maps/runtime/logging/subscription_logger.h>

#import <memory>

namespace yandex {
namespace maps {
namespace runtime {
namespace logging {
namespace ios {

class LogListenerBinding : public ::yandex::maps::runtime::logging::LogListener {
public:
    explicit LogListenerBinding(
        id<YRTLogListener> platformListener);

    virtual void onMessageRecieved(
        const ::yandex::maps::runtime::logging::LogMessage& message) override;

    id<YRTLogListener> platformReference() const { return platformListener_; }

private:
    __weak id<YRTLogListener> platformListener_;
};

} // namespace ios
} // namespace logging
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
struct ToNative<::yandex::maps::runtime::logging::LogMessage, YRTLogMessage, void> {
    static ::yandex::maps::runtime::logging::LogMessage from(
        YRTLogMessage* platformLogMessage);
};

template <typename PlatformType>
struct ToNative<::yandex::maps::runtime::logging::LogMessage, PlatformType,
        typename std::enable_if<
            std::is_convertible<PlatformType, YRTLogMessage*>::value>::type> {
    static ::yandex::maps::runtime::logging::LogMessage from(
        PlatformType platformLogMessage)
    {
        return ToNative<::yandex::maps::runtime::logging::LogMessage, YRTLogMessage>::from(
            platformLogMessage);
    }
};

template <>
struct ToPlatform<::yandex::maps::runtime::logging::LogMessage> {
    static YRTLogMessage* from(
        const ::yandex::maps::runtime::logging::LogMessage& logMessage);
};

} // namespace internal
} // namespace ios
} // namespace bindings
} // namespace runtime
} // namespace maps
} // namespace yandex

@interface YRTLogging ()

- (id)initWithWrappedNative:(NSValue *)native;
- (id)initWithNative:(const std::shared_ptr<::yandex::maps::runtime::logging::Logging>&)native;

- (std::shared_ptr<::yandex::maps::runtime::logging::Logging>)nativeLogging;
- (std::shared_ptr<::yandex::maps::runtime::logging::Logging>)native;

@end



namespace yandex {
namespace maps {
namespace runtime {
namespace bindings {
namespace ios {
namespace internal {

template <>
struct ToNative<std::shared_ptr<::yandex::maps::runtime::logging::LogListener>, id<YRTLogListener>, void> {
    static std::shared_ptr<::yandex::maps::runtime::logging::LogListener> from(
        id<YRTLogListener> platformLogListener);
};
template <typename PlatformType>
struct ToNative<std::shared_ptr<::yandex::maps::runtime::logging::LogListener>, PlatformType> {
    static std::shared_ptr<::yandex::maps::runtime::logging::LogListener> from(
        PlatformType platformLogListener)
    {
        return ToNative<std::shared_ptr<::yandex::maps::runtime::logging::LogListener>, id<YRTLogListener>>::from(
            platformLogListener);
    }
};

template <>
struct ToPlatform<std::shared_ptr<::yandex::maps::runtime::logging::LogListener>> {
    static id<YRTLogListener> from(
        const std::shared_ptr<::yandex::maps::runtime::logging::LogListener>& nativeLogListener);
};

} // namespace internal
} // namespace ios
} // namespace bindings
} // namespace runtime
} // namespace maps
} // namespace yandex
