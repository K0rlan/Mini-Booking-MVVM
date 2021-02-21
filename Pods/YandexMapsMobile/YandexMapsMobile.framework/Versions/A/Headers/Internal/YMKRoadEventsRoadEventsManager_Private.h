#import <YandexMapsMobile/YMKRoadEventsRoadEventsManager.h>

#import <yandex/maps/mapkit/road_events/road_events_manager.h>

#import <memory>

namespace yandex {
namespace maps {
namespace mapkit {
namespace road_events {
namespace ios {

RoadEventSession::OnRoadEventReceived onRoadEventReceived(
    YMKRoadEventsRoadEventSessionResponseHandler handler);
RoadEventSession::OnRoadEventError onRoadEventError(
    YMKRoadEventsRoadEventSessionResponseHandler handler);

EventInfoSession::OnEventInfoReceived onEventInfoReceived(
    YMKRoadEventsEventInfoSessionResponseHandler handler);
EventInfoSession::OnEventInfoError onEventInfoError(
    YMKRoadEventsEventInfoSessionResponseHandler handler);

EntrySession::OnEntryReceived onEntryReceived(
    YMKRoadEventsEntrySessionResponseHandler handler);
EntrySession::OnEntryError onEntryError(
    YMKRoadEventsEntrySessionResponseHandler handler);

FeedSession::OnFeedReceived onFeedReceived(
    YMKRoadEventsFeedSessionResponseHandler handler);
FeedSession::OnFeedError onFeedError(
    YMKRoadEventsFeedSessionResponseHandler handler);

VoteSession::OnVoteCompleted onVoteCompleted(
    YMKRoadEventsVoteSessionResponseHandler handler);
VoteSession::OnVoteError onVoteError(
    YMKRoadEventsVoteSessionResponseHandler handler);

} // namespace ios
} // namespace road_events
} // namespace mapkit
} // namespace maps
} // namespace yandex

@interface YMKRoadEventsRoadEventSession ()

- (id)initWithWrappedNative:(NSValue *)native;
- (id)initWithNative:(std::unique_ptr<::yandex::maps::mapkit::road_events::RoadEventSession>)native;

- (::yandex::maps::mapkit::road_events::RoadEventSession *)nativeRoadEventSession;

@end

@interface YMKRoadEventsEventInfoSession ()

- (id)initWithWrappedNative:(NSValue *)native;
- (id)initWithNative:(std::unique_ptr<::yandex::maps::mapkit::road_events::EventInfoSession>)native;

- (::yandex::maps::mapkit::road_events::EventInfoSession *)nativeEventInfoSession;

@end

@interface YMKRoadEventsEntrySession ()

- (id)initWithWrappedNative:(NSValue *)native;
- (id)initWithNative:(std::unique_ptr<::yandex::maps::mapkit::road_events::EntrySession>)native;

- (::yandex::maps::mapkit::road_events::EntrySession *)nativeEntrySession;

@end

@interface YMKRoadEventsFeedSession ()

- (id)initWithWrappedNative:(NSValue *)native;
- (id)initWithNative:(std::unique_ptr<::yandex::maps::mapkit::road_events::FeedSession>)native;

- (::yandex::maps::mapkit::road_events::FeedSession *)nativeFeedSession;

@end

@interface YMKRoadEventsVoteSession ()

- (id)initWithWrappedNative:(NSValue *)native;
- (id)initWithNative:(std::unique_ptr<::yandex::maps::mapkit::road_events::VoteSession>)native;

- (::yandex::maps::mapkit::road_events::VoteSession *)nativeVoteSession;

@end

@interface YMKRoadEventsManager ()

- (id)initWithWrappedNative:(NSValue *)native;
- (id)initWithNative:(std::unique_ptr<::yandex::maps::mapkit::road_events::RoadEventsManager>)native;

- (::yandex::maps::mapkit::road_events::RoadEventsManager *)nativeRoadEventsManager;

@end
