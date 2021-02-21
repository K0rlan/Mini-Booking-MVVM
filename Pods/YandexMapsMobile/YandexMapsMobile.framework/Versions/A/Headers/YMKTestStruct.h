#import <Foundation/Foundation.h>

/**
 * :nodoc:
 */
@interface YMKTestStruct : NSObject

@property (nonatomic, readonly) NSUInteger value;


+ (nonnull YMKTestStruct *)testStructWithValue:( NSUInteger)value;


@end
