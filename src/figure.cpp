#include <sstream>
#include <iomanip>

#include "figure.hpp"

namespace geometry {

template <typename T>
std::string Figure<T>::ToString() const {
  std::ostringstream oss;
  oss << "Center: " << Center()
      << ", Area: " << Area();
  return oss.str();
}


template class Figure<int>;
template class Figure<float>;
template class Figure<double>;

}  // namespace geometry
