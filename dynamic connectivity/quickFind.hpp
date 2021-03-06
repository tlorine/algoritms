#include "header.h"
#include "iostream"

class quickFind {
private:
    int *array_id;
    int size_array;
public:
    quickFind(int n);
    ~quickFind();
    int compound(int a, int b);
    int unionElem(int a, int b);
    void printArray();
};

quickFind::quickFind(int n) {
    array_id = new int[n];
    size_array = n;

    for (int i = 0; i < size_array; i++) {
            array_id[i] = i;
    }
}

quickFind::~quickFind() {
    delete array_id;
}

int quickFind::unionElem(int a, int b) {
    if (a >= size_array || a < 0)
        return (-1);
    if (b >= size_array || b < 0)
        return (-1);
    a = array_id[a];
    b = array_id[b];
    for (int i = 0; i < size_array; i++) {
        if (array_id[i] == b)
            array_id[i] = a;
    }
    return (1);
}

int quickFind::compound(int a, int b) {
    if (a >= size_array || a < 0)
        return (-1);
    if (b >= size_array || b < 0)
        return (-1);
    if (array_id[a] == array_id[b])
        return (1);
    else
        return (0);
}

void quickFind::printArray() {
    for(int i = 0; i < size_array; i++) {
        std::cout << "[" << array_id[i] << "] ";
    }
    std::cout << "\n";
}