
#include <iostream>
//#include _CRT_SECURE_NO_WAENINGS


//===============================
//         task 1
//===============================

/*
1 Создать программу, которая считывает целое число типа int. И поставить «защиту от дурака»:
если пользователь вводит что-то кроме одного целочисленного значения, нужно вывести
сообщение об ошибке и предложить ввести число еще раз. Пример неправильных введенных
строк:
rbtrb
nj34njkn
1n
*/

void printQuery() {
    std::cout << "Input an integer number, please" << std::endl;
}

void printConfirmation() {
    std::cout << "An integer number has been entered" << std::endl;
}



std::string getData() {
    std::string temp;
    std::cin >> temp;
    return temp;
}

int error() {

    std::cerr << "Invalid data! Please, try again" << std::endl;
    return 1;
}

int checkData(std::string data) {
    int counter = 0;
    int flag = 0;
    std::string num = "0123456789";
    for (int i = 0; i < data.size(); i++) {
        for (int j = 0; j < num.size(); j++) {
            if (data[i] == num[j]) {
                ++counter;
                break;
            }
        }
        if (counter != (i + 1)) {
            flag = 1;
            break;
        }
    }
    return flag;
}

//===============================
//         task 2
//===============================

/*
2 Создать собственный манипулятор endll для стандартного потока вывода, который выводит
два перевода строки и сбрасывает буфер.
*/
std::ostream& endll(std::ostream& out) {
    out << "\n" << std::endl;
    return out;
}

//===============================
//         task BLACK_JACK
//===============================


/*
3 Реализовать класс Player, который наследует от класса GenericPlayer. У этого класса будет 4
метода:
● virtual bool IsHitting() const - реализация чисто виртуальной функции базового
класса. Метод спрашивает у пользователя, нужна ли ему еще одна карта и возвращает
ответ пользователя в виде true или false.
● void Win() const - выводит на экран имя игрока и сообщение, что он выиграл.
● void Lose() const - выводит на экран имя игрока и сообщение, что он проиграл.
● void Push() const - выводит на экран имя игрока и сообщение, что он сыграл вничью.
*/

