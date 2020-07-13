#include "header.h"
#include "iostream"

class quickUnion {
private:
    int *array_id;
    int size_array;
public:
    quickUnion(int n);
    ~quickUnion();
    int compound(int a, int b);
    int unionElem(int a, int b);
    int root(int id);
    void printArray();
};

quickUnion::quickUnion(int n) {
    array_id = new int[n];
    size_array = n;

    for (int i = 0; i < size_array; i++) {
            array_id[i] = i;
    }
}

quickUnion::~quickUnion() {
    delete array_id;
}

int quickUnion::root(int id) {
    while (array_id[id] != id) {
        id = array_id[id];
    }
    return (id);
}

int quickUnion::unionElem(int a, int b) {
    int parentA;
    int parentB;

    if (a < 0 || a > size_array - 1)
        return (-1);
    if (b < 0 || b > size_array - 1)
        return (-1);
    parentA = root(a);
    parentB = root(b);
    array_id[parentA] = parentB;
}

int quickUnion::compound(int a, int b) {
    if (a < 0 || a > size_array - 1)
        return (-1);
    if (b < 0 || b > size_array - 1)
        return (-1);
    if (root(a) == root(b))
        return (1);
    return (0);
}

void quickUnion::printArray() {
    for(int i = 0; i < size_array; i++) {
        std::cout << "[" << array_id[i] << "] ";
    }
    std::cout << "\n";
}