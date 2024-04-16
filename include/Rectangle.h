#pragma once

#include "Shape.h"

class Rectangle : public Shape{
public:
    Rectangle(double x, double y);
    virtual ~Rectangle() = default;

    virtual void enlarge(int n)override;
    virtual void reduce(int n)override; 
    virtual std::string getName(double factor) const override;
    std::string getName()const override;

    virtual void draw(double factor) const override;
    virtual void draw()const override;

private:
    double m_y;
    std::string m_name;
};
