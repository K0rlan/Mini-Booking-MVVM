#import <YandexMapsMobile/YMKDirection.h>
#import <YandexMapsMobile/YMKPoint.h>

/**
 * An arrival point for a place (the position to drive/walk to if you
 * want to visit the place). For example, named entrance into the
 * building.
 */
@interface YMKArrivalPoint : NSObject

/**
 * Optional name for an arrival point, e.g. 'exit 4' or 'main entrance'.
 *
 * Optional field, can be nil.
 */
@property (nonatomic, readonly, nullable) NSString *name;

/**
 * Arrival point position.
 */
@property (nonatomic, readonly, nonnull) YMKPoint *point;

/**
 * Azimuth for the outside normal to the building.
 *
 * Optional field, can be nil.
 */
@property (nonatomic, readonly, nullable) YMKDirection *direction;


+ (nonnull YMKArrivalPoint *)arrivalPointWithName:(nullable NSString *)name
                                            point:(nonnull YMKPoint *)point
                                        direction:(nullable YMKDirection *)direction;


@end

/**
 * List of arrival points for the GeoObject.
 */
@interface YMKArrivalObjectMetadata : NSObject

/**
 * List of ArrivalPoint objects.
 */
@property (nonatomic, readonly, nonnull) NSArray<YMKArrivalPoint *> *arrivalPoints;


+ (nonnull YMKArrivalObjectMetadata *)arrivalObjectMetadataWithArrivalPoints:(nonnull NSArray<YMKArrivalPoint *> *)arrivalPoints;


@end
