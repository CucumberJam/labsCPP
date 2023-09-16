#include "iostream"
using namespace std;
// шаблон функции воспринимает один параметр произвольного типа:
template<class T>
void func(T t){}
// шаблон функции воспринимает два параметра одного произвольного типа:
template<class  T>
void func1(T t1, T t2){}
// шаблон функции воспринимает два параметра различного или одного и того же произвольного типа
template<class T1, class T2>
void func2(T1 t1, T2 t2){}

// обменивает содержимое массива с указанными индексами:
template<class T>
void swap(T t[], int i1, int i2);
// сортирует содержимое массива по убыванию:
template<class T>
void sort(T array[], size_t size);

class Money{
     long dollars;
     int cents;
public:
    Money(){}
    Money(long dollars, int cents){
        this->dollars = dollars;
        this->cents = cents;
    }
    int operator>(const Money&) const;
    friend ostream & operator << (ostream&, Money&);
};

int main(void){
    int i;
    int mas[] = {10, 20, 30, 11, 25, 32, 01};
    sort(mas, sizeof mas/sizeof mas[0]);
    for(i=0; i < sizeof mas/ sizeof mas[0]; i++){
        cout << "mas[" << i << "] = " << mas[i] << endl;
    }

    Money masMoney[] = { Money(19,10), Money(99,99), Money(99,95), Money(19,95)};
    sort(masMoney, sizeof (masMoney)/sizeof masMoney[0]);
    for(i=0; i < sizeof masMoney/ sizeof masMoney[0]; i++){
        cout << "mas[" << i << "] = " << masMoney[i] << endl;
    }

}
template<class T>
void swap(T t[], int i1, int i2){
    T tmp = t[i1];
    t[i1] = t[i2];
    t[i2] = tmp;
}
template<class T>
void sort(T array[], size_t size){
    int i, j;
    T tmp;
    for(i=0; i < size; i++){
        for(j=size-1; i<j; j--){
            if(array[i] > array[j]){
                tmp = array [j];
                array[j] = array[j-1];
                array[j-1] = tmp;
            }
        }
    }
}
int Money::operator>(const Money& amt) const {
    return (dollars>amt.dollars) || ((dollars == amt.dollars) && (cents> amt.cents));
}
ostream & operator<<(ostream& os, Money& amt){
    os << "$ " << amt.dollars << '.' << amt.cents;
    return os;
}
// Отладить программу, иллюстрирующую применение шаблона Sort  к типу,
// определенному пользователем (п. 9.1.1)