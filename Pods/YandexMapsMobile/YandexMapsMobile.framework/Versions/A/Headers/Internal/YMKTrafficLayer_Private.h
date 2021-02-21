#import <YandexMapsMobile/YMKTrafficLayer.h>
#import <YandexMapsMobile/YRTSubscription.h>

#import <yandex/maps/mapkit/traffic/traffic_layer.h>
#import <yandex/maps/runtime/ios/object.h>

#import <memory>

@interface YMKTrafficLayer ()

- (id)initWithWrappedNative:(NSValue *)native;
- (id)initWithNative:(const std::shared_ptr<::yandex::maps::mapkit::traffic::TrafficLayer>&)native;

- (std::shared_ptr<::yandex::maps::mapkit::traffic::TrafficLayer>)nativeTrafficLayer;
- (std::shared_ptr<::yandex::maps::mapkit::traffic::TrafficLayer>)native;

@end
