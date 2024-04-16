#include "Shape.h"
#include <iostream>//remove after testing

Shape::Shape(double x): m_x(x){};

void Shape::enlarge(int n){
    m_x = n * m_x;
}

void Shape::reduce(int n){
    m_x = m_x/n;
}

double Shape::getX()const{
    return m_x;
}

void Shape::setX(double x){
    m_x = x;
}