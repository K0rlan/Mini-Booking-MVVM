#import <Foundation/Foundation.h>

@class YMKAttributionAuthor;
@class YMKAttributionLink;

/**
 * :nodoc:
 * Details about the source of information.
 */
@interface YMKAttribution : NSObject

/**
 * Additional information about the author.
 *
 * Optional field, can be nil.
 */
@property (nonatomic, readonly, nullable) YMKAttributionAuthor *author;

/**
 * Link to a specific page on the author's site. To link to the website
 * as a whole, use author.uri.
 *
 * Optional field, can be nil.
 */
@property (nonatomic, readonly, nullable) YMKAttributionLink *link;


+ (nonnull YMKAttribution *)attributionWithAuthor:(nullable YMKAttributionAuthor *)author
                                             link:(nullable YMKAttributionLink *)link;


@end

@interface YMKAttributionAuthor : NSObject

@property (nonatomic, readonly, nonnull) NSString *name;

/**
 * A reference to the author's site.
 *
 * Optional field, can be nil.
 */
@property (nonatomic, readonly, nullable) NSString *uri;

/**
 * Author's email. Must contain at least one @ symbol.
 *
 * Optional field, can be nil.
 */
@property (nonatomic, readonly, nullable) NSString *email;


+ (nonnull YMKAttributionAuthor *)authorWithName:(nonnull NSString *)name
                                             uri:(nullable NSString *)uri
                                           email:(nullable NSString *)email;


@end

@interface YMKAttributionLink : NSObject

@property (nonatomic, readonly, nonnull) NSString *href;


+ (nonnull YMKAttributionLink *)linkWithHref:(nonnull NSString *)href;


@end
