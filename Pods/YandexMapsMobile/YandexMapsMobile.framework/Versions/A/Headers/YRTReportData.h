#import <Foundation/Foundation.h>

@class YRTReportData;

/**
 * :nodoc:
 */
@interface YRTReportData : NSObject
@property (nonatomic, readonly, nonnull) NSDate *startTime;
@property (nonatomic, readonly, nonnull) NSDate *endTime;
/**
 * Optional property, can be nil.
 */
@property (nonatomic, nullable) NSString *issueId;

- (nonnull NSArray<NSDate *> *)problemMarks;

- (nonnull NSData *)data;

@end

/**
 * :nodoc:
 */
@interface YRTReportFactory : NSObject

- (nonnull YRTReportData *)createReportDataWithData:(nonnull NSData *)data;

@end
