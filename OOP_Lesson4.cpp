/*1. Добавить в контейнерный класс, который был написан в этом уроке, методы:
● для удаления последнего элемента массива (аналог функции pop_back() в векторах)
● для удаления первого элемента массива (аналог pop_front() в векторах)
● для сортировки массива
● для вывода на экран элементов.*/






#include <iostream>
#include <vector>
#include "Arraint.h"
#include "OOP_Lesson4.h"


//------------------------------------
//--------Task1-----------------------
// -----------------------------------

//===========================================================
// из методички

class ArrayInt {
private:
	int m_length;
	int* m_data;
public:
	ArrayInt() : m_length(0), m_data(nullptr)
	{ }
	ArrayInt(int length) :
		m_length(length) {
		assert(length >= 0);
		if (length > 0)
			m_data = new int[length];
		else
			m_data = nullptr;
	}
	void erase();
	void resize(int newLength);
	void insertBefore(int value, int index);
	int getLength();

//конец части из методички
//===========================================================


	int swap(int a, int b);
	int pop_back();
	int pop_front();
	void sort();
	void print();

// из методички
	~ArrayInt() {
		delete[] m_data;
	}
//конец части из методички
//===========================================================
// 
//===========================================================
//методы из методички

	int& operator[](int index)
	{
		assert(index >= 0 && index < m_length);
		return m_data[index];
	}

};
void  ArrayInt::erase() {
	delete[] m_data;
	m_data = nullptr;
	m_length = 0;
}
int ArrayInt::getLength() {
	return m_length;
}
void ArrayInt::resize(int newLength)
{
	if (newLength == m_length)
		return;
	if (newLength <= 0)
	{
		erase();
		return;
	}
	int* data = new int[newLength];
	if (m_length > 0)
	{
		int elementsToCopy = (newLength > m_length) ? m_length : newLength;
		for (int index = 0; index < elementsToCopy; ++index)
			data[index] = m_data[index];
	}
	delete[] m_data;
	m_length = newLength;
}

void ArrayInt::insertBefore(int value, int index)
{
	assert(index >= 0 && index <= m_length);
	int* data = new int[m_length + 1];
	for (int before = 0; before < index; ++before)
		data[before] = m_data[before];
	data[index] = value;
	for (int after = index; after < m_length; ++after)
		data[after + 1] = m_data[after];
	delete[] m_data;
	m_data = data;
	++m_length;
}
//конец методов из методички
//===============================================================
//===============================================================

int ArrayInt::pop_back() {
	int newLenght = m_length - 1;

	if (m_length == 1) {
		return m_data[m_length];
		erase();
	}
	else if (m_length > 1) {
		int temp;
		int* data = new int[newLenght];
		temp = m_data[newLenght];
		std::cout << "pop_back: " << m_data[newLenght] << std::endl;
		for (int index = 0; index < newLenght; ++index) {
			data[index] = m_data[index];
			std::cout << "Index : " << index << " data: " << data[index] << std::endl;
		}
		delete[] m_data;
		m_data = data;
		m_length = newLenght;
		return temp;

	}
}

int ArrayInt::pop_front() {
	int first_indx = 0;
	int newLenght = m_length - 1;
	int temp = m_data[first_indx];

	if (m_length == 1) {
		erase();
	}
	else if (m_length > 1) {
		int* data = new int[newLenght];
		for (int index = 0; index < newLenght; ++index) {
			data[index] = m_data[index + 1];
		}
		delete[] m_data;
		m_data = data;
		m_length = newLenght;
	}
	return temp;
}

int ArrayInt::swap(int a, int b) {
	int temp = a;
	a = b;
	b = a;
	return a, b;
}

void ArrayInt::sort() {
	for (int i = 0; i < m_length - 1; i++) {
		for (int j = 1; j < m_length - 1; j++) {
			if (m_data[i] > m_data[j]) {
				swap(m_data[i], m_data[j]);
			}
		}
	}
}

