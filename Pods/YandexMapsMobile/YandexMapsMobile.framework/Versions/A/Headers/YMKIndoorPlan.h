#import <Foundation/Foundation.h>

@class YMKIndoorLevel;

/**
 * :nodoc:
 */
@interface YMKIndoorLevel : NSObject

/**
 * Universal identifier of the level.
 */
@property (nonatomic, readonly, nonnull) NSString *id;

/**
 * Localized display name of the level.
 */
@property (nonatomic, readonly, nonnull) NSString *name;

/**
 * true if level is under ground
 */
@property (nonatomic, readonly) BOOL isUnderground;


+ (nonnull YMKIndoorLevel *)indoorLevelWithId:(nonnull NSString *)id
                                         name:(nonnull NSString *)name
                                isUnderground:( BOOL)isUnderground;


@end

/**
 * :nodoc:
 */
@interface YMKIndoorPlan : NSObject
/**
 * List of all levels in indoor plan, from bottom to top.
 */
@property (nonatomic, readonly, nonnull) NSArray<YMKIndoorLevel *> *levels;
/**
 * Gets/sets active id.
 */
@property (nonatomic, nonnull) NSString *activeLevelId;

@end
