#include <iostream>
#include <cstring>
#include "laba6_2.h"
using namespace std;

Stroka::Stroka(char *string) {
    strcpy(str, string);
}
Stroka::Stroka(const Stroka& s) {
    strcpy(str, s.str);
}
Stroka& Stroka::operator=(const Stroka& s) {
    strcpy(str, s.str);
    return *this;
}
Stroka& Stroka::operator+(const Stroka & s) {
    strcat(str, s.str);
    return *this;
}
int Stroka::operator==(const Stroka & s) {
    if (strcmp(str, s.str) == 0)
        return 0;
    else
        return -1;
}
int Stroka::dlina() {
    return strlen(str);
}
void Stroka::vvod() {
    cout << "Enter a row: " << endl;
    cin >> str;
}
void Stroka::vyvod() {
    cout << endl;
    cout << str;
    cout << endl;
}
