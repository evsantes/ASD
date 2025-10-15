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
	T size() const; //необходимо дл€ тестов??
	bool is_empty();
	bool is_full();
	void clear() noexcept;
	Stack(); //объ€вление функции
	Stack(T* data, int size, int top); //конструктор инициализации
};

template<class T>
Stack<T>::Stack(T* data, int size, int top) {
	//прописываем тело функции
	_size = size; //переменна€ класса (поле) и локальна€ переменна€ от функции, которую мы создали внутри неЄ
	_data = new T[_size]; //new - выделение пам€ти
	for (int i = 0; i < size; i++) {
		_data[i] = data[i];
	}
	_top = top;
}
template<class T>
Stack<T>::Stack() : _data(nullptr), _size(0), _top(0) {} //список инициализации

//еще какие-нибудь конструкторы

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