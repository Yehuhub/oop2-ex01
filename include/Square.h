#pragma once

#include "Shape.h"

class Square : public Shape{
public:
    Square(double x);
    virtual ~Square() = default;

    std::string getName(double factor)const override;
    std::string getName()const override;
    virtual void draw() const override;
    virtual void draw(double factor) const override;

private:
    std::string m_name;

};