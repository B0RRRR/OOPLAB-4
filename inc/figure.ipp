#pragma once

#include <sstream>
#include <iomanip>

namespace geometry {

template <typename T>
std::string Figure<T>::ToString() const {
  std::ostringstream oss;
  oss << "Center: " << Center()
      << ", Area: " << Area();
  return oss.str();
}

} // namespace geometry
