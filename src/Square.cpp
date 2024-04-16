#include "Square.h"
#include <iostream>

Square::Square(double x): Shape(x), m_name("Square"){};

void Square::draw()const{
    draw(1);
}
void Square::draw(double factor)const{
    
    int x = (int)(getX() * factor);

        for(int i = 0; i < x ; i++){
            for(int j = 0; j < x; j++){
                if(i == 0 || i == x - 1){
                    std::cout<< "* ";
                }
                else if(j == 0 || j == x - 1){
                    std::cout<< "* ";
                }
                else{
                    std::cout<< "  ";
                }
            }
            std::cout<< std::endl;
        }
}

std::string Square::getName(double factor)const {
    std::string myName(m_name);
    int newFact = (int) factor * getX();

    myName+="(" + std::to_string(newFact)+ ")";
    return myName;
}

std::string Square::getName()const{
    return getName(1);
}