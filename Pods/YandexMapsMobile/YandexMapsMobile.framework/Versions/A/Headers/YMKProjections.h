#import <Foundation/Foundation.h>

@class YMKProjection;

@interface YMKProjections : NSObject

+ (nonnull YMKProjection *)wgs84Mercator;

+ (nonnull YMKProjection *)sphericalMercator;

@end

