#import <YandexMapsMobile/YRTGraphicsApiType.h>
#import <UIKit/UIKit.h>

namespace yandex::maps::runtime::view {
class PlatformView;
} // namespace yandex::maps::runtime::view
@class YRTTouchEvent;

@interface YRTView : UIView

- (yandex::maps::runtime::view::PlatformView*)getPlatformView;
- (void)setNoninteractive:(bool)is;
- (void)handleTouchEvent:(YRTTouchEvent *)touchEvent;
- (void)deinitialize;
- (enum YRTGraphicsAPIType)getGraphicsAPI;

@end

@interface YRTViewFactory : NSObject

+ (YRTView*)createViewWithFrame:(CGRect)frame vulkanPreferred:(BOOL)vulkanPreferred;
+ (YRTView*)createViewWithFrame:(CGRect)frame
                                  scale:(float)scale
                        vulkanPreferred:(BOOL)vulkanPreferred;

@end

