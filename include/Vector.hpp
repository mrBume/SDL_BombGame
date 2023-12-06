#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>

struct Vect2D
{
    Vect2D()
    {
        x = 0;
        y = 0;
    }

    Vect2D(int px, int py)
    {
        x = px;
        y = py;
    }

    Vect2D(Vect2D &vect)
    {
        x = vect.x;
        y = vect.y;
    }

    Vect2D operator+(Vect2D const &op)
    {
        return Vect2D(x + op.x, y + op.y);
    }

    friend std::ostream &operator<<(std::ostream &os, Vect2D &vect)
    {
        os << "{ " << vect.x << ", " << vect.y << " }";
        return os;
    }

    int x;
    int y;
};

#endif // VECTOR_HPP
