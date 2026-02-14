#ifndef VECT2_HPP
#define VECT2_HPP

#include <iostream>

class vect2
{
private:
    int x, y;
public:
    vect2(int x = 0, int y = 0);
    ~vect2() {}

    int& operator[](int i);
    int operator[](int i) const;

    vect2& operator++();
    vect2 operator++(int);
    vect2& operator--();
    vect2 operator--(int);

    vect2& operator+=(const vect2& rhs);
    vect2& operator-=(const vect2& rhs);
    vect2& operator*=(int val);

    vect2 operator+(const vect2& rhs) const;
    vect2 operator-(const vect2& rhs) const;

    vect2 operator*(int val) const;
    vect2 operator-() const;

    bool operator==(const vect2& rhs) const;
    bool operator!=(const vect2& rhs) const;
};

std::ostream& operator<<(std::ostream& os, const vect2& v);
vect2 operator*(int val, const vect2& v);

#endif