#ifndef STACK_LIST_H
#define STACK_LIST_H
#include "linear_list.h"

template<class T>
class Stack {
private:
    List<T> list;
public:
    Stack() = default;
    Stack(const Stack& other) : list(other.list) {}
    ~Stack() = default;

    Stack& operator=(const Stack& other) {
        if (this != &other) {
            list = other.list;
        }
        return *this;
    }

    void push(const T& val) noexcept {
        list.push_front(val);  // В стеке добавляем в начало
    }

    void pop() {
        if (is_empty()) {
            throw std::logic_error("Stack is empty");
        }
        list.pop_front();  // Из стека удаляем из начала
    }

    T top() {
        if (is_empty()) {
            throw std::logic_error("Stack is empty");
        }
        return list.front();  // Верхний элемент - первый в списке
    }

    bool is_empty() const {
        return list.is_empty();
    }

    int size() const {
        return list.size();
    }

    void clear() noexcept {
        list.clear();
    }

    bool is_full() const {
        return false;  
    }
};


#endif