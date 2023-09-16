#include "iostream"
#include "string.h"

using namespace std;

template <class T>
class Tstack{
protected:
    int numIItem;
    T *item;
public:
    Tstack(size_t size = 10){
        numIItem = 0;
        item = new T[size];
    }
    ~Tstack(){
        delete [] item;
    }
    T* getTarray(){
        return item;
    }
    T getT(int i){
        return item[i];
    }
    void push(T t);
    T pop();
    friend void sort(T array[], int i);
};

template<class T>
void Tstack<T>::push(T t) {
    item[numIItem++] = t;
}

template <class T>
T Tstack<T>::pop() {
    return item[--numIItem];
}

template <class T>
class Tarray{
protected:
public:
    Tarray(int size = 100){

    }
    ~Tarray(){

    }
    void add(T item);

};
// ������������������ ������� ������ add ��� char*;
template<> void Tarray<char*>::add(char *str) {

}
// ���������� ����������� ������ add ��� ���� �
template <class T>
void Tarray<T>::add(T item) {

}
/// ��������� ������� ����� ���� ������ � �����������:
template <class T, int num>
class TypeBlock{
protected:
    T* p;
public:
    TypeBlock(){
        p = new T[num];
    }
    ~TypeBlock(){
        delete [] p;
    }
    operator T*(){
        return p;
    }
};

/// ��������� ������� ����� ���� �����������:
template <int size>
class Memblock{
protected:
    char * p;
public:
    Memblock(){
        p = new char[size];
    }
    ~Memblock(){
        delete [] p;
    }
    operator char *(){
        return p;
    }
};
int main(){
    Memblock<512> Block;
    strcpy(Block, "String 1");
    cout << (char*)Block << endl;


    Tstack<int> st_int1; // ���� �������� int, ������ �� ���������
    Tstack<int> st_int(2); // ���� �������� int �� 40 ���������
    Tstack<long> *ptr_st_long;  // ��������� �� ���� �� long
    Tstack<double> dbl[10];  // ������ ���� ��� double
    Tstack<char*> cSt; // ���� ���������� �� char
    Tstack<char*> *precSt; // ��������� �� ���� ��� ���������� �� char
    precSt = new Tstack <char*> (20);

    int i1 = 10;
    Tarray<int> iarray;
    iarray.add(i1);
    char *msg = "Row of symbols.";
    Tarray<char*> strArray;
    strArray.add(msg);

    return  0;
}
