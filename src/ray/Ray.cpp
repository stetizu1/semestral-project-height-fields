#include "Ray.h"

Ray::Ray(const Point3d &origin, const Vector3d &direction) : origin(origin), direction(direction) {}

Point3d Ray::getPointOnParameter(const float t) const {
  return origin + t * direction;
}
std::string Ray::to_string() const {
  return "ray(" + origin.to_string() + " --> " + direction.to_string() + ")";
}

std::ostream &operator<<(std::ostream &stream, const Ray &ray) {
  stream << ray.to_string();
  return stream;
}
