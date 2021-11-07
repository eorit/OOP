
#include <iostream>
#include <string>
#include <vector>


//=========================================
//           Task1
//=========================================
/*
1Реализовать шаблон класса Pair1, который позволяет пользователю передавать данные
одного типа парами.
Следующий код:
int main()
{
Pair1<int> p1(6, 9);
cout << "Pair: " << p1.first() << ' ' << p1.second() << '\n';
const Pair1<double> p2(3.4, 7.8);
cout << "Pair: " << p2.first() << ' ' << p2.second() << '\n';
return 0;
}
… должен производить результат:
Pair: 6 9
Pair: 3.4 7.8*/


template <typename T>
class Pair1 {
    const  T First;
    const  T Second;
public:
    Pair1(const T _First, const T _Second) : First(_First), Second(_Second) {};
    T first() const;
    T second() const;
};
template <typename T>
 T Pair1<T>::first() const {
    return First;
}
template <typename T>
T Pair1<T>::second() const {
    return Second;
}


//=========================================
//           Task2
//=========================================
/*Реализовать шаблон класса Pair1, который позволяет пользователю передавать данные
одного типа парами.
Следующий код:
int main()
{
Pair1<int> p1(6, 9);
cout << "Pair: " << p1.first() << ' ' << p1.second() << '\n';
const Pair1<double> p2(3.4, 7.8);
cout << "Pair: " << p2.first() << ' ' << p2.second() << '\n';
return 0;
}
… должен производить результат:
Pair: 6 9
Pair: 3.4 7.8*/


template <class T, class T2>
class Pair {
    const  T First;
    const  T2 Second;
public:
    Pair(T _First, T2 _Second) : First(_First), Second(_Second) {};
    T first() const;
    T2 second() const;
};
template <typename T, typename T2>
T Pair <T, T2>::first() const {
    return First;
}
template <typename T, typename T2>
T2 Pair <T, T2>::second() const {
    return Second;
}


//=========================================
//           Task3
//=========================================


/*3. Написать шаблон класса StringValuePair, в котором первое значение всегда типа string, а
второе — любого типа.Этот шаблон класса должен наследовать частично
специализированный класс Pair, в котором первый параметр — string, а второй — любого
типа данных.
Следующий код :
int main()
{
    StringValuePair<int> svp("Amazing", 7);
    std::cout << "Pair: " << svp.first() << ' ' << svp.second() << '\n';
    return 0;
}
… должен производить следующий результат :
Pair: Amazing 7
Подсказка : при вызове конструктора класса Pair из конструктора класса StringValuePair не
забудьте указать, что параметры относятся к классу Pair.
*/

template <typename U>
class Pair <std::string, U>{
    const  std::string First;
    const  U Second;
public:
    Pair(std::string _First, U _Second) : First(_First), Second(_Second) {};
    std::string first() const;
    U second() const;
};
template <typename U>
std::string Pair <std::string, U>::first() const {
    return First;
}

template  <typename U>
U Pair <std::string, U>::second() const {
    return Second;
}

template <typename U>
class StringValuePair :public Pair <std::string, U>{
public:
    StringValuePair(std::string _First, U _Second) : Pair<std::string, U>(_First, _Second) {};
 };


//=========================================
//           Task4
//=========================================


/*4. Согласно иерархии классов, которая представлена в методичке к уроку 3, от класса Hand
наследует класс GenericPlayer, который обобщенно представляет игрока, ведь у нас будет
два типа игроков - человек и компьютер. Создать класс GenericPlayer, в который добавить
поле name - имя игрока. Также добавить 3 метода:
● IsHitting() - чисто виртуальная функция, возвращает информацию, нужна ли игроку
еще одна карта.
● IsBoosted() - возвращает bool значение, есть ли у игрока перебор
● Bust() - выводит на экран имя игрока и объявляет, что у него перебор.*/

