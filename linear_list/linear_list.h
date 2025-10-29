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
	Iterator begin() {
		return Iterator;
	}
	Iterator end() {
		return Iterator(nullptr);
	}

	class Iterator {
		Iterator() : current(_head) {}
		Iterator(Node<T>*pos) : current(pos) {}
		Iterator(const Iterator&other) : current(other.current) {}

		Iterator& operation = (const Iterator & other);
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

};

//прописать все

