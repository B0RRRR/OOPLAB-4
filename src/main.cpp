#include <iostream>
#include <memory>
#include <iomanip>

#include "point.hpp"
#include "triangle.hpp"
#include "square.hpp"
#include "rectangle.hpp"
#include "array.hpp"

using namespace geometry;

int main() {
    std::cout << std::fixed << std::setprecision(3);

    Array<std::shared_ptr<Figure<double>>> figures;

    while (true) {
        std::cout << "1. Добавить фигуру\n"
                  << "2. Посчитать суммарную площадь\n"
                  << "0. Выход\n> ";

        int choice;
        std::cin >> choice;
        if (!std::cin || choice == 0) break;

        switch (choice) {
            case 1: {
                std::cout << "1. Треугольник\n"
                          << "2. Квадрат\n"
                          << "3. Прямоугольник\n> ";

                int type;
                std::cin >> type;

                if (type == 1) {
                    double x1, y1, x2, y2, x3, y3;
                    std::cout << "(x1 y1 x2 y2 x3 y3): ";
                    std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
                    figures.PushBack(std::make_shared<Triangle<double>>(
                        Point<double>{x1, y1}, Point<double>{x2, y2}, Point<double>{x3, y3}));
                } 
                else if (type == 2) {
                    double x, y, side;
                    std::cout << "x y side: ";
                    std::cin >> x >> y >> side;

                    double h = side / 2.0;
                    figures.PushBack(std::make_shared<Square<double>>(
                        Point<double>{x - h, y - h},
                        Point<double>{x + h, y - h},
                        Point<double>{x + h, y + h},
                        Point<double>{x - h, y + h}));
                } 
                else if (type == 3) {
                    double x, y, w, h;
                    std::cout << "x y w h: ";
                    std::cin >> x >> y >> w >> h;

                    double hw = w / 2.0, hh = h / 2.0;
                    figures.PushBack(std::make_shared<Rectangle<double>>(
                        Point<double>{x - hw, y - hh},
                        Point<double>{x + hw, y - hh},
                        Point<double>{x + hw, y + hh},
                        Point<double>{x - hw, y + hh}));
                }

                break;
            }

            case 2: {
                double total = 0.0;
                for (std::size_t i = 0; i < figures.Size(); ++i)
                    total += figures[i]->Area();
                std::cout << total << "\n";
                break;
            }
        }
    }

    return 0;
}
