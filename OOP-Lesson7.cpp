#include <iostream>
/*
 1. Создайте класс Date с полями день, месяц, год и методами доступа к этим полям.
Перегрузите оператор вывода для данного класса.
Создайте два "умных" указателя today и
date. Первому присвойте значение сегодняшней даты. Для него вызовите по отдельности
методы доступа к полям класса Date, а также выведите на экран данные всего объекта с
помощью перегруженного оператора вывода. Затем переместите ресурс, которым владеет
указатель today в указатель date. Проверьте, являются ли нулевыми указатели today и date и
выведите соответствующую информацию об этом в консоль.
*/

//==================================================================
//          task1
//==================================================================


class Date{
    int day;
    int mounth;
    int year;
public:
    Date(int _day, int _mounth, int _year): day(_day), mounth (_mounth), year(_year){};
    int getDay();
    int getMounth();
    int getYear();
    void setDay(int _day);
    void setMounth(int _mounth);
    void setYear(int _year);
    ~Date(){};
    std::ostream & operator<<(std::ostream &out);
};

int Date::getDay() {return day;}
int Date::getMounth() {return mounth;}
int Date::getYear(){return year;}

void Date::setDay (int _day) {
    day=_day;
}
void Date::setMounth (int _mounth) {
    mounth=_mounth;
}
void Date::setYear (int _year){
    year=_year;
}

std::ostream & Date::operator<<(std::ostream &out) {
    out<<getDay()<<". "<<getMounth()<<". "<<getYear()<<std::endl;
    return out;
}

template <class T>
class Auto_ptr {
    T* ptr;
public:
    Auto_ptr (T* _ptr=nullptr):ptr(_ptr) {}

    ~Auto_ptr(){
        delete ptr;
    }

    T& operator*() const{return *ptr;}

    T* operator->() const{return ptr;}

    Auto_ptr(Auto_ptr& a){
        ptr=a.ptr;
        a.ptr=nullptr;
    }

    bool isNull() const { return ptr == nullptr;  }

    Auto_ptr& operator=(Auto_ptr& a) {
        if (&a == this)
            return *this;
        delete ptr;
        ptr = a.ptr;
        a.ptr = nullptr;
        return *this;
    }
};



//==================================================================
//          task2
//==================================================================

/*
2. По условию предыдущей задачи создайте два умных указателя date1 и date2.
● Создайте функцию, которая принимает в качестве параметра два умных указателя
типа Date и сравнивает их между собой (сравнение происходит по датам). Функция
должна вернуть более позднюю дату.
● Создайте функцию, которая обменивает ресурсами (датами) два умных указателя,
переданных в функцию в качестве параметров.
Примечание: обратите внимание, что первая функция не должна уничтожать объекты,
переданные ей в качестве параметров.
*/

Auto_ptr<Date>* operator>(Auto_ptr<Date> &A, Auto_ptr<Date> &B){
    int flag=0;
    if (A->getYear()>B->getYear()){
        return &A;
    }
    else if(A->getYear()< B->getYear()){
        return &B;
    }
    else{
        if (A->getMounth()> B->getMounth()){
            return &A;
        } else if (A->getMounth()< B->getMounth()){
            return &B;
        } else{
            if (A->getDay()>= B->getDay()){
                return &A;
            } else {
                return &B;
            }
        }
    }
}
void swapDatePtr (Auto_ptr<Date> &A, Auto_ptr<Date> &B) {
    Auto_ptr<Date> temp;
    temp = A;
    A = B;
    B = temp;
}

//=================================================================================

//===============================
//         task BLACK_JACK
//===============================

/*3. Создать класс Deck, который наследует от класса Hand и представляет собой колоду карт.
Класс Deck имеет 4 метода:
● vold Populate() - Создает стандартную колоду из 52 карт, вызывается из конструктора.
● void Shuffle() - Метод, который тасует карты, можно использовать функцию из
алгоритмов STL random_shuffle
● vold Deal (Hand& aHand) - метод, который раздает в руку одну карту
● void AddltionalCards (GenericPlayer& aGenerlcPlayer) - раздает игроку
дополнительные карты до тех пор, пока он может и хочет их получать
Обратите внимание на применение полиморфизма. В каких методах применяется этот
принцип ООП?*/

/*
class Deck :public Hand {
public:
    Deck();
    virtual ~Deck();
    void Populate();
    void Shuffle();
    void Deal(Hand& aHand);
    void AdditionalCards(GenericPlayer& aGenericPlayer);
};

Deck::Deck(){
    m_Cards.reserve(52);
    Populate ();
}

Deck::~Deck(){}

void Deck::Populate(){
    Clear();
    for (int s=Card::CLUBS; s<=Card::SPADES; ++s){
        for (int r=Card::ACE; r<=Card::KING; ++r){
            Add (new Card (static_cast <Card::rank>(r), static_cast <Card::suit>(s)));
        }
    }
}

void Deck:: Shuffle(){
    random_shuffle (m_Cards.begin(), m_Cards.end());
}

void Deck::Deal (Hand& aHand){
    if (!m_Cards.empty()){
        aHand.Add(m_Cards.back());
        m_Cards.pop_back();
    }
    else{
        std::cout<<"Out of cards.Unable to deal."
    }
}
*/

