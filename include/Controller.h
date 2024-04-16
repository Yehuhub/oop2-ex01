#pragma once

#include "Shape.h"
#include "Triangle.h"
#include "Square.h"
#include "Rectangle.h"
#include "DupedShape.h"
#include "StackedShape.h"


#include <vector>
#include <string>
#include <memory>


class Controller{
public:
    Controller() = default;

    void runningLoop();

    void create(std::shared_ptr<Shape> shape);
    void enlarge(int shapeNum, int n)const;
    void reduce(int shapeNum, int n)const;
    void duplicate(int shapeNum, int amnt);
    void stack(int firstShapeNum, int secondShapeNum);
    void deleteShape(int shapeNum);
    void draw(int shapeNum)const;
    void help()const;
    void exitProgram()const;
    bool indexValidity(int num)const;
    

private:
    std::vector<std::shared_ptr<Shape>> m_shapes;
};