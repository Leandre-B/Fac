#pragma once

using coordonee = int;

class point
{
private:
    coordonee _x;
    coordonee _y;
public:
    point();
    point(coordonee x, coordonee y);
    point(point const & p);
    ~point();

};
