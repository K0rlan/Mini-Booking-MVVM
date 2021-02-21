#pragma once

#import <YandexMapsMobile/YRTArchiving.h>

@protocol YRTSerialization <NSObject>

- (void)serialize:(id<YRTArchiving>)archive;

@end
