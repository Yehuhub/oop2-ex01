#pragma once

#include "Shape.h"

class Triangle : public Shape{
public:
    Triangle(double x);
    virtual ~Triangle() = default;

    std::string getName(double factor)const override;
    std::string getName()const override;
    virtual void draw(double factor)const override;
    virtual void draw()const override;

private:
    std::string m_name;
};