#import <YandexMapsMobile/YMKGeometry.h>

#import <yandex/maps/mapkit/geometry/geometry.h>
#import <yandex/maps/runtime/bindings/ios/to_native.h>
#import <yandex/maps/runtime/bindings/ios/to_native_fwd.h>
#import <yandex/maps/runtime/bindings/ios/to_platform.h>
#import <yandex/maps/runtime/bindings/ios/to_platform_fwd.h>

#import <type_traits>

namespace yandex {
namespace maps {
namespace runtime {
namespace bindings {
namespace ios {
namespace internal {

template <>
struct ToNative<::yandex::maps::mapkit::geometry::BoundingBox, YMKBoundingBox, void> {
    static ::yandex::maps::mapkit::geometry::BoundingBox from(
        YMKBoundingBox* platformBoundingBox);
};

template <typename PlatformType>
struct ToNative<::yandex::maps::mapkit::geometry::BoundingBox, PlatformType,
        typename std::enable_if<
            std::is_convertible<PlatformType, YMKBoundingBox*>::value>::type> {
    static ::yandex::maps::mapkit::geometry::BoundingBox from(
        PlatformType platformBoundingBox)
    {
        return ToNative<::yandex::maps::mapkit::geometry::BoundingBox, YMKBoundingBox>::from(
            platformBoundingBox);
    }
};

template <>
struct ToPlatform<::yandex::maps::mapkit::geometry::BoundingBox> {
    static YMKBoundingBox* from(
        const ::yandex::maps::mapkit::geometry::BoundingBox& boundingBox);
};

} // namespace internal
} // namespace ios
} // namespace bindings
} // namespace runtime
} // namespace maps
} // namespace yandex

namespace yandex {
namespace maps {
namespace runtime {
namespace bindings {
namespace ios {
namespace internal {

template <>
struct ToNative<::yandex::maps::mapkit::geometry::Circle, YMKCircle, void> {
    static ::yandex::maps::mapkit::geometry::Circle from(
        YMKCircle* platformCircle);
};

template <typename PlatformType>
struct ToNative<::yandex::maps::mapkit::geometry::Circle, PlatformType,
        typename std::enable_if<
            std::is_convertible<PlatformType, YMKCircle*>::value>::type> {
    static ::yandex::maps::mapkit::geometry::Circle from(
        PlatformType platformCircle)
    {
        return ToNative<::yandex::maps::mapkit::geometry::Circle, YMKCircle>::from(
            platformCircle);
    }
};

template <>
struct ToPlatform<::yandex::maps::mapkit::geometry::Circle> {
    static YMKCircle* from(
        const ::yandex::maps::mapkit::geometry::Circle& circle);
};

} // namespace internal
} // namespace ios
} // namespace bindings
} // namespace runtime
} // namespace maps
} // namespace yandex

namespace yandex {
namespace maps {
namespace runtime {
namespace bindings {
namespace ios {
namespace internal {

template <>
struct ToNative<::yandex::maps::mapkit::geometry::Segment, YMKSegment, void> {
    static ::yandex::maps::mapkit::geometry::Segment from(
        YMKSegment* platformSegment);
};

template <typename PlatformType>
struct ToNative<::yandex::maps::mapkit::geometry::Segment, PlatformType,
        typename std::enable_if<
            std::is_convertible<PlatformType, YMKSegment*>::value>::type> {
    static ::yandex::maps::mapkit::geometry::Segment from(
        PlatformType platformSegment)
    {
        return ToNative<::yandex::maps::mapkit::geometry::Segment, YMKSegment>::from(
            platformSegment);
    }
};

template <>
struct ToPlatform<::yandex::maps::mapkit::geometry::Segment> {
    static YMKSegment* from(
        const ::yandex::maps::mapkit::geometry::Segment& segment);
};

} // namespace internal
} // namespace ios
} // namespace bindings
} // namespace runtime
} // namespace maps
} // namespace yandex



namespace yandex {
namespace maps {
namespace runtime {
namespace bindings {
namespace ios {
namespace internal {

template <>
struct ToNative<::yandex::maps::mapkit::geometry::PolylinePosition, YMKPolylinePosition, void> {
    static ::yandex::maps::mapkit::geometry::PolylinePosition from(
        YMKPolylinePosition* platformPolylinePosition);
};

template <typename PlatformType>
struct ToNative<::yandex::maps::mapkit::geometry::PolylinePosition, PlatformType,
        typename std::enable_if<
            std::is_convertible<PlatformType, YMKPolylinePosition*>::value>::type> {
    static ::yandex::maps::mapkit::geometry::PolylinePosition from(
        PlatformType platformPolylinePosition)
    {
        return ToNative<::yandex::maps::mapkit::geometry::PolylinePosition, YMKPolylinePosition>::from(
            platformPolylinePosition);
    }
};

template <>
struct ToPlatform<::yandex::maps::mapkit::geometry::PolylinePosition> {
    static YMKPolylinePosition* from(
        const ::yandex::maps::mapkit::geometry::PolylinePosition& polylinePosition);
};

} // namespace internal
} // namespace ios
} // namespace bindings
} // namespace runtime
} // namespace maps
} // namespace yandex

namespace yandex {
namespace maps {
namespace runtime {
namespace bindings {
namespace ios {
namespace internal {

template <>
struct ToNative<::yandex::maps::mapkit::geometry::Subpolyline, YMKSubpolyline, void> {
    static ::yandex::maps::mapkit::geometry::Subpolyline from(
        YMKSubpolyline* platformSubpolyline);
};

template <typename PlatformType>
struct ToNative<::yandex::maps::mapkit::geometry::Subpolyline, PlatformType,
        typename std::enable_if<
            std::is_convertible<PlatformType, YMKSubpolyline*>::value>::type> {
    static ::yandex::maps::mapkit::geometry::Subpolyline from(
        PlatformType platformSubpolyline)
    {
        return ToNative<::yandex::maps::mapkit::geometry::Subpolyline, YMKSubpolyline>::from(
            platformSubpolyline);
    }
};

template <>
struct ToPlatform<::yandex::maps::mapkit::geometry::Subpolyline> {
    static YMKSubpolyline* from(
        const ::yandex::maps::mapkit::geometry::Subpolyline& subpolyline);
};

} // namespace internal
} // namespace ios
} // namespace bindings
} // namespace runtime
} // namespace maps
} // namespace yandex







namespace yandex {
namespace maps {
namespace runtime {
namespace bindings {
namespace ios {
namespace internal {

template <>
struct ToNative<::yandex::maps::mapkit::geometry::Geometry, id, void> {
    static ::yandex::maps::mapkit::geometry::Geometry from(
        id platformGeometry);
};

template <typename PlatformType>
struct ToNative<::yandex::maps::mapkit::geometry::Geometry, PlatformType,
        typename std::enable_if<
            std::is_convertible<PlatformType, id>::value>::type> {
    static ::yandex::maps::mapkit::geometry::Geometry from(
        PlatformType platformGeometry)
    {
        return ToNative<::yandex::maps::mapkit::geometry::Geometry, id>::from(
            platformGeometry);
    }
};

template <>
struct ToPlatform<::yandex::maps::mapkit::geometry::Geometry> {
    static id from(
        const ::yandex::maps::mapkit::geometry::Geometry& geometry);
};

} // namespace internal
} // namespace ios
} // namespace bindings
} // namespace runtime
} // namespace maps
} // namespace yandex
