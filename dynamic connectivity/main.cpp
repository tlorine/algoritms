#include "header.h"

int main() {
    quikFind qf(10);

    qf.unionElem(2, 3);
    qf.unionElem(7, 8);
    qf.unionElem(7, 0);
    qf.unionElem(7, 2);
    qf.unionElem(1, 0);
    qf.printArray();
}