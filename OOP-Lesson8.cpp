#include <iostream>
#include <string>

//====================================
//          Task1
//====================================
/*
Написать шаблонную функцию div, которая должна вычислять результат деления двух
параметров и запускать исключение DivisionByZero, если второй параметр равен 0. В
функции main выводить результат вызова функции div в консоль, а также ловить исключения.
 */
template <typename T1, typename T2> float div (T1 divisible, T2 divider) {
    T1 result;
    if (divider==0)
        throw "DivisionByZero";
    result = divisible / divider;
    return result;
}
//====================================
//          Task2
//====================================
/*
Написать класс Ex, хранящий вещественное число x и имеющий конструктор по
вещественному числу, инициализирующий x значением параметра.

Написать класс Bar, хранящий вещественное число y (конструктор по умолчанию
инициализирует его нулем) и имеющий метод set с единственным вещественным параметром a.
Если y + a > 100, возбуждается исключение типа Ex с данными a*y, иначе в y заносится
значение a.

В функции main завести переменную класса Bar и в цикле в блоке try вводить
с клавиатуры целое n. Использовать его в качестве параметра метода set до тех пор, пока
не будет введено 0. В обработчике исключения выводить сообщение об ошибке, содержащее данные объекта
исключения*/

class Ex {
    float x;
public:
    Ex(float _x) : x(_x) {};
    ~Ex() {};
    float getError() const;
};

float Ex::getError()const {
    return x;
}

class Bar{
    float y;
public:
    Bar(float _y = 0) : y(_y) {}
    ~Bar() {}
    void set(float a);
    float get();
};

void Bar::set(float a) {
    if (a+y>100) {
        Ex Exc(a * y);
        throw Exc;
    }
    y = a;
    //std::cout<<"Bar.set! y=  "<<y<< std::endl; //- просто посмотреть
}
float Bar::get() {
    return y;
}

//====================================
//          Task3
//====================================
/*
 Написать класс «робот», моделирующий перемещения робота по сетке 10x10, у которого есть
метод, означающий задание переместиться на соседнюю позицию. Эти методы должны
запускать классы-исключения OffTheField, если робот должен уйти с сетки, и IllegalCommand,
если подана неверная команда (направление не находится в нужном диапазоне). Объект
исключения должен содержать всю необходимую информацию — текущую позицию и
направление движения. Написать функцию main, пользующуюся этим классом и
перехватывающую все исключения от его методов, а также выводящую подробную
информацию о всех возникающих ошибках.
 */

class OffTheField {
    int positionX;
    int positionY;
    std::string stepX;
    std::string stepY;
public:
    OffTheField(int _positionX,int _positionY,std::string _stepX,std::string _stepY) :
                positionX(_positionX), positionY(_positionY), stepX (_stepX),stepY(_stepY) {};
    ~OffTheField() {};
    int getError() const;
    };

    int OffTheField::getError()const {
        std::cout<<std::endl;
        std::cout<< "======================="<<std::endl;
        std::cout<< "OffTheField!"<<std::endl;
        std::cout<< "Robot cannot move:"<<std::endl;
        std::cout<< "X: from "<<positionX<<" to "<< positionX<<" + "<<stepX<<std::endl;
        std::cout<< "Y: from "<<positionY<<" to "<< positionY<<" + "<<stepY<<std::endl;
        std::cout<< "======================="<<std::endl;
        std::cout<<std::endl;
        return 1;
    }


class IllegalCommand {
    int positionX;
    int positionY;
    std::string stepX;
    std::string stepY;
public:
    IllegalCommand(int _positionX,int _positionY,std::string _stepX,std::string _stepY) :
            positionX(_positionX), positionY(_positionY), stepX (_stepX),stepY(_stepY) {};
    ~IllegalCommand() {};
    int getError() const;
};

int IllegalCommand::getError()const {
    std::cout<<std::endl;
    std::cout<< "======================="<<std::endl;
    std::cout<< "Illegal command!"<<std::endl;
    std::cout<< "Robot cannot move:"<<std::endl;
    std::cout<< "X: from "<<positionX<<" to "<< positionX<<" + "<<stepX<<std::endl;
    std::cout<< "Y: from "<<positionY<<" to "<< positionY<<" + "<<stepY<<std::endl;
    std::cout<< "======================="<<std::endl;
    std::cout<<std::endl;
    return 2;
}

class field{
    int Xsize;
    int Ysize;
    int firstX;
    int firstY;
    int lastX=Xsize-firstX;
    int lastY=Ysize-firstY;
public:
    field(int _Xsize=10, int _Ysize=10, int _firstX=0,int _firstY=0):
            Xsize(_Xsize), Ysize (_Ysize), firstX(_firstX), firstY(_firstY) {};
    ~field(){}

