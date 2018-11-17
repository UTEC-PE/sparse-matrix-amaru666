#include <iostream>

#include "matrix.h"

using namespace std;

int main(int argc, char *argv[]) {
    Matrix<int> a(4, 4);

    a.set(1,2,6);
    a.set(3,0,7);

    Matrix<int>b(4,2);

    b.set(2,1,8);

    //system("PAUSE");
    return EXIT_SUCCESS;
}