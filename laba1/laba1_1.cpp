#include <iostream>

int power(int, int);

int main() {
    std::cout << "Program of exponential 2 to 10 degree: "<< std::endl;
    for (int i = 0; i < 10; i++) {
        int k = power(2, i);
        std::cout << "degree = " << i << ", result = " << k << std::endl;
    }std::cout <<std::endl;

    int number, degree;
    std::cout << "What number you want exponentiate? "<< std::endl;
    std:: cin >> number;
    do {
        std::cout << "To what degree ? " << std::endl;
        std::cin >> degree;
        if(degree<0){ std::cout << "Invalid degree, try again. " << std::endl;}
    }while(degree<0);

    std::cout << "result = "<< power(number, degree) << std::endl;
    return 0;
}
int power(int number, int degree) {
        int temp = 1;
        for (int i = 0; i < degree; i++) {
            temp *= number;
        }
        return temp;
}
/* Ознакомиться сос труктурой программы на языке С++.
 * Для этого выполнить программу возведения числа 2 в степень.
 * Модифицировать программу так, чтобы вычислялась степен с любым основанием.*/
