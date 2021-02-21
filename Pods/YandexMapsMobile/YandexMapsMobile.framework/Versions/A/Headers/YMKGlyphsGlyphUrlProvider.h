#import <Foundation/Foundation.h>

@class YMKGlyphsGlyphIdRange;

/**
 * :nodoc:
 */
@protocol YMKGlyphsGlyphUrlProvider <NSObject>

- (nonnull NSString *)formatUrlWithFontId:(nonnull NSString *)fontId
                                    range:(nonnull YMKGlyphsGlyphIdRange *)range;

@end
