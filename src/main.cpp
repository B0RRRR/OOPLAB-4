#include <iostream>
#include <memory>
#include <iomanip>
#include <limits>

#include "point.hpp"
#include "triangle.hpp"
#include "square.hpp"
#include "rectangle.hpp"
#include "array.hpp"

int main() {
    std::cout << std::fixed << std::setprecision(3);

    geometry::Array<std::shared_ptr<geometry::Figure<double>>> figures;

    while (true) {
        std::cout << "1. Добавить фигуру\n"
                  << "2. Посчитать площадь\n"
                  << "0. Выход\n> ";

        int choice;
        std::cin >> choice;

        if (choice == 0) break;

        switch (choice) {
            case 1: {
                std::cout << "1. Треугольник\n"
                          << "2. Квадрат\n"
                          << "3. Прямоугольник\n> ";


                int type;
                std::cin >> type;
                if (!std::cin) {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    continue;
                }

                if (type == 1) {
                    double x1, y1, x2, y2, x3, y3;
                    std::cout << "(x1 y1 x2 y2 x3 y3): ";
                    std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
                    if (!std::cin) {
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        continue;
                    }
                    figures.PushBack(std::make_shared<geometry::Triangle<double>>(
                        geometry::Point<double>{x1, y1}, 
                        geometry::Point<double>{x2, y2}, 
                        geometry::Point<double>{x3, y3}));
                } 
                else if (type == 2) {
                    double x, y, side;
                    std::cout << "(x y side): ";
                    std::cin >> x >> y >> side;
                    if (!std::cin) {
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        continue;
                    }

                    double h = side / 2.0;
                    figures.PushBack(std::make_shared<geometry::Square<double>>(
                        geometry::Point<double>{x - h, y - h},
                        geometry::Point<double>{x + h, y - h},
                        geometry::Point<double>{x + h, y + h},
                        geometry::Point<double>{x - h, y + h}));
                } 
                else if (type == 3) {
                    double x, y, w, h;
                    std::cout << "(x y w h): ";
                    std::cin >> x >> y >> w >> h;
                    if (!std::cin) {
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        continue;
                    }

                    double hw = w / 2.0, hh = h / 2.0;
                    figures.PushBack(std::make_shared<geometry::Rectangle<double>>(
                        geometry::Point<double>{x - hw, y - hh},
                        geometry::Point<double>{x + hw, y - hh},
                        geometry::Point<double>{x + hw, y + hh},
                        geometry::Point<double>{x - hw, y + hh}));
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

            default:
                std::cout << "Неверный выбор\n";
                break;
        }
    }

    return 0;
}
