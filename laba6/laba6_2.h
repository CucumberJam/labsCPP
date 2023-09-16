#ifndef LABSCPP_LABA6_2_H
#define LABSCPP_LABA6_2_H

#endif //LABSCPP_LABA6_2_H
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