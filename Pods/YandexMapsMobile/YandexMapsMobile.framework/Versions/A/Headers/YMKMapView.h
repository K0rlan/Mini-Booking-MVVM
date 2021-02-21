#import <YandexMapsMobile/YMKMapWindow.h>
#import <YandexMapsMobile/YRTGraphicsApiType.h>

#import <UIKit/UIKit.h>

@interface YMKMapView : UIView

@property (nonatomic, readonly) YMKMapWindow *mapWindow;
@property (nonatomic, readonly) BOOL vulkanPreferred;

- (void)setNoninteractive:(bool)is;
- (instancetype)initWithFrame:(CGRect)frame vulkanPreferred:(BOOL)vulkanPreferred;
- (enum YRTGraphicsAPIType)getGraphicsAPI;

@end
