#include "header.h"

int main() {
    quickImp qf(10);

    qf.unionElem(5, 4);
    qf.unionElem(0, 4);
    qf.unionElem(6, 1);
    qf.unionElem(6, 0);
    qf.printArray();
}