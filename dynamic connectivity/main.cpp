#include "header.h"

int main() {
    quickUnion qf(10);

    qf.unionElem(4, 3);
    qf.unionElem(1, 3);
    qf.unionElem(4, 3);
    qf.unionElem(7, 1);
    qf.unionElem(8, 4);
    qf.printArray();
}