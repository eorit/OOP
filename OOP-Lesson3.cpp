#include <iostream>
#include <cmath>


//======================================
//                Task1
//=======================================


/*1 Создать абстрактный класс Figure (фигура). Его наследниками являются классы Parallelogram
(параллелограмм) и Circle (круг). Класс Parallelogram — базовый для классов Rectangle
(прямоугольник), Square (квадрат), Rhombus (ромб). Для всех классов создать конструкторы.
Для класса Figure добавить чисто виртуальную функцию area() (площадь). Во всех остальных
классах переопределить эту функцию, исходя из геометрических формул нахождения
площади.*/
#define PI 3.1415926535

class Figure {
    float Area;
public:
    virtual float area() = 0;
    virtual void setArea();
    float getArea();
    virtual ~Figure() {}
};

void Figure::setArea() {
    Area = area();
}
float Figure::getArea() {
    return Area;
}

class Parallelogram:public Figure {
    float height;
    float base;
    float angle;
public:
    float area();
    Parallelogram(float _height, float _base, float _angle=90) :
        height(_height), base(_base), angle(_angle) {
        setArea();
    }
};

float Parallelogram::area() {
    return (height * base * sin(angle*PI/180));
}

class Circle :public Figure {
    float radius; 
public:
    float area();
    Circle(float _radius) : radius(_radius) {
        setArea();
     }
};

float Circle::area() {
    return (PI* radius* radius);
}

class Rectangle : public Parallelogram {
public:
    Rectangle(float length, float width) :Parallelogram(width, length) {}
};

class Square : public Parallelogram {
public:
    Square(float length) :Parallelogram(length, length) {}
};

class Rhombus : public Parallelogram {
public:
    Rhombus(float firsteEdge, float secondEdge, float angle=90) :Parallelogram(firsteEdge, secondEdge, angle) {}
};



//======================================
//                Task2
//=======================================


/*2. Создать класс Car (автомобиль) с полями company (компания) и model (модель).
Классы-наследники: PassengerCar (легковой автомобиль) и Bus (автобус). От этих классов
наследует класс Minivan (минивэн). Создать конструкторы для каждого из классов, чтобы они
выводили данные о классах. Создать объекты для каждого из классов и посмотреть, в какой
последовательности выполняются конструкторы. Обратить внимание на проблему «алмаз
смерти».
Примечание: если использовать виртуальный базовый класс, то объект самого "верхнего"
базового класса создает самый "дочерний" класс.*/



class Car {
	std::string company;
	std::string model;
public:
	void info();
	Car(std::string _company, std::string _model) : company(_company), model(_model) {
		std::cout << "Car" << std::endl;
		info();
	}

};

void Car::info() {
	std::cout << "company: " << company << ", " << "model: " << model << std::endl;
};

class PassengerCar :virtual public Car {
public:
	PassengerCar(std::string _company, std::string _model) : Car(_company, _model) {
		std::cout << "PassengerCar" << std::endl;
		//info();
	}
};

class Bus : virtual public Car {
public:
	Bus(std::string _company, std::string _model) : Car(_company, _model) {
		std::cout << "Bus" << std::endl;
		//info();
	}
};

class Minivan :public PassengerCar, public Bus {
public:
	Minivan(std::string _company, std::string _model) : PassengerCar(_company, _model), Bus(_company, _model), Car(_company, _model) {
		std::cout << "Minivan" << std::endl;
		//info();
	}

};

//======================================
//                Task3
//=======================================

/*3. Создать класс: Fraction (дробь). Дробь имеет числитель и знаменатель (например, 3/7 или 9/2).
Предусмотреть, чтобы знаменатель не был равен 0. Перегрузить:
● математические бинарные операторы (+, -, *, /) для выполнения действий с дробями
● унарный оператор (-)
● логические операторы сравнения двух дробей (==, !=, <, >, <=, >=).
Примечание: Поскольку операторы < и >=, > и <= — это логические противоположности,
попробуйте перегрузить один через другой.
Продемонстрировать использование перегруженных операторов.*/

class Fraction {
	int divisible;
	int divider;

public:

	bool checkData(int divider);
	int getDivisible();
	int getDivider();

	Fraction(int _divisible, int _divider) : divisible(_divisible), divider(_divider) {
		if (!(checkData(divider))) {
			std::cout <<"Warning, divider < 0" << std::endl;
		}
	}
};

bool Fraction::checkData(int divider) {
	if (divider <= 0) {
		return false;
	}
	else {
		return true;
	}
}
int Fraction::getDivisible() {
	return divisible;
}

int Fraction::getDivider() {
	return divider;
}

