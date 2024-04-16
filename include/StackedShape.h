#pragma once 

#include "Shape.h"
#include <memory>
#include <vector>
#include <string>

class StackedShape : public Shape{
public:
    StackedShape(const std::shared_ptr<Shape>& first, const std::shared_ptr<Shape>& second);
    virtual ~StackedShape() = default;

    virtual void draw(double factor)const override; 
    virtual void draw()const override; 
    virtual std::string getName(double factor)const override;
    virtual std::string getName()const override;
    
    
    virtual void enlarge(int n)override;
    virtual void reduce(int n)override; 

private:
    std::vector<std::shared_ptr<Shape>> m_shapes;
    double m_factor;
};