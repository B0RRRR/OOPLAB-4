#include <sstream>

#include "triangle.hpp"

namespace geometry {

template <typename T>
Triangle<T>::Triangle(const Point<T>& a, const Point<T>& b, const Point<T>& c)
    : vertices_{a, b, c} {}

template <typename T>
double Triangle<T>::Area() const {
  double x1 = vertices_[0].x, y1 = vertices_[0].y;
  double x2 = vertices_[1].x, y2 = vertices_[1].y;
  double x3 = vertices_[2].x, y3 = vertices_[2].y;
  return std::abs((x1*(y2 - y3) + x2*(y3 - y1) + x3*(y1 - y2)) / 2.0);
}

template <typename T>
Point<T> Triangle<T>::Center() const {
  return {(vertices_[0].x + vertices_[1].x + vertices_[2].x) / 3,
          (vertices_[0].y + vertices_[1].y + vertices_[2].y) / 3};
}

template <typename T>
std::vector<Point<T>> Triangle<T>::Vertices() const {
  return {vertices_[0], vertices_[1], vertices_[2]};
}

template <typename T>
bool Triangle<T>::operator==(const Figure<T>& other) const {
    if (auto p = dynamic_cast<const Triangle<T>*>(&other)) {
        return vertices_ == p->vertices_;
    }
    return false;
}

template <typename T>
Triangle<T>::operator double() const {
  return Area();
}

template <typename T>
void Triangle<T>::Print(std::ostream& os) const {
  os << "Triangle: " << this->ToString() << "\n";
}

template class Triangle<int>;
template class Triangle<float>;
template class Triangle<double>;

}  // namespace geometry
