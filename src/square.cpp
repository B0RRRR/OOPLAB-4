#include <cmath>
#include <sstream>

#include "square.hpp"

namespace geometry {

template <typename T>
Square<T>::Square(const Point<T>& a, const Point<T>& b, const Point<T>& c, const Point<T>& d)
    : vertices_{a, b, c, d} {}

template <typename T>
double Square<T>::Area() const {
  double side = std::hypot(vertices_[1].x - vertices_[0].x,
                           vertices_[1].y - vertices_[0].y);
  return side * side;
}

template <typename T>
Point<T> Square<T>::Center() const {
  double x = 0, y = 0;
  for (const auto& v : vertices_) {
    x += v.x;
    y += v.y;
  }
  return { T(x / T(4)), T(y / T(4)) };
}

template <typename T>
std::vector<Point<T>> Square<T>::Vertices() const {
  return {vertices_[0], vertices_[1], vertices_[2], vertices_[3]};
}

template <typename T>
bool Square<T>::operator==(const Figure<T>& other) const {
    if (auto p = dynamic_cast<const Square<T>*>(&other)) {
        return vertices_ == p->vertices_;
    }
    return false;
}

template <typename T>
Square<T>::operator double() const {
  return Area();
}

template <typename T>
void Square<T>::Print(std::ostream& os) const {
  os << "Square: " << this->ToString() << "\n";
}

template class Square<int>;
template class Square<float>;
template class Square<double>;

}  // namespace geometry
