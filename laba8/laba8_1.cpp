#include <iostream>
#include <cstring>
#include <fstream>

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
    char* getStr();
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
char* Stroka::getStr(){
    return str;
}

ostream& operator<<(ostream& os, Stroka& stroka){ //перегружаем метод вывода путем передачи ссылки базовому классу на проиводный и на объект
    os<< stroka.getStr();
    return os;
}
istream& operator>>(istream& is, Stroka& stroka){ //перегружаем метод ввода путем передачи ссылки базовому классу на проиводный и на объект
    is >> stroka.getStr();
    return is;
}

int main(void){
    Stroka s1("qwert");

    string path = "laba8_1.txt";
    fstream fs;
    fs.open(path, fstream:: in | fstream:: out | fstream:: app);
    if(!fs.is_open()){
        cout << "Error while opening." << endl;
    } else {
        cout << " File is opened!" << endl;
        fs << s1 << "\n";
        while (true) {
            Stroka strTemp;
            fs >> strTemp;
            strTemp.vyvod();
            if(fs.eof()){
                break;
            }
        }
    }
    fs.close();
    return 0;

}
// Для класса , написанного в ЛР 6, предусмотреть возможность ввода - вывода
// его объектов при помощи операций помещения и извлечения (аналогично тому,
// как это делается для объектов стандартных типов данных).