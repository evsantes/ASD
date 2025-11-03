#include <iostream>

template<class T>
struct Node {
	T value;
	Node<T>* next;
	Node(T value, Node<T>* next = nullptr) : value(value), next(next) {}
};

template<class T>
class List {
	Node<T>* _head;
	int _count;
	Node<T>* _tail;

public:
	class Iterator {
		Iterator() : current(_head) {}
		Iterator(Node<T>*pos) : current(pos) {}
		Iterator(const Iterator&other) : current(other.current) {}
        
		Iterator& operator= (const Iterator & other);
		T& operator*();
		bool operator!=(const Iterator& other);
		Iterator operator++(int);//x++
		Iterator& operator++();//++x
	};

	List();
    List(const List& other);
    ~List();
    List& operator=(const List& other);

    bool is_empty() const;
    int size() const;
	Node<T>* find(const T& val);
	Node<T>* get_head() const;
	Node<T>* get_tail() const;
    T& front();
    T& back();

    void push_front(const T& val) noexcept;
    void push_back(const T& val) noexcept;
    void insert(int pos, const T& val);
	void insert(Node<T>* node, const T& val);
    void pop_front();
    void pop_back();
    void erase(Node<T>* node);
    void clear();

    Iterator begin() {
        return Iterator;
    };
    Iterator end() {
        return nullptr;
    };

};

template<class T>
typename List<T>::Iterator& List<T>::Iterator::operator=(const Iterator& other) {
    current = other.current;
    return *this;
}

template<class T>
T& List<T>::Iterator::operator*() {
    return current->value;
}

template<class T>
bool List<T>::Iterator::operator!=(const Iterator& other) {
    return current != other.current;
}

template<class T>
typename List<T>::Iterator List<T>::Iterator::operator++(int) {
    Iterator temp = *this;
    current = current->next;
    return temp;
}

template<class T>
typename List<T>::Iterator& List<T>::Iterator::operator++() {
    current = current->next;
    return *this;
}

// Реализация List
template<class T>
List<T>::List() {
    _head = nullptr;
    _count = 0;
    _tail = nullptr;
}

template<class T>
List<T>::List(const List& other) {
    _head = nullptr;
    _count = 0;
    _tail = nullptr;

    Node<T>* current = other._head;
    while (current != nullptr) {
        push_back(current->value);
        current = current->next;
    }
}

template<class T>
List<T>::~List() {
    clear();
}

template<class T>
List<T>& List<T>::operator=(const List& other) {
    if (this == &other) {
        return *this;
    }

    clear();

    Node<T>* current = other._head;
    while (current != nullptr) {
        push_back(current->value);
        current = current->next;
    }

    return *this;
}

template<class T>
bool List<T>::is_empty() const {
    return _head == nullptr;
}

template<class T>
int List<T>::size() const {
    return _count;
}

template<class T>
Node<T>* List<T>::find(const T& val) {
    Node<T>* current = _head;
    while (current != nullptr) {
        if (current->value == val) {
            return current;
        }
        current = current->next;
    }
    return nullptr;
}

template<class T>
Node<T>* List<T>::get_head() const {
    return _head;
}

template<class T>
Node<T>* List<T>::get_tail() const {
    return _tail;
}

template<class T>
T& List<T>::front() {
    return _head->value;
}

template<class T>
T& List<T>::back() {
    return _tail->value;
}

template<class T>
void List<T>::push_front(const T& val) noexcept {
    Node<T>* new_node = new Node<T>(val, _head);
    _head = new_node;
    if (_tail == nullptr) {
        _tail = _head;
    }
    _count++;
}

template<class T>
void List<T>::push_back(const T& val) noexcept {
    Node<T>* new_node = new Node<T>(val);
    if (_tail == nullptr) {
        _head = _tail = new_node;
    }
    else {
        _tail->next = new_node;
        _tail = new_node;
    }
    _count++;
}

template<class T>
void List<T>::insert(int pos, const T& val) {
    if (pos == 0) {
        push_front(val);
        return;
    }

    if (pos == _count) {
        push_back(val);
        return;
    }

    Node<T>* current = _head;
    for (int i = 0; i < pos - 1; i++) {
        current = current->next;
    }

    Node<T>* new_node = new Node<T>(val, current->next);
    current->next = new_node;
    _count++;
}

template<class T>
void List<T>::insert(Node<T>* node, const T& val) {
    if (node == nullptr) {
        push_back(val);
        return;
    }

    Node<T>* new_node = new Node<T>(val, node->next);
    node->next = new_node;

    if (node == _tail) {
        _tail = new_node;
    }
    _count++;
}

template<class T>
void List<T>::pop_front() {
    if (_head == nullptr) {
        return;
    }

    Node<T>* temp = _head;
    _head = _head->next;
    delete temp;
    _count--;

    if (_head == nullptr) {
        _tail = nullptr;
    }
}

template<class T>
void List<T>::pop_back() {
    if (_head == nullptr) {
        return;
    }

    if (_head == _tail) {
        delete _head;
        _head = _tail = nullptr;
    }
    else {
        Node<T>* current = _head;
        while (current->next != _tail) {
            current = current->next;
        }
        delete _tail;
        _tail = current;
        _tail->next = nullptr;
    }
    _count--;
}

template<class T>
void List<T>::erase(Node<T>* node) {
    if (node == nullptr || _head == nullptr) {
        return;
    }

    if (node == _head) {
        pop_front();
        return;
    }

    Node<T>* current = _head;
    while (current->next != node && current->next != nullptr) {
        current = current->next;
    }

    if (current->next == node) {
        current->next = node->next;
        if (node == _tail) {
            _tail = current;
        }
        delete node;
        _count--;
    }
}

template<class T>
void List<T>::clear() {
    while (_head != nullptr) {
        pop_front();
    }
}

