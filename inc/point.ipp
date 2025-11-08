#pragma once

namespace geometry {

template <Scalar T>
Point<T>::Point(T x_val, T y_val) : x(x_val), y(y_val) {}

template <Scalar T>
bool Point<T>::operator==(const Point<T>& other) const {
    return x == other.x && y == other.y;
}

} // namespace geometry
