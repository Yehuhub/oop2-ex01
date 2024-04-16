#pragma once

#include "Shape.h"
#include <memory>
#include <vector>
#include <string>

class DupedShape : public Shape{
public:
    DupedShape(const std::shared_ptr<Shape>& shape, int amnt);
    virtual ~DupedShape() = default;
    
    virtual void draw(double factor)const override; 
    virtual void draw()const override; 
    virtual std::string getName(double factor)const override;
    virtual std::string getName()const override;
    
    
    virtual void enlarge(int n)override;
    virtual void reduce(int n)override; 

private:
    std::shared_ptr<Shape> m_shape;
    int m_amnt;
    double m_factor;
};