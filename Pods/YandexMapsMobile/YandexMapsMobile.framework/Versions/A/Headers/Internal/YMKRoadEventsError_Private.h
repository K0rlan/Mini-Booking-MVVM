#import <YandexMapsMobile/YMKRoadEventsError.h>

#import <yandex/maps/mapkit/road_events/error.h>

#import <memory>

@interface YMKRoadEventsRoadEventFailedError ()

- (id)initWithWrappedNative:(NSValue *)native;
- (id)initWithNative:(const std::shared_ptr<::yandex::maps::mapkit::road_events::RoadEventFailedError>&)native;

- (std::shared_ptr<::yandex::maps::mapkit::road_events::RoadEventFailedError>)nativeRoadEventFailedError;

@end
