#import <Foundation/Foundation.h>
#import <YandexMapsMobile/YRTAnimatedModel.h>
#import <YandexMapsMobile/YRTAnimatedModelProvider.h>

@interface YRTAnimatedModelProviderFactory : NSObject

+ (id<YRTAnimatedModelProvider>)fromAnimatedModel:(YRTAnimatedModel*)animatedModel;

@end
