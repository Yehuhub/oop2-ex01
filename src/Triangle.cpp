#include "Triangle.h"
#include <iostream>

Triangle::Triangle(double x): Shape(x), m_name("Triangle"){};

void Triangle::draw()const{
    draw(1);
}
    
void Triangle::draw(double factor)const{
    int side = (int)(factor * getX());

    for(int i = 1 ; i <= side; i++){
        if(i != side){
            //print space in left indentation
            for(int j = 1; j <= side - i ;j++){
                std::cout<<" ";
            }
            std::cout<<"*";
            //fill out middle with spaces
            for(int j = 1; j <= 2*(i-1) - 1; j++){
                std::cout<<" ";
            }
            if(i != 1){
                std::cout<<"*";
            }
            std::cout<<std::endl;
        }
        else{
            for(int j = 0; j < side ; j++){
                std::cout<<"* ";
            }
            std::cout<< std::endl;
        }

    }
}

std::string Triangle::getName(double factor)const {
    std::string myName(m_name);
    int newFact =(int) (factor * getX());

    myName+="(" + std::to_string(newFact)+ ")";
    return myName;
}

std::string Triangle::getName()const{
    return getName(1);
}