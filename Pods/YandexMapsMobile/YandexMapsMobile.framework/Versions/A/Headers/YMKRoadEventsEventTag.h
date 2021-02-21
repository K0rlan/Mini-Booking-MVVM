#import <Foundation/Foundation.h>

/**
 * :nodoc:
 */
typedef NS_ENUM(NSUInteger, YMKRoadEventsEventTag) {
    YMKRoadEventsEventTagOther,
    YMKRoadEventsEventTagFeedback,
    YMKRoadEventsEventTagChat,
    /**
     * Temporary issues
     */
    YMKRoadEventsEventTagDrawbridge,
    YMKRoadEventsEventTagClosed,
    YMKRoadEventsEventTagReconstruction,
    YMKRoadEventsEventTagAccident,
    YMKRoadEventsEventTagTrafficAlert,
    /**
     * Potentially dangerous zones
     */
    YMKRoadEventsEventTagDanger,
    YMKRoadEventsEventTagSchool,
    YMKRoadEventsEventTagOvertakingDanger,
    YMKRoadEventsEventTagPedestrianDanger,
    YMKRoadEventsEventTagCrossRoadDanger,
    /**
     * Traffic code control tags
     */
    YMKRoadEventsEventTagPolice,
    YMKRoadEventsEventTagLaneControl,
    YMKRoadEventsEventTagRoadMarkingControl,
    YMKRoadEventsEventTagCrossRoadControl,
    YMKRoadEventsEventTagNoStoppingControl,
    YMKRoadEventsEventTagMobileControl,
    YMKRoadEventsEventTagSpeedControl
};
