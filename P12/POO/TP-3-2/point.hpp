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

    coordonee getX() const {return _x;};
    coordonee getY() const {return _y;};

    void afficher() const;
    bool equals(point const & p) const;
    void translation(point const & direction);

};
