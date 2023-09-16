#include "iostream"
#include "string.h"

using namespace std;

template<class T>
T getMax(T t1, T t2){
    return t1 > t2 ? t1: t2;
}
// перегрузка шаблона функции
template<class T>
T getMax(T t[], size_t size){
    T retval = t[0];
    for(int i = 0; i< size; i++){
        if(t[i] > retval) retval = t[i];
    }
    return retval;
}
char* getMax(char *s1, char *s2){
    return strcmp(s1, s2) > 0? s1: s2;

}
int main(){
    int i1 = 3, i2 = 5;
    int mas[] = {3, 9, 5, 8};

    cout << "max int = " << getMax(i1, i2) << endl;
    cout << " max int in array = " << getMax(mas, sizeof mas/sizeof mas[0]) << endl;

    char *s1 = "row1";
    char *s2 = "row2";
    cout << "max row = " << getMax(s1, s2) << endl;

    return 0;
}
// Выполнить примеры из п. 9.1.2. и 9.1.3.