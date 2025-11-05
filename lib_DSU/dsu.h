#ifndef DSU_H_
#define DSU_H_

template <class T>
class DSU {
    int* _rank;
    int* _parent;
    int _size;
public:
    DSU(int _size);
    DSU(const DSU& other);
    void unite(int, int);
    int find(int);
    ~DSU();
};

template<class T>
DSU<T>::DSU(int size) : _size(size) {
    _rank = new int[size];
    _parent = new int[size];
    for (int i = 0; i < _size; i++) {
        _rank[i] = 0;
        _parent[i] = i;
    }
}

template<class T>
DSU<T>::DSU(const DSU& other) :_size(other._size) {
    _rank = new int[_size];
    _parent = new int[_size];
    for (int i = 0; i < _size; i++) {
        _rank[i] = other._rank[i];
        _parent[i] = other._parent[i];
    }
}

template<class T>
DSU<T>::~DSU() {
    delete[] _rank;
    delete[] _parent;
}

template<class T>
int DSU<T>::find(int x) {
    if (_parent[x] == x) { return x; }
    else { return _parent[x] = find(_parent[x]); }
}

template<class T>
void DSU<T>::unite(int x1, int x2) {
    int rank_x1 = find(x1);
    int rank_x2 = find(x2);
    if (_rank[rank_x1] < _rank[rank_x2]) {
        _parent[x1] = find(x2);
    }
    else if (_rank[rank_x1] > _rank[rank_x2]){
        _parent[x2] = find(x1);

        //if (_rank[x1] = _rank[x2]) {
        //    _rank[x1]++;
        //}
        //else { _parent[x2] = find(x1); }
    }
    else {
        _parent[x2] = find(x1);
        _rank[rank_x1]++;
    }
}

#endif