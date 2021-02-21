#import <YandexMapsMobile/YMKGeoObject.h>
#import <YandexMapsMobile/YMKPoint.h>
#import <YandexMapsMobile/YMKRoadEventsEventTag.h>
#import <YandexMapsMobile/YRTAuthError.h>
#import <YandexMapsMobile/YRTErrors.h>

@class YMKRoadEventsEntry;
@class YMKRoadEventsEntrySession;
@class YMKRoadEventsEventInfoSession;
@class YMKRoadEventsFeed;
@class YMKRoadEventsFeedSession;
@class YMKRoadEventsRoadEventFailedError;
@class YMKRoadEventsRoadEventSession;
@class YMKRoadEventsVoteSession;

/**
 * :nodoc:
 */
typedef void(^YMKRoadEventsRoadEventSessionResponseHandler)(
    YMKGeoObject * _Nullable event,
    NSError * _Nullable error);

/**
 * :nodoc:
 * Road event creation session.
 */
@interface YMKRoadEventsRoadEventSession : NSObject

/**
 * One of the following errors can happen:
 * YMKRoadEventsRoadEventFailedError, YRTNetworkError,
 * YRTAuthPasswordRequiredError, YRTRemoteError.
 */
- (void)retryWithResponseHandler:(nonnull YMKRoadEventsRoadEventSessionResponseHandler)responseHandler;

- (void)cancel;

@end

/**
 * :nodoc:
 */
typedef void(^YMKRoadEventsEventInfoSessionResponseHandler)(
    YMKGeoObject * _Nullable event,
    NSError * _Nullable error);

/**
 * :nodoc:
 * Session for requesting road event info.
 */
@interface YMKRoadEventsEventInfoSession : NSObject

/**
 * One of the following errors can happen: YRTNotFoundError,
 * {@runtime.network.NetworkError}, YRTRemoteError.
 */
- (void)retryWithResponseHandler:(nonnull YMKRoadEventsEventInfoSessionResponseHandler)responseHandler;

- (void)cancel;

@end

/**
 * :nodoc:
 */
typedef void(^YMKRoadEventsEntrySessionResponseHandler)(
    YMKRoadEventsEntry * _Nullable entry,
    NSError * _Nullable error);

/**
 * :nodoc:
 * Session for adding comments.
 */
@interface YMKRoadEventsEntrySession : NSObject

/**
 * One of the following errors can occur:
 * YMKRoadEventsRoadEventFailedError, YRTNotFoundError, YRTNetworkError,
 * YRTAuthPasswordRequiredError, YRTRemoteError.
 */
- (void)retryWithResponseHandler:(nonnull YMKRoadEventsEntrySessionResponseHandler)responseHandler;

- (void)cancel;

@end

/**
 * :nodoc:
 */
typedef void(^YMKRoadEventsFeedSessionResponseHandler)(
    YMKRoadEventsFeed * _Nullable feed,
    NSError * _Nullable error);

/**
 * :nodoc:
 * Session for requesting the comments feed.
 */
@interface YMKRoadEventsFeedSession : NSObject

- (BOOL)hasNextPage;

/**
 * One of the following errors can occur: YRTNotFoundError,
 * YRTNetworkError, YRTRemoteError.
 */
- (void)fetchNextPageWithResponseHandler:(nonnull YMKRoadEventsFeedSessionResponseHandler)responseHandler;

- (void)cancel;

@end

/**
 * :nodoc:
 */
typedef void(^YMKRoadEventsVoteSessionResponseHandler)(
    NSError * _Nullable error);

/**
 * :nodoc:
 * Session for voting for or against events.
 */
@interface YMKRoadEventsVoteSession : NSObject

/**
 * One of the following errors can occur:
 * YMKRoadEventsRoadEventFailedError, YRTNotFoundError, YRTNetworkError,
 * YRTAuthPasswordRequiredError, YRTRemoteError.
 */
- (void)retryWithResponseHandler:(nonnull YMKRoadEventsVoteSessionResponseHandler)responseHandler;

- (void)cancel;

@end

/**
 * :nodoc:
 */
@interface YMKRoadEventsManager : NSObject

/**
 * Begins async request to create a road event.
 *
 * @param eventTag Tag of event to create.
 * @param descriptionText Event description.
 * @param eventLocation new Event location.
 * @param roadEventListener Listener for result or error.
 *
 * @return Request session.
 */
- (nonnull YMKRoadEventsRoadEventSession *)addEventWithEventTag:(YMKRoadEventsEventTag)eventTag
                                                descriptionText:(nonnull NSString *)descriptionText
                                                  eventLocation:(nonnull YMKPoint *)eventLocation
                                                responseHandler:(nonnull YMKRoadEventsRoadEventSessionResponseHandler)responseHandler;

/**
 * Begins asynchronous request for road event info.
 *
 * @param eventId ID of the event to request information for.
 * @param eventInfoListener Listener for result or error.
 */
- (nonnull YMKRoadEventsEventInfoSession *)requestEventInfoWithEventId:(nonnull NSString *)eventId
                                                       responseHandler:(nonnull YMKRoadEventsEventInfoSessionResponseHandler)responseHandler;

/**
 * Begins async request to vote up a road event.
 *
 * @param eventId ID of the event to vote for.
 * @param voteListener Listener for result or error.
 *
 * @return Request session.
 */
- (nonnull YMKRoadEventsVoteSession *)voteUpWithEventId:(nonnull NSString *)eventId
                                        responseHandler:(nonnull YMKRoadEventsVoteSessionResponseHandler)responseHandler;

/**
 * Begins async request to vote down a road event.
 *
 * @param eventId ID of the event to vote for.
 * @param voteListener Listener for result or error.
 *
 * @return Request session.
 */
- (nonnull YMKRoadEventsVoteSession *)voteDownWithEventId:(nonnull NSString *)eventId
                                          responseHandler:(nonnull YMKRoadEventsVoteSessionResponseHandler)responseHandler;

/**
 * Begins async request to get comments.
 *
 * @param eventId ID of the event to get comments for.
 *
 * @return Comments session.
 */
- (nonnull YMKRoadEventsFeedSession *)commentsWithEventId:(nonnull NSString *)eventId;

/**
 * Begins async request to add a comment.
 *
 * @param eventId ID of the event to add a comment for.
 * @param text Comment text.
 * @param entryListener Receives the new comment entry or error.
 *
 * @return Request session.
 */
- (nonnull YMKRoadEventsEntrySession *)addCommentWithEventId:(nonnull NSString *)eventId
                                                        text:(nonnull NSString *)text
                                             responseHandler:(nonnull YMKRoadEventsEntrySessionResponseHandler)responseHandler;

@end
