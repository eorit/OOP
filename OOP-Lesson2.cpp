/*
1 Создать класс Person (человек) с полями: имя, возраст, пол и вес. Определить методы переназначения имени, 
изменения возраста и веса. Создать производный класс Student (студент), имеющий поле года обучения. 
Определить методы переназначения и увеличения этого значения. Создать счетчик количества созданных студентов. 
В функции main() создать несколько (не больше трёх) студентов. Вывести информацию о них.
*/

#include <iostream>
#include <string>


//=============================================
//      TASK1 
//=============================================

class Person {  
    std::string name;
    size_t age;
    char sex;
    size_t weight;
public:
    void set(std::string name, size_t age, char sex, size_t weight);
    void setName(std::string name);
    void setAge(size_t age);
    void setSex(char sex);
    void setWeight(size_t weight);
    std::string getName();
    size_t getAge();
    char getSex();
    size_t getWeight();
};


void Person::set(std::string _name, size_t _age, char _sex, size_t _weight) {
    name = _name;
    age = _age;
    sex = _sex;
    weight = _weight;
}
void Person::setName(std::string _name) {
    name = _name;
}
void Person::setAge(size_t _age) {
    age = _age;
}
void Person::setSex(char _sex) {
    sex = _sex;
}
void Person::setWeight(size_t _weight) {
    weight = _weight;
}
std::string Person::getName() {
    return name;

}
size_t Person::getAge() {
    return age;
}
char Person::getSex() {
    return sex;
}
size_t Person::getWeight() {
    return weight;
}

static int counter = 0;

class Student :public Person {
    size_t yearOfStudy;

public:
    void setYearOfStudy(size_t yearOfStudy);
    void increaseYearOfStudy();
    size_t getYearOfStudy();
    void counterStudent();
    friend void print();
    Student() {
        counterStudent();
    }
};


void Student::setYearOfStudy(size_t _yearOfStudy) {
    yearOfStudy = _yearOfStudy;
}
void Student::increaseYearOfStudy() {
    this->yearOfStudy++;
}
size_t Student::getYearOfStudy() {
    return yearOfStudy;
}
void Student::counterStudent() {
    counter++;
}

void print(Student &student) {
    printf("name: %s,\n sex: %c, \n age: %d, \n weight: %d, \n years of study: %d. \n\n ",\
        (student.getName()).c_str(), student.getSex(), student.getAge(), student.getWeight(), student.getYearOfStudy());
}

void printCounter() {
    std::cout << "Student quantity: " << counter << std::endl << std::endl;
}


//=============================================
//      TASK2
//=============================================
/*2 Создать классы Apple (яблоко) и Banana (банан), которые наследуют класс Fruit (фрукт). У Fruit есть две переменные-члена:
name (имя) и color (цвет). Добавить новый класс GrannySmith, который наследует класс Apple.*/

class Fruit {
    std::string name;
    std::string color;
public:
    Fruit(std::string _name, std::string _color) : name(_name), color(_color) {}
    std::string getName();
    std::string getColor();
};
std::string Fruit::getName() {
    return name;
}
std::string Fruit::getColor() {
    return color;
}


class Apple :public Fruit {
public:
    Apple(std::string _color) : Fruit ("apple", _color) {}
    Apple(std::string _name, std::string _color) : Fruit(_name, _color) {}
};

class Banana : public Fruit {
public:
    Banana() :Fruit("banana", "yellow") {}
};
class GrannySmith : public Apple {
public:
    GrannySmith() :Apple("Granny Smith apple","green") {}
};


int main()
{


    //=============================================
    //      TASK1 
    //=============================================
    
    
    Student Ivanov;
    std::string name = "Ivanov";
    size_t age = 18;
    char sex = 'm';
    size_t weight = 75;
    size_t yearOfStudy = 1;
    Ivanov.set(name, age, sex, weight);
    Ivanov.setYearOfStudy(yearOfStudy);

    Student Petrov;
    name = "Petrov";
    age = 20;
    sex = 'm';
    weight = 80;
    yearOfStudy = 3;
    Petrov.set(name, age, sex, weight);
    Petrov.setYearOfStudy(yearOfStudy);

    Student Sidorova;
    name = "Sidorova";
    age = 20;
    sex = 'f';
    weight = 65;
    yearOfStudy = 1;
    Sidorova.set(name, age, sex, weight);
    Sidorova.setYearOfStudy(yearOfStudy);
    Sidorova.increaseYearOfStudy();

    
    print(Petrov);
    print(Sidorova);
    print(Ivanov);

    printCounter();


    //=============================================
    //      TASK2
    //=============================================

    Apple a("red");
    Banana b;
    GrannySmith c;
    std::cout << "My " << a.getName() << " is " << a.getColor() << ".\n";
    std::cout << "My " << b.getName() << " is " << b.getColor() << ".\n";
    std::cout << "My " << c.getName() << " is " << c.getColor() << ".\n";
    return 0;

}

//=============================================
//      TASK3
//=============================================
/*
Классы:
Игрок:

    параметры
        количество полученных карт
        количество очков
        количество средств для ставок
    методы 
        сделать ставку
        запросить карту
        забрать выигрыш
        страховка
        сплит
        увеличить ставку 
        
 производный от Игрока класс - крупье;
        подсчет игроков
        выдать карту
        перемешать колоду
        
класс колода(карты в игре);
    количество колод (может быть до 8);
    состав 1 колоды;
    текущий состав карт,
    счетчик карт,
    методы
        reset
      
    friend Крупье
 */
