#include <iostream>
#include <cstring>

using namespace std;

class Stroka{
    char* str;
public:
    Stroka(char*);
    Stroka(){
        cout << "Empty constructor: \t" << this << endl;
    };
    Stroka (const Stroka&);
    ~Stroka() {
        clearStr();
        cout << "Deconstruct is working: \t" << this << endl;
    };
    Stroka& operator = (const char *);
    Stroka& operator + (const Stroka&);
    int operator == (Stroka&);
    int dlina();
    void vvod();
    void vyvod();
private:
    void clearStr(){
        if(NULL == str){
            delete[] str;
        }
    }

    void alloc(const char* s) {
        clearStr();
        str = (char*) malloc(sizeof s);
    }

    void alloc(const char* s1, const char* s2) {
        clearStr();
        str = (char*) malloc((sizeof s1) + (sizeof s2));
    }
};

Stroka::Stroka(char *string) {
    alloc(string);
    int i;
    for(i = 0; string[i] != '\0'; i++){   // strcpy(str, string);
        str[i] = string[i];
    }
    str[i] = '\0';
    cout << "Constructor is working: \t" << this << endl;
}
Stroka::Stroka(const Stroka& s) {
    alloc (s.str);
    int i;
    for(i = 0; s.str[i] != '\0'; i++){   // strcpy(str, s.str);
        str[i] = s.str[i];
    }
    str[i] = '\0';
    cout << "Constructor of coping is working: \t" << this << endl;
}

Stroka& Stroka::operator=(const char* string) {
    alloc(string);
    int i;
    for(i = 0; string[i] != '\0'; i++){   // strcpy(str, string);
        str[i] = string[i];
    }
    str[i] = '\0';
    return *this;
}
Stroka& Stroka::operator+(const Stroka & s) {
    str = (char*) realloc(str, sizeof str + sizeof s.str);
    int i, j;
    for(i = 0; str[i] != '\0'; i++);
    for(j = 0; s.str[j] != '\0'; j++, i++){  // strcat(str, s.str);
        str[i] = s.str[j];
    }
    str[i] = '\0';
    return *this;
}
int Stroka::operator==(Stroka& s) {
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
    for(int i = 0; str[i] != '\0'; i++){  // return strlen(str);
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
    s3 = "asdfg";
    s3.vyvod();
    s5 = s1+s3+s4;
    cout << "Length s5 = " << s5.dlina() << endl;
    s5.vyvod();
    if(s1==s5) {
        cout << "Rows s1 and s5 equal." << endl;
    } else if(s1==s4) {
        cout << "Rows s1 and s4 equal." << endl;
    }

    return 0;
}
// Доделать описание класса конструктором, который создает экземпляры класса,
// используя заданный размер динамической памяти.
// Понадобится ли при наличии такого конструктора деструктор?