/*
class Card {

	enum Suit {                                         //Масть карты (трефы, бубны, червы и пики). suit — это перечисление,
        SPADES = 1,                                     //содержащее четыре возможные масти
        HEARTS=2,
        CLUBS=3,
        DIAMONDS=4
    };

	enum Value {                                        //Значение карты (туз, двойка, тройка и так долее). rank — это                  
        ACE=1,                                          // перечисление, куда входят все 13 значений
        TWO=2,
        THREE=3,
        FOUR=4,
        FIVE=5,
        SIX=6,
        SEVEN=7,
        EIGHT=8,
        NINE=9,
        TEN=10,
        JACK=10,
        QUEEN=10,
        KING=10
    };

	bool Position;                                      //Указывает, как расположена карта — вверх лицом или рубашкой.
                                                        //Влияет на то, отображается она или нет
public:
	void Flip();                                       //Переворачивает карту.Может использоваться для того, чтобы
                                                        //перевернуть карту лицом вверх или вниз
	int getValue(Value value);                           //Возвращает значение карты
	};

void Card::Flip() {
	if (Position == false) {
		Position = true;
	}
}

int Card::getValue(Value value) {
	return value;
}


#define BLACK_JACK 21

class Hand {
    std::vector <Card> m_Сard;                 //Коллекция карт. Хранит указатели на объекты типа Сard

public:
    void Add(Card pCard);                      //Добавляет карту в руку. Добавляет указатель на объект типа Сard в
                                                //вектор m_Сards
    void Clear();                               //Очищает руку от карт.Удаляет все указатели из вектора m_Сards,
                                                //устраняя все связанные с ними объекты в куче
    int getValue();                             //Возвращает сумму очков карт руки
};

void Hand::Add(Card pCard) {
    m_Сard.push_back(pCard);
}

void Hand::Clear() {
    m_Сard.clear();
}

int Hand::getValue() {
    int sum = 0;
    for (int i = 0; i < m_Сard.size(); ++i) {
        if (sum < BLACK_JACK && m_Сard[i].getValue() == 1) {
            sum = sum + 11;
        }
        else {
            sum = sum + m_Сard[i].getValue();
        }
    }
    return sum;
}.
*/

class GenericPlayer :public Hand {
    std::string name;
public:
    GenericPlayer(std::string _name) : name(_name) {};
    virtual bool IsHitting() const = 0;
    bool IsBoosted();                                   // возвращает bool значение, есть ли у игрока перебор
    void Bust();                                        //выводит на экран имя игрока и объявляет, что у него перебор.
    std::string getName()const;
};

bool GenericPlayer::IsBoosted() {                       // возвращает bool значение, есть ли у игрока перебор
    if (getValue() > BLACK_JACK) {
        return true;
    }
    else {
        return false;
    }
}

void GenericPlayer::Bust() {                              // выводит на экран имя игрока и объявляет, что у него перебор.
    if (this->IsBoosted()) {
        std::cout << "Player " << this->name << ":" << "Is Boosted" << "\n";
    }
}

std::string GenericPlayer::getName() const {                              // выводит на экран имя игрока и объявляет, что у него перебор.
    return name;
}


class Player :public GenericPlayer {
public:
    virtual bool IsHitting() const = 0;                 //Указывает, нужна ли игроку еще одна карта
    void Win() const;                                   //Объявляет, что игрок выиграл
    void Lose() const;                                  //Объявляет, что игрок проиграл
    void Push() const;                                  //Объявляет, что игрок сыграл вничью
};

void Player::Win() const {
    std::cout <<this->getName() << "WIN" << "\n";
}

void Player::Lose() const {
    std::cout << this->getName() << "LOSE" << "\n";
}

void Player::Lose() const {
    std::cout << this->getName() << "PUSH" << "\n";
}

class House :public GenericPlayer {
public:
    virtual bool IsHitting() const;                      //Указывает, нужна ли игроку еще одна карта
    void FliptFirstCard();                               //Переворачивает первую карту
};


/*

class Deck :public Hand {
public:
    void Populate();                                     //Создает стандартную колоду из 52 карт
    void Shuffle();                                      //Тасует карты
    void Deal(Hand& aHand);                              //Раздает в руку одну карту
    void AdditionalCards(GenericPlayer& aGenericPlayer); //Раздает игроку дополнительные карты
                                                         //до тех пор, пока он может и хочет их получать

};

class Game {
    Deck m_Deck;                                         //Колода карт
    House m_House;                                       //Рука дилера
    std::vector <Player> m_Player;                       //Группа игроков-людей. Вектор, содержащий объекты типа Player
    void Play();                                         //Проводит кон игры Blackjack
};
*/



int main()
{

    //=========================================
    //           Task1
    //=========================================
    /* Pair1<int> p1(6, 9);
    std::cout << "Pair: " << p1.first() << ' ' << p1.second() << '\n';
    const Pair1<double> p2(3.4, 7.8);
    std::cout << "Pair: " << p2.first() << ' ' << p2.second() << '\n';
  


    //=========================================
    //           Task2
    //=========================================
    Pair<int, double> p3(6, 7.8);
    std::cout << "Pair: " << p3.first() << ' ' << p3.second() << '\n';
    const Pair<double, int> p4(3.4, 5);
    std::cout << "Pair: " << p4.first() << ' ' << p4.second() << '\n';
    */


    //=========================================
    //           Task3
    //=========================================
    StringValuePair<int> svp("Amazing", 7);
    std::cout << "Pair: " << svp.first() << ' ' << svp.second() << '\n';
   

    //=========================================
    //           Task4
    //=========================================

    return 0;
}
