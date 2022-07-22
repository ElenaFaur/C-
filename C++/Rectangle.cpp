#include "Rectangle.hpp"

Rectangle::Rectangle(double width, double height): width_{width},height_{height}{}

double Rectangle::Width() const
{
    return width_;
}
double Rectangle::Height() const
{
    return height_;
}
double Rectangle::Area() const
{
    return width_*height_;
}
double Rectangle::Perimeter() const
{
    return 2.0*(width_+height_);
}
void Rectangle::Scale(double scaleFactor)
{
    width_*=scaleFactor;
    height_*=scaleFactor;
}