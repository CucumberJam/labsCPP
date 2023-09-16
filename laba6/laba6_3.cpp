#include <iostream>
#include <cstring>

using namespace std;

class Stroka{
    char str[80]{};
public:
    Stroka(char*);
    Stroka(){};
    ~Stroka(){};
    Stroka (const Stroka&); //  конструктора копирования
    Stroka& operator = (Stroka &);
    Stroka& operator + (const Stroka&);
    int operator == (Stroka&);
    int dlina();
    void vvod();
    void vyvod();
};
Stroka::Stroka(char *string) {
    int i;
    for(i = 0; string[i] != '\0'; i++){   // strcpy(str, string);
        str[i] = string[i];
    }
    str[i] = '\0';
}
Stroka::Stroka(const Stroka& s) {
    int i = 0;
    do{
        str[i] = s.str[i];     //  strcpy(str, s.str);
        i++;
    }while(s.str[i] != '\0');
    str[i]='\0';

}
Stroka& Stroka::operator=(Stroka &s) {
    int i;
    for(i = 0; s.str[i] != '\0'; i++){
        str[i] = s.str[i];
    }
    str[i] = '\0';
    return *this;
}
Stroka& Stroka::operator+(const Stroka & s) {
    int i, j;
    for(i = 0; str[i] != '\0'; i++);
    for(j = 0; s.str[j] != '\0'; j++, i++){
        str[i] = s.str[j];
    }
    str[i] = '\0';
    return *this;
}
int Stroka::operator==(Stroka & s) {
    if((this->dlina())< s.dlina()) return -1;
    else if(this->dlina()>s.dlina()) return 1;
    else{
        for(int i = 0; str[i] != '\0'; i++){
            if(s.str[i] != str[i]){
                if(str[i]< s.str[i]) return -1;
                else if(str[i]> s.str[i]) return 1;
                else return 0;
            }
        }
    }
}
int Stroka::dlina() {
    int count = 0;
    for(int i = 0; str[i] != '\0'; i++){
        count++;
    }
    return count;
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
    s3 = (Stroka &) "asdfg";
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
// Изменить программу так, чтобы вместо библиотечных функций, выполняющих действия со строкой,
// использовались аналогичные функции, написанные при выполнении заданий ЛР № 4.
