#import <YandexMapsMobile/YRTLocalError.h>

#import <yandex/maps/runtime/local_error.h>

#import <memory>

@interface YRTLocalError ()

- (id)initWithWrappedNative:(NSValue *)native;
- (id)initWithNative:(const std::shared_ptr<::yandex::maps::runtime::LocalError>&)native;

- (std::shared_ptr<::yandex::maps::runtime::LocalError>)nativeLocalError;

@end

@interface YRTDiskFullError ()

- (id)initWithWrappedNative:(NSValue *)native;
- (id)initWithNative:(const std::shared_ptr<::yandex::maps::runtime::DiskFullError>&)native;

- (std::shared_ptr<::yandex::maps::runtime::DiskFullError>)nativeDiskFullError;

@end

@interface YRTDiskCorruptError ()

- (id)initWithWrappedNative:(NSValue *)native;
- (id)initWithNative:(const std::shared_ptr<::yandex::maps::runtime::DiskCorruptError>&)native;

- (std::shared_ptr<::yandex::maps::runtime::DiskCorruptError>)nativeDiskCorruptError;

@end

@interface YRTDiskWriteAccessError ()

- (id)initWithWrappedNative:(NSValue *)native;
- (id)initWithNative:(const std::shared_ptr<::yandex::maps::runtime::DiskWriteAccessError>&)native;

- (std::shared_ptr<::yandex::maps::runtime::DiskWriteAccessError>)nativeDiskWriteAccessError;

@end
