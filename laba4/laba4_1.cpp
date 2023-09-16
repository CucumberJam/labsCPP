#include <iostream>
#include <cstring>

using namespace std;

void compare_rows( char [],  char []);

int main(){
    char s[] = "Hello";
    cout <<"Row is: " << s << endl;
    cout << "Length of row is: " << strlen(s) << endl;
    char a[5];
    cout << "Copy of row is : " << strcpy(a,s) << endl;

    char b[] = " World!";
    char c[20];
    cout << "Concatenation of row " << a << " and " << b << " is : " << strcat(a, b)<< endl;
    compare_rows(s,b);
    compare_rows(s,a);


    return 0;
}
void compare_rows( char first[],  char second[]){
    if(strcmp(first,second)==0){
        cout<< "Rows '"<< first << "' and '" << second << "' are equal.";
    } else{
        cout<< "Rows '"<< first << "' and '" << second << "' are not equal.";
    }
    cout  << endl;
}
// Познакомиться с библиотечными функциями работы со строками,
// Написать программу, которая использует эти функции (подключить string.h):
// strlen() - определение длины строки
// strcat() -конкатенация строк
// strcpy() - копирование одной строки в другую
// strcmp() - сравнивание строк