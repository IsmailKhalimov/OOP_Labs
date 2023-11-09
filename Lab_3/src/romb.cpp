#include "romb.hpp"

Romb::Romb(std::istream &is) {
    for (int i = 0; i < 4; i++) {
        is >> points[i];
    }
}

void Romb::Print(std::ostream &os) const {
    for (const auto& p :points) {
        os << p << " ";
    }
    os << std::endl;
}

double Romb::Square() const {
    double result = 0;
    for(unsigned i = 0; i < 4; ++i) {
        Point p1 = i ? points[i - 1] : points[3];
        Point p2 = points[i];
        result += (p1.getX() - p2.getX()) * (p1.getY() + p2.getY());
    }
    return fabs(result) / 2.0;
}

Figure& Romb::operator=(const Figure& other){
    const Romb* otherRomb = dynamic_cast<const Romb*>(&other);
    for (int i = 0; i < 5; ++i) {
        points[i] = otherRomb->points[i];
    }
    return *this;
}

Figure& Romb::move(Figure&& other) noexcept {
    const Romb* otherRomb = dynamic_cast<const Romb*>(&other);
    for (int i = 0; i < 5; ++i) {
        points[i] = std::move(otherRomb->points[i]);
    }
    return *this;
}

bool Romb::operator==(const Figure& other) const {
    const Romb* otherRomb = dynamic_cast<const Romb*>(&other);
    for (int i = 0; i < 5; ++i) {
        if (points[i].getX() != otherRomb->points[i].getX() || points[i].getY() != otherRomb->points[i].getY()) {
            return false;
        }
    }
    return true;
}

Point Romb::Center() const {
    double centerX = 0.0;
    double centerY = 0.0;

    for (const Point& point : points) {
        centerX += point.getX();
        centerY += point.getY();
    }

    centerX /= 4.0;
    centerY /= 4.0;

    return Point(centerX, centerY);
}

