#import <YandexMapsMobile/YMKGeometry.h>
#import <YandexMapsMobile/YMKLocationLocationManager.h>

/**
 * Listens for updates for location simulation.
 */
@protocol YMKLocationSimulatorListener <NSObject>

/**
 * Simulation is finished.
 */
- (void)onSimulationFinished;

@end

/**
 * Simulates the device location.
 */
@interface YMKLocationSimulator : YMKLocationManager
/**
 * The polyline describing the location.
 *
 * Optional property, can be nil.
 */
@property (nonatomic, nullable) YMKPolyline *geometry;
/**
 * The position of the polyline.
 */
@property (nonatomic, readonly, nonnull) YMKPolylinePosition *polylinePosition;
/**
 * Movement speed.
 */
@property (nonatomic) double speed;

/**
 * Subscribes to simulation events.
 */
- (void)subscribeForSimulatorEventsWithSimulatorListener:(nonnull id<YMKLocationSimulatorListener>)simulatorListener;

/**
 * Unsubscribes from simulation events.
 */
- (void)unsubscribeFromSimulatorEventsWithSimulatorListener:(nonnull id<YMKLocationSimulatorListener>)simulatorListener;
/**
 * True if simulator is not suspended.
 */
@property (nonatomic, readonly, getter=isActive) BOOL active;

@end
