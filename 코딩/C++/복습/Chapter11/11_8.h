#ifndef CIRCLE_2D
#define CIRCLE_2D

class Circle2D
{
    public:
    Circle2D();
    Circle2D(double, double, double);

    double getX() const;
    double getY() const;
    double getRadius() const;

    double getArea() const;
    double getPerimeter() const;
    bool contains(double, double) const;
    bool contains(const Circle2D&) const;
    bool overlaps(const Circle2D&) const;

    private:
    double x;
    double y;
    double radius;
};

#endif