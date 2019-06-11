#include <iostream>
#include <string>

int main() {
    std::cout << "Please enter your name";
    std::string name;
    std::cin >> name;
    std::cout << "Hello " << name  << "\n" << std::endl;
    return 0;
}