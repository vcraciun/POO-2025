#include "Header1.h"

int main()
{
    /*
    B b(5,10);
    std::cout << b.calcul() << std::endl;
    std::cout << b.A::calcul() << std::endl;
    A* ptr = new B(3, 4);
    std::cout << ptr->calcul();
    delete ptr;
    */

    Example t(16, 6);
    std::cout << t.calcul() << '\n';
    {
        Example t2 = t;
        std::cout << t2.calcul() << '\n';
    }
    std::cout << t.calcul() << '\n';
    return 0;
}