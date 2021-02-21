#import <YandexMapsMobile/YMKRoadEventsEventTag.h>

/**
 * Road event tap object meta information.
 */
@interface YMKTrafficRoadEventTapInfo : NSObject

/**
 * Road event identifier.
 */
@property (nonatomic, readonly, nonnull) NSString *id;

/**
 * Road event description.
 */
@property (nonatomic, readonly, nonnull) NSString *descriptionText;

/**
 * Road event tags.
 */
@property (nonatomic, readonly, nonnull) NSArray<NSNumber *> *tags;


+ (nonnull YMKTrafficRoadEventTapInfo *)roadEventTapInfoWithId:(nonnull NSString *)id
                                               descriptionText:(nonnull NSString *)descriptionText
                                                          tags:(nonnull NSArray<NSNumber *> *)tags;


@end
