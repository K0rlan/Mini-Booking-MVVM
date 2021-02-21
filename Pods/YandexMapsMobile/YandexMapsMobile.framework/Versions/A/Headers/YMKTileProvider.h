#import <YandexMapsMobile/YMKRawTile.h>
#import <YandexMapsMobile/YMKTileId.h>
#import <YandexMapsMobile/YMKVersion.h>

/**
 * Generates empty tiles.
 */
@protocol YMKTileProvider <NSObject>

/**
 * Called in a separate thread and generates an empty tile.
 */
- (nonnull YMKRawTile *)loadWithTileId:(nonnull YMKTileId *)tileId
                               version:(nonnull YMKVersion *)version
                                  etag:(nonnull NSString *)etag;

@end