    void setSizeX (int X);
    void setSizeY (int Y);
    void setFirstX (int X);
    void setFirstY (int Y);

    int getSizeX ();
    int getSizeY ();
    int getFirstX ();
    int getFirstY ();
    int getLastX ();
    int getLastY ();
};

void field::setSizeX(int X){
    Xsize=X;
}

void field::setSizeY(int Y){
    Ysize=Y;
}

void field::setFirstX(int X){
     firstX=X;
}

void field::setFirstY(int Y){
     firstY=Y;
}

int field::getSizeX(){
    return Xsize;
}

int field::getSizeY(){
    return Ysize;
}

int field::getFirstX(){
    return firstX;
}

int field::getFirstY(){
    return firstY;
}

int field::getLastX(){
    return lastX;
}

int field::getLastY(){
    return lastY;
}

class Robot{
    int Xcoord;
    int Ycoord;
    field field;
public:
    Robot (int x=5, int y=5, int sizeX=10, int sizeY=10, int firstX=0, int firstY=0 ): Xcoord(x), Ycoord(y){
        field.setSizeX(sizeX);
        field.setSizeX(sizeY);
        field.setFirstX(firstX);
        field.setFirstY(firstY);
    }
    ~Robot(){}
    void setField(int );
    //void move(int X, int Y);
    void move(std::string X, std::string Y);
    int getPosition();
    void printPosition();
    void setPosition(int X, int Y);
    bool checkDigit(std::string step);
    void checkCommand(std::string stepX, std::string stepY);
    void checkOffTheField (std::string stepX, std::string stepY);
};

bool Robot::checkDigit(std::string step){
    bool result=true;
    for (int i=0; i<step.size(); ++i){
        if ((!isdigit(step[i]))) {
            return false;
        }
    }
    return true;
}

void Robot::checkCommand(std::string stepX, std::string stepY){
    if (!checkDigit(stepX)||!checkDigit(stepY)){
        IllegalCommand Exc1(Xcoord,Ycoord, stepX, stepY);
        throw Exc1.getError();
    }
    if (stoi(stepX)> field.getSizeX() ||stoi(stepY)>field.getSizeX()){
        IllegalCommand Exc1(Xcoord,Ycoord, stepX, stepY);
        throw Exc1.getError();
    }
}

void Robot::checkOffTheField(std::string stepX, std::string stepY){
    if ((Xcoord+stoi(stepX))> field.getLastX() || (Xcoord+stoi(stepX))<field.getFirstX() ||(Ycoord+stoi(stepY))>9 || (Ycoord+stoi(stepY))<0){
        OffTheField Exc2(Xcoord,Ycoord, stepX, stepY);
        throw Exc2.getError();
    }
}


int Robot::getPosition() {
    int position;
    position= (Xcoord<<5)+(Ycoord);
    return position;
}

void Robot::printPosition() {
    std::cout<<"current position:"<<std::endl;
    std::cout<< "X: " <<Xcoord<<" Y: "<<Ycoord<< std::endl;
}

void Robot::move(std::string stepX, std::string stepY){
    checkCommand(stepX,stepY);
    checkOffTheField(stepX, stepY);
    setPosition(stoi(stepX), stoi(stepX));
}
void Robot::setPosition(int X, int Y) {
    Xcoord+=X;
    Ycoord+=Y;
}



int main() {

    //====================================
    //          Task1
    //====================================

    float divisible;
    float divider;
    float result;
    std::cin>>divisible>>divider;
    try{
        result=div(divisible,divider);
        std::cout << result<< std::endl;
    }
    catch (const char* exp) {
        std::cerr<<exp<<std::endl;
        std::cerr<<"Murphy's third law in action"<<std::endl;
    }

    //====================================
    //          Task2
    //====================================

    Bar bar;
    float n;
    do{
        std::cin>> n;
        try {
            bar.set(n);
        }
        catch(const Ex& Exc){
            std::cerr<<"Ex.x= " <<Exc.getError()<< std::endl;
        }
    } while (n!=0);

    //====================================
    //          Task3
    //====================================

    Robot robot1;
    std::string stepX;
    std::string stepY;
    char m;
    do{
        robot1.printPosition();
        std::cout<<"set the increment of coordinates? y/n: ";
        std::cin>>m;
        if (m=='y') {
            std::cout<<"increment of coordinate X: ";
            std::cin >> stepX;
            std::cout<<" increment of coordinate Y: ";
            std::cin >> stepY;

            try {
                robot1.move(stepX, stepY);
            }
            catch (...) {
            }
        }
    } while (m!='n');




return 0;
}