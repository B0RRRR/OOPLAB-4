#pragma once

#include <memory>
#include <string>
#include <vector>
#include <type_traits>

#include "point.hpp"

namespace geometry {

template <typename T>
class Figure {
  static_assert(std::is_arithmetic_v<T>, "T must be an arithmetic type");

 public:
  virtual ~Figure() = default;

  virtual double Area() const = 0;
  virtual Point<T> Center() const = 0;
  virtual std::vector<Point<T>> Vertices() const = 0;

  virtual bool operator==(const Figure<T>& other) const = 0;
  virtual explicit operator double() const = 0;

  virtual std::string ToString() const;
  virtual void Print(std::ostream& os) const = 0;

 protected:
  Figure() = default;
};

}  // namespace geometry
