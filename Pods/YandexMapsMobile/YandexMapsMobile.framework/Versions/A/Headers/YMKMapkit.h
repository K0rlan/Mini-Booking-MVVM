#import <YandexMapsMobile/YMKCoverage.h>
#import <YandexMapsMobile/YMKDummyLocationManager.h>
#import <YandexMapsMobile/YMKGeometry.h>
#import <YandexMapsMobile/YMKLocationLocationManager.h>
#import <YandexMapsMobile/YMKLocationSimulator.h>
#import <YandexMapsMobile/YMKMapWindow.h>
#import <YandexMapsMobile/YMKOfflineCacheManager.h>
#import <YandexMapsMobile/YMKPersonalizedPoiLayer.h>
#import <YandexMapsMobile/YMKRoadEventsRoadEventsManager.h>
#import <YandexMapsMobile/YMKStorageStorageManager.h>
#import <YandexMapsMobile/YMKStyleType.h>
#import <YandexMapsMobile/YMKTrafficLayer.h>
#import <YandexMapsMobile/YMKUiExperimentsManager.h>
#import <YandexMapsMobile/YMKUserLocation.h>
#import <YandexMapsMobile/YRTAccount.h>
#import <YandexMapsMobile/YRTMiidManager.h>

@class YRTView;

/**
 * Provides access to all services in the SDK.
 *
 * Initialize the MapKit factory before using this class.
 *
 * Note: MapKit holds listener/delegate objects by weak references. You
 * need to have strong references to them somewhere in the client code.
 */
@interface YMKMapKit : NSObject

/**
 * :nodoc:
 * Sets user-specific parameters for MapKit.
 *
 * @param uuid Refer to the Yandex.Metrica documentation for information
 * about what this is and how to get one.
 * @param deviceId Device ID.
 */
- (void)setMetricaIdsWithUuid:(nonnull NSString *)uuid
                     deviceId:(nonnull NSString *)deviceId;

/**
 * :nodoc:
 * Sets advertising ID for targeting.
 *
 * @param advId GAID for android or IDFA for ios.
 */
- (void)setAdvertisingIdWithAdvId:(nonnull NSString *)advId;

/**
 * :nodoc:
 * Sets the key for API access.
 *
 * @param key Key issued in the Developer Dashboard.
 */
- (void)setApiKeyWithKey:(nonnull NSString *)key;

/**
 * :nodoc:
 * Sets the account that is used by services.
 *
 * Remark:
 * @param account has optional type, it may be uninitialized.
 */
- (void)setAccount:(nullable id<YRTAccount>)account;

/**
 * :nodoc:
 */
- (void)setScaleFactorWithScaleFactor:(float)scaleFactor;

/**
 * :nodoc:
 */
- (void)setStyleTypeWithStyleType:(YMKStyleType)styleType;

/**
 * Notifies MapKit when the application resumes the foreground state.
 */
- (void)onStart;

/**
 * Notifies MapKit when the application pauses and goes to the
 * background.
 */
- (void)onStop;
/**
 * :nodoc:
 * Returns the manager that uniquely identifies the installed app.
 */
@property (nonatomic, readonly, readonly, nonnull) YRTMiidManager *miidManager;

/**
 * :nodoc:
 * Creates a manager that allows to check if the "feature" with a given
 * ID covers some specific point or area.
 */
- (nonnull YMKCoverage *)createCoverageWithCoverageId:(nonnull NSString *)coverageId;
/**
 * :nodoc:
 * Returns a manager that allows to listen for experimental UI
 * parameters.
 */
@property (nonatomic, readonly, readonly, nonnull) YMKUiExperimentsManager *uiExperimentsManager;

/**
 * Creates a manager that allows to listen for device location updates.
 */
- (nonnull YMKLocationManager *)createLocationManager;

/**
 * Creates a suspended LocationSimulator object with the given geometry.
 */
- (nonnull YMKLocationSimulator *)createLocationSimulatorWithGeometry:(nonnull YMKPolyline *)geometry;

/**
 * Creates a suspended LocationSimulator object which provides real
 * location until first 'setGeometry'
 */
- (nonnull YMKLocationSimulator *)createLocationSimulator;

/**
 * Creates a manager that functions as a location proxy.
 */
- (nonnull YMKDummyLocationManager *)createDummyLocationManager;

/**
 * :nodoc:
 * Creates a manager that only uses the Yandex LBS service.
 */
- (nonnull YMKLocationManager *)createLbsLocationManager;

/**
 * :nodoc:
 * Creates an internal "window" object that is used to show the map.
 *
 * Do not call this method - it is for internal use only. To show the
 * map, please use the corresponding map "view" object.
 */
- (nonnull YMKMapWindow *)createMapWindowWithPlatformView:(nonnull YRTView *)platformView;

/**
 * :nodoc:
 * Creates an internal "window" object that is used to show the map with
 * a custom scale factor. The scale factor is equal to the number of
 * pixels per device-independent point.
 *
 * Do not call this method - it is for internal use only. To show the
 * map, please use the corresponding map "view" object.
 */
- (nonnull YMKMapWindow *)createMapWindowWithPlatformView:(nonnull YRTView *)platformView
                                        customScaleFactor:(float)customScaleFactor;
/**
 * @attention This feature is not available in the free MapKit version.
 *
 *
 * Returns a manager that handles offline maps, search index and road
 * graph.
 */
@property (nonatomic, readonly, readonly, nonnull) YMKOfflineCacheManager *offlineCacheManager;
/**
 * Returns a manager that handles disk size and IO errors.
 */
@property (nonatomic, readonly, readonly, nonnull) YMKStorageManager *storageManager;

/**
 * :nodoc:
 * Creates the personalized POI layer.
 */
- (nonnull YMKPersonalizedPoiLayer *)createPersonalizedPoiLayerWithMapWindow:(nonnull YMKMapWindow *)mapWindow;

/**
 * Creates the traffic layer.
 */
- (nonnull YMKTrafficLayer *)createTrafficLayerWithMapWindow:(nonnull YMKMapWindow *)mapWindow;

/**
 * :nodoc:
 * Creates a manager that allows to retrieve and add road events.
 */
- (nonnull YMKRoadEventsManager *)createRoadEventsManager;

/**
 * Create layer with the user location icon.
 */
- (nonnull YMKUserLocationLayer *)createUserLocationLayerWithMapWindow:(nonnull YMKMapWindow *)mapWindow;
/**
 * Returns the version of the MapKit bundle.
 */
@property (nonatomic, readonly, nonnull) NSString *version;

/**
 * Tells if this object is valid or no. Any method called on an invalid
 * object will throw an exception. The object becomes invalid only on UI
 * thread, and only when its implementation depends on objects already
 * destroyed by now. Please refer to general docs about the interface for
 * details on its invalidation.
 */
@property (nonatomic, readonly, getter=isValid) BOOL valid;

@end
