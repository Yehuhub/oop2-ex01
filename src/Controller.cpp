#include "Controller.h"
#include "Commands.h"
#include <iostream>



void Controller::create(std::shared_ptr<Shape> shape){
    m_shapes.push_back(shape);
}

void Controller::enlarge(int shapeNum, int n)const{
    m_shapes[shapeNum]->enlarge(n);
}

void Controller::reduce(int shapeNum, int n)const{
    m_shapes[shapeNum]->reduce(n);
}

void Controller::duplicate(int shapeNum, int amnt){
    m_shapes.push_back(std::make_shared<DupedShape>(m_shapes[shapeNum], amnt));
}

void Controller::stack(int firstShapeNum, int secondShapeNum){
    m_shapes.push_back(std::make_shared<StackedShape>(m_shapes[firstShapeNum], m_shapes[secondShapeNum]));
}

void Controller::draw(int shapeNum)const{
    m_shapes[shapeNum]->draw();
}

void Controller::deleteShape(int shapeNum){
    m_shapes.erase(m_shapes.begin() + shapeNum);
}

void Controller::help()const{
    std::cout<<"The available commands are:\n * cre(ate shape) <t - triangle | r - rectangle | s - square> x [y] -\n";
    std::cout<<"create new shape according to the chosen letter, with the given size(s) (y must be given only for a rectangle)\n";
    std::cout<<"* en(large) num n - enlarge the size of the sides of shape #num by n (1-10)\n";
    std::cout<<"* red(uce) num n - reduce the size of the sides of shape #num by n (1-10)\n";
    std::cout<<"* draw num - draw shape #num\n";
    std::cout<<"* dup(licate) num n - create a new shape which is a n times (vertical) duplication of shape #num\n";
    std::cout<<"* stack num1 num2 - create a new shape by stacking shape number #num1 over shape number #num2\n";
    std::cout<<"* del(ete) num - delete shape #num from the shape list\n";
    std::cout<<"* help - print this command list\n";
    std::cout<<"* exit - exit the program\n";

}

void Controller::exitProgram()const{
    std::cout<<"Goodbye"<<std::endl;
    exit(EXIT_SUCCESS);
}

void Controller::runningLoop(){
    std::string userCmd;


    while(1){

        if(m_shapes.size() == 0){
            std::cout<<"No Shapes in list"<<std::endl;
        }
        else{
            for(size_t i = 0 ; i < m_shapes.size(); i++){
                std::cout<<i<<".    "<<m_shapes[i]->getName()<<std::endl;
            }
        }
        std::cout<<"Enter command ('help' for list of available commands): ";
        std::cin >> userCmd;

        //if userCmd is in the commands map
        if(commands.find(userCmd) != commands.end()){
            int run = commands[userCmd];
            char type;
            int param1, param2;
            double size, size2;

            switch((cmdLst)run){
                case cre:
                    std::cin >> type >>size;//need to figure out which shape to create
                    switch(type){
                        case 't':
                            create(std::make_shared<Triangle>(size));
                            break;
                        case 's':
                            create(std::make_shared<Square>(size));
                            break;
                        case 'r':
                            std::cin>>size2;
                            create(std::make_shared<Rectangle>(size, size2));
                            break;
                        default:
                            std::cout<<"Wrong shape"<<std::endl;
                            break;
                    }
                    break;

                case en:
                    std::cin>> param1>>param2;
                    if(indexValidity(param1)){
                        if(param2 <= 10 && param2 >= 1)
                            enlarge(param1, param2);
                        else    
                            std::cout<<"Enlarge factor not in range"<<std::endl;
                    }
                    break;
                case red:
                    std::cin>> param1>>param2;
                    if(indexValidity(param1)){
                        if(param2 <= 10 && param2 >= 1)
                            reduce(param1, param2);
                        else
                            std::cout<<"Reduce factor not in range"<<std::endl;
                    }
                    break;
                case dra:
                    std::cin>>param1;
                    if(indexValidity(param1)){
                        draw(param1);
                    }
                    break;
                case sta:
                    std::cin>> param1>>param2;
                    if(indexValidity(param1) && indexValidity(param2)){
                        stack(param1, param2);
                    }
                    break;
                case dup:
                    std::cin>> param1 >> param2;
                    if(indexValidity(param1)){
                        duplicate(param1, param2);
                    }
                    break;
                case del:
                    std::cin>>param1;
                    if(indexValidity(param1)){
                        deleteShape(param1);
                    }
                    break;
                case hel:
                    help();
                    break;
                case ex:
                    exitProgram();
                    break;
                default:
                    break;
            }
        }else{
            std::cout<<"invalid command"<<std::endl;
        }
    }
    
}

bool Controller::indexValidity(int num)const{
    if(m_shapes.size() <= num){
        std::cout<<"Invalid item #num"<<std::endl;
        return false;
    }
    return true;
}