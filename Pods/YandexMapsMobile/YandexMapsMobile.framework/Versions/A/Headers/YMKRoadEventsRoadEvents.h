#import <YandexMapsMobile/YMKAtomFeed.h>
#import <YandexMapsMobile/YMKAttribution.h>
#import <YandexMapsMobile/YMKRoadEventsEventTag.h>
#import <YandexMapsMobile/YMKTime.h>

/**
 * :nodoc:
 */
@interface YMKRoadEventsTimePeriod : NSObject

/**
 * Unix timestamps.
 */
@property (nonatomic, readonly, nonnull) YMKTime *begin;

/**
 * Optional field, can be nil.
 */
@property (nonatomic, readonly, nullable) YMKTime *end;


+ (nonnull YMKRoadEventsTimePeriod *)timePeriodWithBegin:(nonnull YMKTime *)begin
                                                     end:(nullable YMKTime *)end;


@end

/**
 * :nodoc:
 */
@interface YMKRoadEventsRoadEventMetadata : NSObject

@property (nonatomic, readonly, nonnull) NSString *eventId;

/**
 * Point id obtained from server.
 *
 * Optional field, can be nil.
 */
@property (nonatomic, readonly, nullable) NSString *description;

@property (nonatomic, readonly, nonnull) NSArray<NSNumber *> *tags;

/**
 * Optional field, can be nil.
 */
@property (nonatomic, readonly, nullable) YMKRoadEventsTimePeriod *timePeriod;

@property (nonatomic, readonly, nonnull) YMKTime *modificationTime;

/**
 * Optional field, can be nil.
 */
@property (nonatomic, readonly, nullable) NSNumber *commentsCount;

/**
 * Optional field, can be nil.
 */
@property (nonatomic, readonly, nullable) YMKAttributionAuthor *author;


+ (nonnull YMKRoadEventsRoadEventMetadata *)roadEventMetadataWithEventId:(nonnull NSString *)eventId
                                                             description:(nullable NSString *)description
                                                                    tags:(nonnull NSArray<NSNumber *> *)tags
                                                              timePeriod:(nullable YMKRoadEventsTimePeriod *)timePeriod
                                                        modificationTime:(nonnull YMKTime *)modificationTime
                                                           commentsCount:(nullable NSNumber *)commentsCount
                                                                  author:(nullable YMKAttributionAuthor *)author;


@end

/**
 * :nodoc:
 */
@interface YMKRoadEventsTextEntry : NSObject

@property (nonatomic, readonly, nonnull) NSString *text;


+ (nonnull YMKRoadEventsTextEntry *)textEntryWithText:(nonnull NSString *)text;


@end

/**
 * :nodoc:
 */
@interface YMKRoadEventsEntry : NSObject

@property (nonatomic, readonly, nonnull) YMKAtomEntry *atomEntry;

@property (nonatomic, readonly, nonnull) YMKRoadEventsTextEntry *content;


+ (nonnull YMKRoadEventsEntry *)entryWithAtomEntry:(nonnull YMKAtomEntry *)atomEntry
                                           content:(nonnull YMKRoadEventsTextEntry *)content;


@end

/**
 * :nodoc:
 */
@interface YMKRoadEventsFeed : NSObject

@property (nonatomic, readonly, nonnull) YMKAtomFeed *atomFeed;

@property (nonatomic, readonly, nonnull) NSArray<YMKRoadEventsEntry *> *entries;


+ (nonnull YMKRoadEventsFeed *)feedWithAtomFeed:(nonnull YMKAtomFeed *)atomFeed
                                        entries:(nonnull NSArray<YMKRoadEventsEntry *> *)entries;


@end
