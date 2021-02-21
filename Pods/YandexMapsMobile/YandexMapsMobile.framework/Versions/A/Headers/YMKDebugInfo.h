#import <Foundation/Foundation.h>

/**
 * Debug info of the map.
 */
@interface YMKDebugInfo : NSObject

/**
 * Total amount of memory used by the map in bytes.
 */
@property (nonatomic, readonly) long long memUsage;


+ (nonnull YMKDebugInfo *)debugInfoWithMemUsage:( long long)memUsage;


@end