/*
4. Реализовать класс Game, который представляет собой основной процесс игры. У этого
класса будет 3 поля:
● колода карт
● рука дилера
● вектор игроков.
Конструктор класса принимает в качестве параметра вектор имен игроков и создает объекты
самих игроков. В конструкторе создается колода карт и затем перемешивается.
Также класс имеет один метод play(). В этом методе раздаются каждому игроку по две
стартовые карты, а первая карта дилера прячется. Далее выводится на экран информация о
картах каждого игра, в т.ч. и для дилера. Затем раздаются игрокам дополнительные карты.
Потом показывается первая карта дилера и дилер набирает карты, если ему надо. После
этого выводится сообщение, кто победил, а кто проиграл. В конце руки всех игроков
очищаются.*/

/*

class Game {
    Deck m_Deck;
    House m_House;
    std::vector <Player> m_Player;
public:
    Game (const vector <string>& names);
    ~Game();
    void Play();
};

Game::Game (const vector <string>& names){
    vector <string>::const_iterator pName;
    for (pName=names.begin(); pName !=naames.end(); ++pName){
        m_players.push_back(Player(*pName));
    }
    srand(static_cast<ubsigned int>(time(0)));
    m_Deck.Populate();
    m_Deck.Shuggle();
}
Game::~Game(){}

void Game::Play(){
    vector<Player>::iterator pPlayer;
    for (int i=0;i<2; ++i){
        for (pPlayer=m_Players.begin(); pPlayers!=m_Players.end(); ++pPlayer) {
            m_Deck.Deal(*pPlayer);
        }
        m_Deck.Deal(m_House);
    }
    m_House.FlipFirstCard();

    for (pPlayer=m_Players.begin(); pPlayers!+m_Players.end(); ++pPlayers){
        std::cout*pPlayer<<std::endl;
    }
    std::cout<<m_House<<std::endl;
    for (pPlayer=m_Players.begin(); pPlayer!=m_Players.end(); ++pPlayer){
        m_Deck.AdditionalCards(*pPlayer);
    }
    m_House.FlipPirstCard();
    std::cout<<std::endl<<m_House;
    m_Deck.AdditionalCards(m_House);
    if (m_House.IsBusted()){
        for (pPlayer = m_Players.begin(); pPlayer != m_Players.end(); ++pPlayer)
        {
            if (!(pPlayer->IsBusted()))
            {
                pPlayer->Win();
            }
        }
    }
    else {
        for (pPlayer = m_Players.begin(); pPlayer != m_Players.end(); ++pPlayer){
            if (!(pPlayer->IsBusted())){
                if (pPlayer->GetTotal() > m_House.GetTotal()){
                    pPlayer->Win();
                }
                else if (pPlayer->GetTotal() < m_House.GetTotal()){
                    pPlayer->Lose();
                }
                else {
                    pPlayer->Push();
                }
            }
        }
    }
    for (pPlayer = m_Players.begin(); pPlayer != m_Players.end(); ++pPlayer){
        pPlayer->Clear();
    }
    m_House.Clear();
}
 */




/*
5. Написать функцию main() к игре Блекджек. В этой функции вводятся имена игроков.
Создается объект класса Game и запускается игровой процесс. Предусмотреть возможность
повторной игры.*/
/*
int main(){
    cout << "\t\tWelcome to Blackjack!\n\n";
    int numPlayers = 0;
    while (numPlayers < 1 || numPlayers > 7){
        cout << "How many players? (1 - 7): ";
        cin >> numPlayers;
    }
    vector<string> names;
    string name;
    for (int i = 0; i < numPlayers; ++i){
        cout << "Enter player name: ";
        cin >> name;
        names.push_back(name);
    }
    cout << endl;

    Game aGame(names);
    char again = 'y';
    while (again != 'n' && again != 'N'){
        aGame.Play();
        cout << "\nDo you want to play again? (Y/N): ";
        cin >> again;
    }
    return 0;
}*/







int main() {

    //==================================================================
    //          task1
    //==================================================================

    Auto_ptr <Date> today (new Date (28, 10, 2002));
    today->setDay(21);
    today->setMounth(11);
    today->setYear(2021);
    today->operator<<(std::cout);
    Auto_ptr <Date> date;

    std::cout << "today is " << (today.isNull() ? "null\n" : "not null\n");
    std::cout << "date is " << (date.isNull() ? "null\n" : "not null\n");

    date=today;
    date->operator<<(std::cout);
    std::cout << "today is " << (today.isNull() ? "null\n" : "not null\n");
    std::cout << "date is " << (date.isNull() ? "null\n" : "not null\n");
    //==================================================================
    //          task2
    //==================================================================


    Auto_ptr <Date> date1 (new Date (28, 10, 2002));
    Auto_ptr <Date> date2 (new Date (28, 11, 2002));
    Auto_ptr <Date> date3 (new Date (12, 12, 2000));
    Auto_ptr <Date> date4 (new Date (28, 10, 2002));

    date1->operator<<(std::cout);
    date2->operator<<(std::cout);
    std::cout<< "date1>date2"<<std::endl;
    (*(date1>date2))->operator<<(std::cout);
    date2->operator<<(std::cout);
    date3->operator<<(std::cout);
    std::cout<< "date2>date3"<<std::endl;
    (*(date2>date3))->operator<<(std::cout);

    date3->operator<<(std::cout);
    date4->operator<<(std::cout);
    std::cout<< "date3>date4"<<std::endl;
    (*(date3>date4))->operator<<(std::cout);

    std::cout<< "SWAP date1 date2"<<std::endl;
    date1->operator<<(std::cout);
    date2->operator<<(std::cout);
    swapDatePtr (date1, date2);
    std::cout<< "SWAP!"<<std::endl;
    date1->operator<<(std::cout);
    date2->operator<<(std::cout);



    return 0;
}
