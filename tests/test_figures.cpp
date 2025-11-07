#include <gtest/gtest.h>
#include <memory>

#include "triangle.hpp"
#include "square.hpp"
#include "rectangle.hpp"


TEST(TriangleTest, AreaAndCenter) {
  geometry::Triangle<double> t({0, 0}, {4, 0}, {2, 3});
  EXPECT_NEAR(static_cast<double>(t), 6.0, 1e-6);
  auto c = t.Center();
  EXPECT_NEAR(c.x, 2.0, 1e-6);
  EXPECT_NEAR(c.y, 1.0, 1e-6);
}

TEST(TriangleTest, Equality) {
  geometry::Triangle<int> t1({0, 0}, {2, 0}, {1, 2});
  geometry::Triangle<int> t2({0, 0}, {2, 0}, {1, 2});
  EXPECT_TRUE(t1.operator==(t2));
}


TEST(SquareTest, AreaAndCenter) {
  geometry::Square<double> s({0, 0}, {2, 0}, {2, 2}, {0, 2});
  EXPECT_NEAR(static_cast<double>(s), 4.0, 1e-6);
  auto c = s.Center();
  EXPECT_NEAR(c.x, 1.0, 1e-6);
  EXPECT_NEAR(c.y, 1.0, 1e-6);
}

TEST(SquareTest, Equality) {
  geometry::Square<int> s1({0, 0}, {1, 0}, {1, 1}, {0, 1});
  geometry::Square<int> s2({0, 0}, {1, 0}, {1, 1}, {0, 1});
  EXPECT_TRUE(s1.operator==(s2));
}


TEST(RectangleTest, AreaAndCenter) {
  geometry::Rectangle<double> r({0, 0}, {4, 0}, {4, 2}, {0, 2});
  EXPECT_NEAR(static_cast<double>(r), 8.0, 1e-6);
  auto c = r.Center();
  EXPECT_NEAR(c.x, 2.0, 1e-6);
  EXPECT_NEAR(c.y, 1.0, 1e-6);
}

TEST(RectangleTest, Equality) {
  geometry::Rectangle<int> r1({0, 0}, {2, 0}, {2, 1}, {0, 1});
  geometry::Rectangle<int> r2({0, 0}, {2, 0}, {2, 1}, {0, 1});
  EXPECT_TRUE(r1.operator==(r2));
}
