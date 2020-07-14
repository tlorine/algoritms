#include "header.h"
#include "iostream"

class quickImp {
private:
    int *array_id;
    int *branch_size;
    int size_array;
public:
    quickImp(int n);
    ~quickImp();
    int compound(int a, int b);
    int unionElem(int a, int b);
    int root(int id);
    void printArray();
};

quickImp::quickImp(int n) {
    array_id = new int[n];
    branch_size = new int[n];
    size_array = n;

    for (int i = 0; i < size_array; i++) {
        array_id[i] = i;
        branch_size[i] = 1;
    }
}

quickImp::~quickImp() {
    delete array_id;
    delete branch_size;
}

int quickImp::root(int id) {
    while (array_id[id] != id) {
        id = array_id[array_id[id]];
    }
    return (id);
}

int quickImp::unionElem(int a, int b) {
    int parentA;
    int parentB;

    if (a < 0 || a > size_array - 1)
        return (-1);
    if (b < 0 || b > size_array - 1)
        return (-1);
    parentA = root(a);
    parentB = root(b);
    if (branch_size[parentA] < branch_size[parentB]) {
        array_id[parentA] = parentB;
        branch_size[parentB] = branch_size[parentA] + branch_size[parentB];
    } 
    else {
        array_id[parentB] = parentA;
        branch_size[parentA] = branch_size[parentA] + branch_size[parentB];
    }
}

int quickImp::compound(int a, int b) {
    if (a < 0 || a > size_array - 1)
        return (-1);
    if (b < 0 || b > size_array - 1)
        return (-1);
    if (root(a) == root(b))
        return (1);
    return (0);
}

void quickImp::printArray() {
    for(int i = 0; i < size_array; i++) {
        std::cout << "[" << array_id[i] << ":" << branch_size[i] << "] ";
    }
    std::cout << "\n";
}