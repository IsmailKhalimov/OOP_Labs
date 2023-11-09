#pragma once

#include "figure.hpp"
#include "point.hpp"

class Romb : public Figure {
private:
    Point points[4];
public:
    Romb() = default;
    Romb(std::istream &is);

    void Print(std::ostream &os) const override;
    double Square() const;
    Point Center() const override;
   
    Figure& operator=(const Figure& other) override; // Конструктор копирования
    Figure& move(Figure&& other) noexcept override; // Конструктор перемещения
    bool operator==(const Figure& other) const override; // Оператор сравнения
    
    virtual ~Romb() = default;
};
