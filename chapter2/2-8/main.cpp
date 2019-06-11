#include <iostream>

int main() {
    int fac = 1;
    int n = 1;
    while (n != 10) {
        fac *= n;
        n++;
    }
    std::cout << fac << std::endl;
}