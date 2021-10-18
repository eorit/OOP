
#include <iostream>
#include <cmath>
#include <cstdint>

//-------------------------------------------
//    TASK1
//--------------------------------------------

/*
1. Создать класс Power, который содержит два вещественных числа. Этот класс должен
иметь две переменные-члена для хранения этих вещественных чисел.
Еще создать два метода: один с именем set, который позволит присваивать значения
переменным, второй — calculate, который будет выводить результат возведения
первого числа в степень второго числа. Задать значения этих двух чисел по умолчанию.
*/

class Power {
    float number=2;
    float power=10;
public:
    void set ( float _number, float _power );
    float calculate ();   
};

void Power::set(float _number, float _power) {
    number = _number;
    power = _power;
}

float Power::calculate () {
    return pow ( number, power );
}

//-------------------------------------------
//    TASK2
//--------------------------------------------
/*2. Написать класс с именем RGBA, который содержит 4 переменные - члена типа 
std::uint8_t: m_red, m_green, m_blue и m_alpha (#include cstdint для доступа 
к этому типу).Задать 0 в качестве значения по умолчанию для m_red, m_green, 
m_blue и 255 для m_alpha.Создать конструктор со списком инициализации членов, 
который позволит пользователю передавать значения для m_red, m_blue, m_green 
и m_alpha.Написать функцию print(), которая будет
выводить значения переменных - членов.
*/

class RGBA {
    std::uint8_t m_red = 0;
    std::uint8_t m_green = 0;
    std::uint8_t m_blue = 0;
    std::uint8_t m_alpha = 255;
public:

    RGBA() {
    }

    RGBA(std::uint8_t red, std::uint8_t green, std::uint8_t blue, std::uint8_t alpha) 
        : m_red(red), m_green(green), m_blue(blue), m_alpha(alpha) {
    }
    void print();
};

void RGBA::print() {
    std::cout << "m_red = " << unsigned ( m_red ) << std::endl
        << "m_green = " << unsigned ( m_green ) << std::endl
        << "m_blue = " << unsigned ( m_blue ) << std::endl
              << "m_alpha = " << unsigned ( m_alpha ) << std::endl;
}






//-------------------------------------------
//    TASK3
//--------------------------------------------

/*
3. Написать класс, который реализует функциональность стека.Класс Stack должен иметь :
-private - массив целых чисел длиной 10;
-private целочисленное значение для отслеживания длины стека;
-public - метод с именем reset(), который будет сбрасывать длину и все значения
элементов на 0;
-public - метод с именем push(), который будет добавлять значение в стек.push()
должен возвращать значение false, если массив уже заполнен, и true в противном
случае;
-public - метод с именем pop() для вытягивания и возврата значения из стека.Если в
стеке нет значений, то должно выводиться предупреждение;
-public - метод с именем print(), который будет выводить все значения стека.
*/

class Stack {
private:
    
    int stack[10] = { 0 };
    int quantity = -1;
public:
    void reset();
    bool push(int number);
    int pop();
    void print();
    Stack() {
        this->stack[10];
        this-> quantity;
    }
};

void Stack::reset() {
    quantity = -1;
}

bool Stack::push(int number) {
    if (quantity < 10) {
        quantity++;
        stack[quantity] = number;
        return true;
    }
    else if (quantity > (10 - 1)) {
        return false;
    }
}

int Stack::pop() {
    int temp;
    if (quantity > -1) {
        temp = stack[quantity];
        quantity--;
        return temp;
    }
    else if (quantity == -1) {
        std::cout << "Stack is empty" << std::endl;
    }
}

void Stack::print() {
    std::cout << "( ";
    if (quantity > -1) {
        for (int i = quantity; i >= 0; i--) {
            std::cout << stack[i] << " ";
        }
    }
    std::cout << ")" << std::endl;
}


int main()
{

//-------------------------------------------
//    TASK1
//--------------------------------------------
    float number=2.5;
    float power=10;  
    Power power1;
    std::cout << power1.calculate() << std::endl;
    power1.set(number, power);
    std::cout << power1.calculate() << std::endl;
        
//-------------------------------------------
//    TASK2
//--------------------------------------------
    std::uint8_t red = 92;
    std::uint8_t green = 157;
    std::uint8_t blue = 52;
    std::uint8_t alpha = 1;
    RGBA color1;
    color1.print();
    
    RGBA color2(red, green, blue, alpha);
    color2.print();
//-------------------------------------------
//    TASK3
//--------------------------------------------
    Stack stack;

    stack.reset();
    stack.print();
    stack.push(3);
    stack.push(7);
    stack.push(5);
    stack.print();
    stack.pop();
    stack.print();
    stack.pop();
    stack.pop();
    stack.print();

    Stack stack2;
    
    stack2.print();
    stack2.push(8);
    stack2.push(10);
    stack2.push(6);
    stack2.print();
    stack2.pop();
    stack2.print();
    stack2.pop();
    stack2.pop();
    stack2.print();

    return 0;
}
