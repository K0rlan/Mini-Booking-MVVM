#import <Foundation/Foundation.h>

/**
 * :nodoc:
 */
@interface YMKGlyphsGlyphIdRange : NSObject

@property (nonatomic, readonly) NSUInteger firstGlyphId;

@property (nonatomic, readonly) NSUInteger lastGlyphId;


+ (nonnull YMKGlyphsGlyphIdRange *)glyphIdRangeWithFirstGlyphId:( NSUInteger)firstGlyphId
                                                    lastGlyphId:( NSUInteger)lastGlyphId;


@end
