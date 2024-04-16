#include "Rectangle.h"
#include <iostream>

Rectangle::Rectangle(double x, double y): Shape(x), m_y(y), m_name("Rectangle"){}

void Rectangle::draw()const{
    draw(1);

}
void Rectangle::draw(double factor)const{
    int width = (int)(getX() * factor);
    int height = (int)(m_y * factor);

        for(int i = 0; i < height ; i++){
            for(int j = 0; j < width; j++){
                if(i == 0 || i == height - 1){
                    std::cout<< "* ";
                }
                else if(j == 0 || j == width - 1){
                    std::cout<< "* ";
                }
                else{
                    std::cout<< "  ";
                }
            }
            std::cout<< std::endl;
        }
}

void Rectangle::enlarge(int n){
    m_y = m_y * n;
    setX(getX() * n);
}
void Rectangle::reduce(int n){
    m_y = m_y / n;
    setX(getX() / n);
} 

std::string Rectangle::getName(double factor)const {
    std::string myName(m_name);
    int wFact = (int)(factor * getX());
    int hFact = (int)(factor * m_y);

    myName+="(w: " + std::to_string(wFact)+ ", h: " + std::to_string(hFact) + ")";
    return myName;
}

std::string Rectangle::getName()const{
    return getName(1);
}