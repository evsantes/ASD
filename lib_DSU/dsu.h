#ifndef DSU_H_
#define DSU_H_

template <class T>
class DSU {
    int* _rank;
    int* _parents;
    int _size;
public:
    DSU(int _size);
    DSU(const DSU& other);
    void unite(int, int);
    int find(int);
    T& operator[](int);
    ~DSU();
};

template<class T>
DSU<T>::DSU(int size) : _size(size) {
    _rank = new int[size];
    _parent = new int[size];
    for (int i = 0; i < _size; i++) {
        _rank[i] = i;
        _parent[i] = i;
    }
}

template<class T>
DSU<T>::DSU(const DSU& other) :_size(other._size) {
    _rank = new int[size];
    _parents = new int[size];
    for (int i = 0; i < _size; i++) {
        _rank[i] = other._rank[i];
        _parent[i] = other._parents[i];
    }
}

//template<class T>
//T& DSU<T>::operator[](int index) {
//  return _rank[index];
//  return _parent[index];
//}

template<class T>
DSU<T>::~DSU() {
    delete[] _rank;
    delete[] _parent;
}

template<class T>
int DSU<T>::find(int x) {
    if (_parent[x] == x) { return x; }
    else { return x = find(_parent[x]); }
}

template<class T>
void DSU<T>::unite(int x1, int x2) {
    int rank_x1 = rank[find(x1)];
    int rank_x2 = rank[find(x2)];
    if (rank_x1 < rank_x2) {
        _parent[x1] = find(x2);
    }
    else {
        if (_rank[x1] = _rank[x2]) {
            _rank[x1]++;
        }
        else { _parent[x2] = find(x1); }
    }
}

#endif