#include "StackedShape.h"

StackedShape::StackedShape(const std::shared_ptr<Shape>& first, const std::shared_ptr<Shape>& second)
    :m_factor(1){
        m_shapes.push_back(first);
        m_shapes.push_back(second);
}

void StackedShape::draw(double factor)const{
    for(auto& shape: m_shapes){
        shape->draw(m_factor * factor);
    }
}

void StackedShape::draw()const{
    draw(1);
}

std::string StackedShape::getName(double factor)const{
    std::string name = "(";
    name += m_shapes[0]->getName(m_factor * factor) + " / " + m_shapes[1]->getName(m_factor * factor) + ")";
    return name;
}

std::string StackedShape::getName()const{
    return getName(1);
}

void StackedShape::enlarge(int n){
    m_factor *= n;
}

void StackedShape::reduce(int n){
    m_factor /= n;
}
    