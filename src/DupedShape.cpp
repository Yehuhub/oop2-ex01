#include "DupedShape.h"

DupedShape::DupedShape(const std::shared_ptr<Shape>& shape, int amnt)
    :m_shape(shape),m_amnt(amnt), m_factor(1){}

void DupedShape::draw(double factor)const{
    for(int i = 0; i < m_amnt; i++){
        m_shape->draw(m_factor * factor);
    }
} 

void DupedShape::draw()const{
    draw(1);
} 

std::string DupedShape::getName(double factor)const{
    std::string name(std::to_string(m_amnt) + " * (");
    name += m_shape->getName(m_factor * factor) + ")";
    return name;
}

std::string DupedShape::getName()const{
    return getName(1);
}

void DupedShape::enlarge(int n){
    m_factor *= n;
}
void DupedShape::reduce(int n){
    m_factor /= n;
}