Fraction operator + (Fraction& l, Fraction& r) {
	int divisible;
	int divider;
	if (l.getDivider() == r.getDivider()) {
		divisible = l.getDivisible() + r.getDivisible();
		divider = l.getDivider();
	}
	else {
		divider = l.getDivider() * r.getDivider();
		divisible = (l.getDivisible() * r.getDivider()) + (r.getDivisible() * l.getDivider());
	}
	return Fraction(divisible, divider);
}

Fraction operator - (Fraction& l, Fraction& r) {
	int divisible;
	int divider;
	if (l.getDivider() == r.getDivider()) {
		divisible = l.getDivisible() - r.getDivisible();
		divider = l.getDivider();
	}
	else {
		divider = l.getDivider() * r.getDivider();
		divisible = (l.getDivisible() * r.getDivider()) - (r.getDivisible() * l.getDivider());
	}
	return Fraction(divisible, divider);
}

Fraction operator * (Fraction& l, Fraction& r) {
	int divisible;
	int divider;
	divider = l.getDivider() * r.getDivider();
	divisible = l.getDivisible() * r.getDivisible();
	return Fraction(divisible, divider);
}

Fraction operator / (Fraction& l, Fraction& r) {
	int divisible;
	int divider;
	divider = l.getDivider() * r.getDivisible();
	divisible = l.getDivisible() * r.getDivider();
	return Fraction(divisible, divider);
}

Fraction operator - (Fraction& l) {
	int divisible;
	int divider;
	divider = -l.getDivider();
	divisible = -l.getDivisible();
	return Fraction(divisible, divider);
}

bool operator == (Fraction& l, Fraction& r) {  
	return ((r.getDivider() * l.getDivisible()) == (l.getDivider() * r.getDivisible()));
}


bool operator != (Fraction& l, Fraction& r) {
	return !((r.getDivider() * l.getDivisible()) == (l.getDivider() * r.getDivisible()));
}

bool operator < (Fraction& l, Fraction& r) {
	return ((l.getDivider() * r.getDivisible()) < (r.getDivider() * l.getDivisible()));
}

bool operator <= (Fraction& l, Fraction& r) {
	return ((l.getDivider() * r.getDivisible()) <= (r.getDivider() * l.getDivisible()));
}

bool operator > (Fraction& l, Fraction& r) {
	return (r.getDivider() * l.getDivisible()) < (l.getDivider() * r.getDivisible());
}

bool operator >= (Fraction& l, Fraction& r) {

	return ((r.getDivider() * l.getDivisible()) <= (l.getDivider() * r.getDivisible()));
	
}

std::ostream& operator << (std::ostream& s, Fraction& f) {
	s << f.getDivisible() << ", " << f.getDivider() << std::endl;
	return s;
}

//======================================
//                Task4
//=======================================

/*4. Создать класс Card, описывающий карту в игре БлэкДжек. У этого класса должно быть три
поля: масть, значение карты и положение карты (вверх лицом или рубашкой). Сделать поля
масть и значение карты типом перечисления (enum). Положение карты - тип bool. Также в этом
классе должно быть два метода:
● метод Flip(), который переворачивает карту, т.е. если она была рубашкой вверх, то он
ее поворачивает лицом вверх, и наоборот.
● метод GetValue(), который возвращает значение карты, пока можно считать, что туз =1.*/

class Card {
	enum Suit { SPADES = 1, HEARTS, CLUBS, DIAMONDS };
	enum Value {ONE=1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK=10, QUEEN=10, KING=10, ACE=1 };
	bool Position;
public:
	void Flip();
	int getValue(Value value);
	};

void Card::Flip() {
	if (Position == false) {
		Position = true;
	}
}

int Card::getValue(Value value) {
	return value;
}



int main()
{
//======================================
//                Task1
//=======================================

    Circle c0(10);
    Rectangle r0(10, 10);
    Square s0(25);
    Rhombus rh0(10, 15, 40);

    std::cout <<"Circle:" << c0.getArea() << std::endl<<"Rectangle:" << r0.getArea() << std::endl<< "Square: " << s0.getArea() << std::endl
                <<"Rhombus: " << rh0.getArea() << std::endl;
	

//======================================
//                Task2
//=======================================

	Car c1("zil", "130");
	std::cout << std::endl;
	PassengerCar p1("renault", "koleos");
	std::cout << std::endl;
	Bus b1("liaz", "Hell-car");
	std::cout << std::endl;
	Minivan m1("WV", "Hippi-car");
	std::cout << std::endl;


//======================================
//                Task3
//=======================================
	Fraction f1(5, 0);
	Fraction f2(2, 4);
	Fraction f3(3, 6);
	Fraction f4(1, 5);

	if (f2 == f3) {
		std::cout << "Equal" << std::endl;
	}
	else {
		std::cout << "Not Equal" << std::endl;
	}
	Fraction f5(f2 + f4);
	std::cout << f5 << std::endl;

}

