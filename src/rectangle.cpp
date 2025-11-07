#include <sstream>
#include <cmath>

#include "rectangle.hpp"

namespace geometry {

template <typename T>
Rectangle<T>::Rectangle(const Point<T>& a, const Point<T>& b,
                        const Point<T>& c, const Point<T>& d)
    : vertices_{a, b, c, d} {}

template <typename T>
double Rectangle<T>::Area() const {
  double width = std::hypot(vertices_[1].x - vertices_[0].x,
                            vertices_[1].y - vertices_[0].y);
  double height = std::hypot(vertices_[3].x - vertices_[0].x,
                             vertices_[3].y - vertices_[0].y);
  return width * height;
}

template <typename T>
Point<T> Rectangle<T>::Center() const {
  double x = 0, y = 0;
  for (const auto& v : vertices_) {
    x += v.x;
    y += v.y;
  }
  return { T(x / T(4)), T(y / T(4)) };
}

template <typename T>
std::vector<Point<T>> Rectangle<T>::Vertices() const {
  return {vertices_[0], vertices_[1], vertices_[2], vertices_[3]};
}

template <typename T>
bool Rectangle<T>::operator==(const Figure<T>& other) const {
    if (auto p = dynamic_cast<const Rectangle<T>*>(&other)) {
        return vertices_ == p->vertices_;
    }
    return false;
}

template <typename T>
Rectangle<T>::operator double() const {
  return Area();
}

template <typename T>
void Rectangle<T>::Print(std::ostream& os) const {
  os << "Rectangle: " << this->ToString() << "\n";
}

// Явная инстанциация
template class Rectangle<int>;
template class Rectangle<float>;
template class Rectangle<double>;

}  // namespace geometry
