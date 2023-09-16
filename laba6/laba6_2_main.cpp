#include <iostream>
#include "laba6_2.h"

using namespace std;

int main(void){
    Stroka s1("qwert"), s3, s4(s1), s5;
    s3.vvod();
    s3 = (Stroka &)"asdfg";
    s3.vyvod();
    s5 = s1+s3+s4;
    cout << endl;
    cout << "Length s5 = " << s5.dlina();
    s5.vyvod();
    if(s1==s5)
        cout << "Rows s1 and s5 equal.";
    else
    if(s1==s4)
        cout << "Rows s1 and s4 equal.";
}
// Описание класса выделить в заголовочный файл, определение его методов - в файл
// с расширение .cpp, текст главной функции написать в отдельном файле.