#ifndef STACK_H
#define STACK_H

#include <iostream>
template <typename T>
class Stack {
	T* _data;
	int _size;
	int _top; //индекс последнего верхнего элемента
public:
	void push(const T& val);
	void pop();
	T top() const; //вовзвращение элемента в конце стэка
	T size() const; //необходимо для тестов
	bool is_empty();
	bool is_full();
	void clear() noexcept;
	Stack(); //объявление функции
	Stack(T* data, int size, int top); //конструктор инициализации
	~Stack();
	Stack& operator=(const Stack& other);
	Stack(const Stack& other);
};

template<class T>
Stack<T>::Stack(T* data, int size, int top) {
	//прописываем тело функции
	_size = size; //переменная класса (поле) и локальная переменная от функции, которую мы создали внутри неё
	_data = new T[_size]; //new - выделение памяти
	for (int i = 0; i < size; i++) {
		_data[i] = data[i];
	}
	_top = top;
}
template<class T>
Stack<T>::Stack() : _data(nullptr), _size(0), _top(0) {} //список инициализации

template<class T>
Stack<T>::Stack(const Stack& other) : _capacity(other._capacity), _size(other._size) {
	_data = new T[_capacity];
	for (int i = 0; i < _size; i++) {
		_data[i] = other._data[i];
	}
}

template<class T>
Stack<T>& Stack<T>::operator=(const Stack& other) {
	if (this != &other) {
		delete[] _data;

		_capacity = other._capacity;
		_size = other._size;

		_data = new T[_capacity];
		for (int i = 0; i < _size; i++) {
			_data[i] = other._data[i];
		}
	}
	return *this;
}

template<class T>
Stack<T>:: ~Stack() {
	delete[] _data;
}

template<class T>
void Stack<T>::push(const T& val) {
	_data[++_top] = val;
}

template<class T>
void Stack<T>::pop() {
	//_data[_top] = NULL;
	_top--;
}

template<class T>
bool Stack<T>::is_empty() {
	return _top == -1; //сравниваем
}

template<class T>
bool Stack<T>::is_full() {
	return _top == _size - 1;
}

template<class T>
void Stack<T>::clear() noexcept{
	_size = 0;
	_top = -1; //присваиваем
}

#endif