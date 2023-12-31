#include <iostream>
#include "figures.hpp"

int get_command() {
    int command;
    std::cin >> command;
    return command;
}

int main() {
    int command1, command2;

    Figures figuresArray;

    std::cout << "1 - add figure to the array\n"
                 "2 - delete figure from the array\n"
                 "3 - call common functions for the whole array\n"
                 "4 - get total area of figures in the array\n"
                 "0 - exit\n";

    while (true) {
        command1 = get_command();
        if (command1 == 1) {
            Figure* f;
            std::cout << "1 - Romb, 2 - Hexagon, 3 - Octagon" << std::endl;
            std::cin >> command2;
             if(command2 == 1) {
                    f = new Romb(std::cin);
                } else if(command2 == 2) {
                    f = new Hexagon(std::cin);
                } else if(command2 == 3) {
                    f = new Octagon(std::cin);
                } else {
                    std::cout << "Wrong input" << std::endl;
                }
            if (f) {
                figuresArray.addFigure(f);
            }
            std::cout << "Success" << std::endl;
        } else if (command1 == 2) {
            std::cout << "Enter index" << std::endl;
            std::cin >> command2;
            figuresArray.deleteFigureAtIndex(command2);
            std::cout << "Success" << std::endl;
        } else if (command1 == 3) {
            // Вызов методов для каждой фигуры в массиве
            for (size_t i = 0; i < figuresArray.getSize(); ++i) {
                Figure* figure = figuresArray.getFigureForIndex(i);
                if (figure) {
                    figure->Print(std::cout);
                    std::cout << "Center: " << figure->Center() << std::endl;
                    std::cout << "Square: " << figure->Square() << std::endl;
                }
            }
            std::cout << "It's all" << std::endl;
        } else if (command1 == 4) {
            double totalArea = figuresArray.calculateTotalArea();
            std::cout << "Total area of figures: " << totalArea << std::endl;
        } else if (command1 == 0) {
            std::cout << "Bye" << std::endl;
            break;
        }
    }

    return 0;
}
