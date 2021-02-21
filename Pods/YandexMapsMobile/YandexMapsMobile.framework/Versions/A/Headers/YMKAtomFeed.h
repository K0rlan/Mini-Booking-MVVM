#import <YandexMapsMobile/YMKAttribution.h>

/**
 * :nodoc:
 * Information about the author of the post in the feed.
 */
@interface YMKAtomAuthor : NSObject

@property (nonatomic, readonly, nonnull) NSString *name;

/**
 * Optional field, can be nil.
 */
@property (nonatomic, readonly, nullable) NSString *uri;

/**
 * Optional field, can be nil.
 */
@property (nonatomic, readonly, nullable) NSString *email;


+ (nonnull YMKAtomAuthor *)authorWithName:(nonnull NSString *)name
                                      uri:(nullable NSString *)uri
                                    email:(nullable NSString *)email;


@end

/**
 * :nodoc:
 * Save, edit and delete links in the feed.
 */
@interface YMKAtomLink : NSObject

@property (nonatomic, readonly, nonnull) NSString *href;

/**
 * Optional field, can be nil.
 */
@property (nonatomic, readonly, nullable) NSString *rel;

/**
 * Optional field, can be nil.
 */
@property (nonatomic, readonly, nullable) NSString *type;


+ (nonnull YMKAtomLink *)linkWithHref:(nonnull NSString *)href
                                  rel:(nullable NSString *)rel
                                 type:(nullable NSString *)type;


@end

/**
 * :nodoc:
 * Common feed entry information.
 */
@interface YMKAtomEntry : NSObject

/**
 * Optional field, can be nil.
 */
@property (nonatomic, readonly, nullable) NSString *id;

/**
 * Optional field, can be nil.
 */
@property (nonatomic, readonly, nullable) NSString *updateTime;

@property (nonatomic, readonly, nonnull) YMKAtomAuthor *author;

/**
 * Optional field, can be nil.
 */
@property (nonatomic, readonly, nullable) YMKAttribution *attribution;

@property (nonatomic, readonly, nonnull) NSArray<YMKAtomLink *> *links;


+ (nonnull YMKAtomEntry *)entryWithId:(nullable NSString *)id
                           updateTime:(nullable NSString *)updateTime
                               author:(nonnull YMKAtomAuthor *)author
                          attribution:(nullable YMKAttribution *)attribution
                                links:(nonnull NSArray<YMKAtomLink *> *)links;


@end

/**
 * :nodoc:
 * Root feed element.
 */
@interface YMKAtomFeed : NSObject

/**
 * Optional field, can be nil.
 */
@property (nonatomic, readonly, nullable) NSString *nextpage;

@property (nonatomic, readonly, nonnull) NSArray<YMKAtomLink *> *links;


+ (nonnull YMKAtomFeed *)feedWithNextpage:(nullable NSString *)nextpage
                                    links:(nonnull NSArray<YMKAtomLink *> *)links;


@end
