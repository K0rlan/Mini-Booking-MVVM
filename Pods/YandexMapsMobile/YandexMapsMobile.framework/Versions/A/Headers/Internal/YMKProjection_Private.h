#import <YandexMapsMobile/YMKProjection.h>

#import <yandex/maps/mapkit/geometry/geo/projection.h>

#import <memory>

@interface YMKProjection ()

- (id)initWithWrappedNative:(NSValue *)native;
- (id)initWithNative:(const std::shared_ptr<::yandex::maps::mapkit::geometry::geo::Projection>&)native;

- (std::shared_ptr<::yandex::maps::mapkit::geometry::geo::Projection>)nativeProjection;
- (std::shared_ptr<::yandex::maps::mapkit::geometry::geo::Projection>)native;

@end
