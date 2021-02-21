#import <YandexMapsMobile/YMKErrors.h>

#import <yandex/maps/mapkit/offline_cache/errors.h>

#import <memory>

@interface YMKCachePathUnavailable ()

- (id)initWithWrappedNative:(NSValue *)native;
- (id)initWithNative:(const std::shared_ptr<::yandex::maps::mapkit::offline_cache::CachePathUnavailable>&)native;

- (std::shared_ptr<::yandex::maps::mapkit::offline_cache::CachePathUnavailable>)nativeCachePathUnavailable;

@end
