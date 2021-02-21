#import <Foundation/Foundation.h>

/**
 * The type of map displayed.
 */
typedef NS_ENUM(NSUInteger, YMKMapType) {
    /**
     * Do not use any of the predefined maps.
     */
    YMKMapTypeNone,
    /**
     * Raster map.
     */
    YMKMapTypeMap,
    /**
     * :nodoc:
     * Default satellite map.
     */
    YMKMapTypeSatellite,
    /**
     * :nodoc:
     * Satellite map with roads, placemarks and labels.
     */
    YMKMapTypeHybrid,
    /**
     * Vector map.
     */
    YMKMapTypeVectorMap
};
