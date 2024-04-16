#pragma once

#include <string>

class Shape{

public:
    Shape() = default;
    Shape(double x);
    virtual ~Shape() = default;

    virtual void draw(double factor)const = 0; 
    virtual void draw()const = 0; 
    virtual std::string getName(double factor) const = 0;
    virtual std::string getName() const = 0;
    
    
    virtual void enlarge(int n);
    virtual void reduce(int n); 
    double getX()const;
    void setX(double x);

private:
    //size of shape, in rect is width
    double m_x;
};