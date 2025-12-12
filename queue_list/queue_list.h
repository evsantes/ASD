#ifndef QUEUE_LIST_H
#define QUEUE_LIST_H
#include "linear_list.h"

template <typename T>
class Queue {
    List<T> _list;  
    int _count; 

public:
    Queue();
    Queue(T* data, int size);  
    Queue(const Queue& other);
    ~Queue();
    Queue& operator=(const Queue& other);
    void push(const T& val);       // Добавление в конец
    void pop();                    // Удаление из начала
    T head();                // Получение первого элемента
    int size() const;              // Размер очереди
    bool is_empty() const;         // Проверка на пустоту
    bool is_full() const;          // Проверка на заполненность
    void clear() noexcept;         // Очистка очереди
    T back();                // Получение последнего элемента
};

// Конструктор по умолчанию
template<class T>
Queue<T>::Queue() : _count(0) {}

// Конструктор с массивом
template<class T>
Queue<T>::Queue(T* data, int size) : _count(0) {
    for (int i = 0; i < size; i++) {
        push(data[i]);
    }
}

// Конструктор копирования
template<class T>
Queue<T>::Queue(const Queue& other) : _list(other._list), _count(other._count) {}

// Деструктор
template<class T>
Queue<T>::~Queue() {
    clear();  // Список сам очистится
}

// Оператор присваивания
template<class T>
Queue<T>& Queue<T>::operator=(const Queue& other) {
    if (this != &other) {
        _list = other._list;
        _count = other._count;
    }
    return *this;
}

// Добавление элемента в очередь
template<class T>
void Queue<T>::push(const T& val) {
    _list.push_back(val);
    _count++;
}

// Удаление элемента из очереди
template<class T>
void Queue<T>::pop() {
    if (is_empty()) {
        throw std::logic_error("Queue is empty!");
    }
    _list.pop_front();
    _count--;
}

// Получение первого элемента (головы)
template<class T>
T Queue<T>::head(){
    if (is_empty()) {
        throw std::logic_error("Queue is empty!");
    }
    return _list.front();
}

// Получение последнего элемента (хвоста)
template<class T>
T Queue<T>::back(){
    if (is_empty()) {
        throw std::logic_error("Queue is empty!");
    }
    return _list.back();
}

// Размер очереди
template<class T>
int Queue<T>::size() const {
    return _count;
}

// Проверка на пустоту
template<class T>
bool Queue<T>::is_empty() const {
    return _list.is_empty();
}

// Проверка на заполненность
template<class T>
bool Queue<T>::is_full() const {
    return false;  // Очередь на списке никогда не заполнена
}

// Очистка очереди
template<class T>
void Queue<T>::clear() noexcept {
    _list.clear();
    _count = 0;
}

#endif