/*
4 Реализовать класс House, который представляет дилера. Этот класс наследует от класса
GenericPlayer. У него есть 2 метода:
● virtual bool IsHitting() const - метод указывает, нужна ли дилеру еще одна карта. Если
у дилера не больше 16 очков, то он берет еще одну карту.
● void FlipFirstCard() - метод переворачивает первую карту дилера.
*/
/*
class Card {


    bool IsFaceUp;

    rank Rank;
    suit Suit;

 public:
 enum suit {
        SPADES = 1,
        HEARTS=2,
        CLUBS=3,
        DIAMONDS=4
    };

    enum rank {
        ACE=1,
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
    Card (rank r, suit s, bool is_face_up):Rank(r), Suit(s), IsFaceUp(is_face_up){}
    void Flip();

    int getValue() const;
    };

void Card::Flip() {
    IsFaceUp=!IsFaceUp;
}

int Card::getValue()const {
    int value=0;
    if (IsFaceUp){
        value=Rank;
    }
    return value;
}


#define BLACK_JACK 21

class Hand {
protected:
    std::vector <Card> m_Сard;

public:
    Hand();
    void Add(Card* pCard);

    void Clear();

    int getTotal() const;
    virtual ~Hand();
 };
Hand::Hand(){
    m_Card.reserve(7);
 }

 Hand::~Hand(){
    Clear();
 }

void Hand::Add(Card pCard) {
    m_Сard.push_back(pCard);
}

void Hand::Clear() {
    vector<Card*>::iterator iter=m_Card.begin();
    for (iter=m_Card.begin(); iter!=m_Card.end(); ++iter){
        delete *iter;
        *iter=0;
    }
    m_Сard.clear();
}

int Hand::getTotal() const {
    if(m_Card.empty()){
        return 0;
    }
    if(m_Card[0]->GetValue()==0){
        return 0;
    }


    int sum = 0;
    vector<Card*>::const_iterator iter;
    for (iter=m_Card.begin(); iter!=m_Card.end(); ++iter){
        sum+=(*iter)->GetValue();
    }
    bool containsAce=false;
    for (iter=m_Cardd.begin(); iter!=m_Card.end(); ++iter){
        if((*iter)->GetValue()==Card::ACE){
            containsAce=true;
        }
    }

    if (containsAce&& sum<=11){  // не совсем понятна логика, если я правильно понял правила, туз становится равен 1 после набора 21 ,т.е.
    sum+=10;                     // может быть не менее 2х тузов на руках (они будут по 11), а третий уже 1 (так как сумма уже будет 22 >21)
    }                            //Из методички к 5 уроку стр 21: "Количество очков, которое дает туз, определяется так: если
                                 //в руке есть туз, он дает 11 очков; затем выполняется проверка, превышает ли сумма очков карт в руке
                                 //число 21. Если нет — количество очков, которое дает туз, не изменяется. В противном случае туз даст
                                 //1 очко."
    return sum;
}

//    for (int i = 0; i < m_Сard.size(); ++i) {
//        if (sum < BLACK_JACK && m_Сard[i].getValue() == 1) {
//            sum = sum + 11;
//        }
//        else {
//            sum = sum + m_Сard[i].getValue();
//        }
//    }
//    return sum;
}.


class GenericPlayer :public Hand {

    friend std::ostream& operator<< (std::ostream& out, const GenericPlayer& aGenericPlayer);
protected:
    std::string name;
public:
    GenericPlayer(std::string _name) : name(_name) {};
    virtual bool IsHitting() const = 0;
    bool IsBoosted();
    void Bust() const;
    std::string getName()const;
    ~GenericPlayer(){}
};

bool GenericPlayer::IsBoosted() {
    return (getTotal() > BLACK_JACK);                   // в методичке 6 урок на стр 13 "(GetTotal() > 21)" - можно считать ошибкой, если такие константы -это bad style?

}

void GenericPlayer::Bust() const {
        std::cout << "Player " << name << ":" << "Is Boosted" << "\n";
}

std::string GenericPlayer::getName() const {
    return name;
}
std::ostream& operator<< (std::ostream& out, const GenericPlayer& aGenericPlayer){
    out<<aGenericPlayer.name<<":\t";

    vector <Card*>::const_iterator pCard;
    if (!aGenericPlayer.m_Card.empty()) {
        for (pCard = aGenericPlayer.m_Card.begin();
             pCard != aGenericPlayer.m_Card.end();
             ++pCard) {
            out << *(*pCard) << "\t";                        //   *(*pCard) - требуется пояснение данного выражения
        }
        if (aGenericPlayer.getTotal() != 0) {
            std::cout << "(" << aGenericPlayer.getTotal() << ")";
        }
    } else {
        out<<"<empty>";
    }
    return out;
}




class Player :public GenericPlayer {
public:
    Player (const std::string& name="");
    virtual ~Player();
    virtual bool IsHitting() const = 0;
    void Win() const;
    void Lose() const;
    void Push() const;
};
virtual bool Player:: IsHitting() const{
    std::cout <<name<<", do you want a hit? (Y/N): ";
    char response;
    std::cin>>response;
    return (response=='y'|| response=='Y');
}


void Player::Win() const {
    std::cout <<name << "WIN" << "\n";
}

void Player::Lose() const {
    std::cout << name << "LOSE" << "\n";
}

void Player::Push() const {
    std::cout << name<< "PUSH" << "\n";
}

*/

/*
class House :public GenericPlayer {
public:

    House (const string& name="House");
    virtual ~House();
    virtual bool IsHitting() const;
    void FliptFirstCard();
};
 bool House::IsHitting() const{
     return (getTotal()<=16);
 }

 bool House::FlipFirstCard() {
     if (!(m_Card.empty())){
         m_Card[0]->Flip();
     } else{
         std::cout<<"No card to flip!\n";
     }
 }
*/
/*

class Deck :public Hand {
public:
    void Populate();                                     
    void Shuffle();                                     
    void Deal(Hand& aHand);                              
    void AdditionalCards(GenericPlayer& aGenericPlayer); 
                                                         

};

class Game {
    Deck m_Deck;                                         
    House m_House;                                      
    std::vector <Player> m_Player;                       
    void Play();                                         
};
*/




/*
5 Написать перегрузку оператора вывода для класса Card. Если карта перевернута рубашкой
вверх (мы ее не видим), вывести ХХ, если мы ее видим, вывести масть и номинал карты.
Также для класса GenericPlayer написать перегрузку оператора вывода, который должен
отображать имя игрока и его карты, а также общую сумму очков его карт.
*/
/*
std::ostream& operator<<(std::ostream& out, const Card& aCard){
    const std::string RANKS[]={"A", "2", "3", "4", "5", "6", "7", "8", "9",
                               "10", "J", "Q", "K"};
    const std::string SUITS[]={"c", "d", "h", "s"};
    if (aCard.IsFaceUp){
        out<<RANKS[aCard.Rank]<<SUITS[aCard.Suit];
    } else{
        out<<"XX";
    }
    return out;
}
*/


int main()
{


    //===============================
    //         task 1
    //===============================

    std::string data;
    printQuery();
    data = getData();
    while (checkData(data)) {
        error();
        data = getData();
    }
    printConfirmation();
    //===============================
    //         task 2
    //===============================

    std::cout << "endll" << endll;
    std::cout << "Check!" << std::endl;


    return 0;
}