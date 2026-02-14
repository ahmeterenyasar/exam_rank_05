#include "vect2.hpp"

    vect2::vect2(int x, int y) : x(x), y(y) {};

    int& vect2::operator[](int i) { return (i == 0) ? x : y; }
    int vect2::operator[](int i) const { return (i == 0) ? x : y; }

    vect2& vect2::operator++() { x++; y++; return *this; }
    vect2 vect2::operator++(int) { vect2 tmp = *this; ++(*this); return tmp; }
    vect2& vect2::operator--() { x--; y--; return *this; }
    vect2 vect2::operator--(int) { vect2 tmp = *this; --(*this); return tmp; }

    vect2& vect2::operator+=(const vect2& rhs) { x += rhs.x; y += rhs.y; return *this; }
    vect2& vect2::operator-=(const vect2& rhs) { x -= rhs.x; y -= rhs.y; return *this; }
    vect2& vect2::operator*=(int val) { x *= val; y *= val; return *this; }

    vect2 vect2::operator+(const vect2& rhs) const { return vect2(*this) += rhs; }
    vect2 vect2::operator-(const vect2& rhs) const { return vect2(*this) -= rhs; }

    vect2 vect2::operator*(int val) const { return vect2(*this) *= val; }
    vect2 vect2::operator-() const { return vect2(-x, -y); }

    bool vect2::operator==(const vect2& rhs) const { return (x == rhs.x) && (y == rhs.y); }
    bool vect2::operator!=(const vect2& rhs) const { return !(*this == rhs); }

std::ostream& operator<<(std::ostream& os, const vect2& v)
{
    os << "{" << v[0] << ", " << v[1] << "}";
    return os;
}
vect2 operator*(int val, const vect2& v)
{
    return v * val;
}