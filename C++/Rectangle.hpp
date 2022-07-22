#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

class Rectangle
{
  private:
  double width_{};
  double height_{};
  public:
  Rectangle()=default;
  Rectangle(double width, double height);

  double Width() const;
  double Height() const;

  double Area() const;

  double Perimeter() const;

  void Scale(double scaleFactor);
};
#endif 