void ArrayInt::print() {
	if (m_length > 0) {
		for (int index = 0; index < m_length; ++index) {
			std::cout << m_data[index];
		}
		std::cout << std::endl;
	}
}

#define ARRAY_SIZE	10

//------------------------------------
//--------Task2-----------------------
// -----------------------------------


/*2. Дан вектор чисел, требуется выяснить, сколько среди них различных. Постараться
использовать максимально быстрый алгоритм. */
void fillVector(std::vector<int> &v) {
	for (int i = 10; i < 100; i = i + 5) {
		v.push_back(i);
		if (i % 3 == 0) {
			v.push_back(i);
		}
	}
}

void printVector(std::vector<int>& v) {
	for (int i = 0; i < v.size(); i++) {
		std::cout << v[i] << " ";
	}
	std::cout << std::endl;
}

void printFilteredVector(std::vector <int > & v) {
	for (int i = 0; i < v.size(); i++) {
		if (v[i] != 0) {
			std::cout << v[i]<<" ";
		}
	}
	std::cout << std::endl;

}

void resizeVector(std::vector<int>& v) {
	v.resize(v.size() * 2);
}


//------------------------------------
//--------Task3-----------------------
// -----------------------------------

/*
3. Реализовать класс Hand, который представляет собой коллекцию карт. В классе будет одно
поле: вектор указателей карт (удобно использовать вектор, т.к. это по сути динамический
массив, а тип его элементов должен быть - указатель на объекты класса Card). Также в классе
Hand должно быть 3 метода:
● метод Add, который добавляет в коллекцию карт новую карту, соответственно он
принимает в качестве параметра указатель на новую карту
● метод Clear, который очищает руку от карт
● метод GetValue, который возвращает сумму очков карт руки (здесь предусмотреть
возможность того, что туз может быть равен 11).*/
/*
class Card {
	enum Suit { SPADES = 1, HEARTS, CLUBS, DIAMONDS };
	enum Value {ACE=1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK=10, QUEEN=10, KING=10 };
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
*/
#define BLACK_JACK 21

class Hand {
	std::vector <Card* > m_Сard;

public:
	void Add(Card* pCard);
	void Clear();
	int getValue();
};

void Hand::Add(Card* pCard) {
	m_Сard.push_back(pCard);
}

void Hand::Clear() {
	m_Сard.clear ();
}

int Hand::getValue() {
	int sum = 0;
	for (int i = 0; i < m_Сard.size(); ++i) {
		if (sum < BLACK_JACK && m_Сard[i].getValue() == 1) {
			sum = sum + 11;
		} else {
			sum = sum + (m_Сard[i]).getValue();
		}
	}
	return sum;
}


int main()
{
//=============================================
//--------Task1----------------------
//=============================================



	ArrayInt arr(ARRAY_SIZE);
	for (int i = 0; i < ARRAY_SIZE; i++) {
		arr[i] = i;
	}
	std::cout << arr.getLength() << std::endl;
	arr.print();
	std::cout << arr.pop_back() << std::endl;
	arr.print();
	std::cout << arr.pop_front() << std::endl;
	arr.print();
	

//=============================================
//--------Task2----------------------
//=============================================

	std::vector <int> ivect;
	
	fillVector(ivect);
	
	printVector(ivect);
	
	std::vector <int> numbers (ivect.size());
	std::vector <int> count (ivect.size());
	
	
	for (int i = 0; i < ivect.size(); i++) {
		if (numbers.size() < ivect[i]) {
			resizeVector(numbers);
			resizeVector(count);
		}
		numbers[ivect[i]] = ivect[i];
		count[ivect[i]] = count[ivect[i]]+1;
	}
	std::cout << "numbers: ";
	printFilteredVector(numbers);
	std::cout << "count:   ";
	printFilteredVector(count);
	
	



}