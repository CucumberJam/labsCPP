#include <iostream>
#include <cstring>

using namespace std;

class Stroka{
    char str[80]{};
public:
    Stroka(char*);
    Stroka(){};
    Stroka (const Stroka&); //  конструктора копирования
    ~Stroka()= default;
    Stroka& operator = (const Stroka &);
    Stroka& operator + (const Stroka&);
    int operator == (const Stroka&);
    int dlina();
    void vvod();
    void vyvod();
};
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
// Описать класс для работы со строкой, как со стандартным типом данных
// В разделе описания элементов - данных класс должен иметь переменную
// для хранения символьной строки.
// В разделе описания элементов-функций необходимо предусмотреть:
// - конструкторы в нескольких вариантах;
// - деструкторы, если необходимо;
// - перегруженные операции для выполнения присваивания (=),
// сцепления (+) и сравнения (==);
// - методы для определения длины строки;
// - методы ввода и вывода строки.