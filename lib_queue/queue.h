#ifndef STACK_H
#define STACK_H

template <typename T>
class Queue {
	T* _data; //динамический массив
	int _size; //размер
	int _head; //индекс начала очереди
	int _tail; //индекс конца очереди
	int _count; //количество?
public:
	void push(const T& val);
	void pop();
	T head() const;
	T size() const; //необходимо дл€ тестов
	bool is_empty();
	bool is_full();
	void clear() noexcept;
	Queue(); //объ€вление функции
	Queue(T* data, int head, int count, int tail, int size); //конструктор инициализации
};

template<class T>
Queue<T>::Queue(T* data, int head, int count, int tail, int size) {
	//прописываем тело функции
	_size = size; //переменна€ класса (поле) и локальна€ переменна€ от функции, которую мы создали внутри неЄ
	_data = new T[_size]; //new - выделение пам€ти
	for (int i = 0; i < count; i++) {
		_data[i] = data[i];
	}
	//_head = head;
}

template<class T>
Queue<T>::Queue() : _data(nullptr), _count(0), _head(0), _size(size), _tail(-1) {} //список инициализации

//еще какие-нибудь конструкторы

template<class T>
void Queue<T>::push(const T& val) {
	if (is_full()) {
		throw logic_error("Queue is full!");
	}
	_count++;
	_data[(++_tail) % size] = val;
}

template<class T>
void Queue<T>::pop() {
	if (is_empty()) {
		throw logic_error("Queue is empty!");
	}
	//_data[_head] = NULL;
	_count--;
	head = (++head) % _size;
}

template<class T>
bool Queue<T>::is_empty() {
	return _count == 0; //сравниваем
}

template<class T>
bool Queue<T>::is_full() {
	return _count == _size;
}

template<class T>
void Queue<T>::clear() noexcept {
	_count = 0;
	_tail = -1;
	_head = 0; //присваиваем
}

#endif 