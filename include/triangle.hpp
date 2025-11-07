#pragma once

#include <array>
#include <cmath>

#include "figure.hpp"

namespace geometry {

template <typename T>
class Triangle : public Figure<T> {
 public:
  Triangle(const Point<T>& a, const Point<T>& b, const Point<T>& c);
  double Area() const override;
  Point<T> Center() const override;
  std::vector<Point<T>> Vertices() const override;
  bool operator==(const Figure<T>& other) const override;
  explicit operator double() const override;
  void Print(std::ostream& os) const override;

 private:
  std::array<Point<T>, 3> vertices_;
};

}  // namespace geometry
