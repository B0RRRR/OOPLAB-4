#pragma once

#include <concepts>
#include <iostream>

namespace geometry {

template <typename T>
concept Scalar = std::is_scalar_v<T>;

template <Scalar T>
class Point {
 public:
  T x{};
  T y{};

  Point() = default;
  Point(T x_val, T y_val);

  bool operator==(const Point<T>& other) const;
  friend std::ostream& operator<<(std::ostream& os, const Point<T>& p) {
    os << "(" << p.x << ", " << p.y << ")";
    return os;
  }
};

}  // namespace geometry
