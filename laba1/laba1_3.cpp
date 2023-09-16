#include <iostream>
int a, b;
void obmen1(int, int);
void obmen2(int*, int*);
void obmen3(int&, int&);

int main() {
    a = 2, b = 5;
    std::cout << "Before exchange: a = \t" << a << ", b = \t" << b << std::endl;
    obmen1(a, b);
    std::cout << "After exchange1: a = \t" << a << ", b = \t" << b << std::endl;
    a = 2, b = 5;
    obmen2(&a, &b);
    std::cout << "After exchange2: a = \t" << a << ", b = \t" << b << std::endl;
    a = 2, b = 5;
    obmen3(a, b);
    std::cout << "After exchange3: a = \t" << a << ", b = \t" << b << std::endl;
    return 0;
}
void obmen1(int x, int y){
    int temp = x;
    x = y;
    y = temp;
    std::cout << "In method exchange 1 local variables changed:\n"
                 " a = \t" << x << ", b = \t" << y << std::endl;
}

void obmen2(int* px, int* py){
    int temp = *px;
    *px = *py;
    *py = temp;
}
void obmen3(int& x, int& y){
    int temp = x;
    x = y;
    y = temp;



}
/* Написать программу, которая меняет местами значения двух переменных.
 * В качестве параметра использовать int, int* и int&.
 * Структура программы следующая: функция main() вводит переменные и вызывает
 * другую функцию, которая и выполняе обмен.
 *
 * Написать 3 варианта функции обмена. В качестве параметров эта цункция в
 * первый раз получает два параметра типа int, второй раз - типа int*, третий раз -
 * типа int&.
 * Придумайте способ достижения результата в каждом из трех вариантов.*/