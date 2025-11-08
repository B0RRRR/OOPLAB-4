#pragma once

#include <array>
#include <vector>

#include "figure.hpp"

namespace geometry {

template <typename T>
class Square : public Figure<T> {
public:
    Square(const Point<T>& a, const Point<T>& b,
           const Point<T>& c, const Point<T>& d);

    double Area() const override;
    Point<T> Center() const override;
    std::vector<Point<T>> Vertices() const override;

    bool operator==(const Figure<T>& other) const override;
    explicit operator double() const override;
    void Print(std::ostream& os) const override;

private:
    std::array<Point<T>, 4> vertices_;
};

} // namespace geometry

#include "square.ipp"
