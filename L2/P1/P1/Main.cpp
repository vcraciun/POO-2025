#include <iostream>
#include <cstdlib>
#include <ctime>
typedef int (*func)(int, int);

int dreptunghi(int a, int b) {
    return a * b;
}

int patrat(int a, int b) {
    return a * a;
}

int cerc(int a, int b) {
    return 3.1415f * a * a;
}

int suma(int a, int b) {
    return a + b;
}

int diferenta(int a, int b) {
    return a - b;
}

int produsul(int a, int b) {
    return a * b;
}

int restul(int a, int b) {
    return a % b;
}

int catul(int a, int b) {
    return a / b;
}

func operatii[8] = { dreptunghi, patrat, cerc, suma, diferenta, catul, restul,produsul };
std::string functii[8] = { "dreptunghi","patrat","cerc","suma","diferenta","catul","restul","produsul" };
int main() {
    srand(time(0));
    int r,a,b;
    for (int i = 1; i <= 100; ++i) {
        r = rand() % 8;
        a = rand() % 20;
        b = rand() % 20;
        std::cout << functii[r] << '(' << a << ','<< b << ") = " << operatii[r](a, b) << '\n';
    }
    return 0;
}