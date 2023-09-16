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
    T* getArray(){
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
void sort(T array[], int i);

class Couch{
private:
    int num;
public:
    Couch(){
        num = 0;
    };
    Couch(int numb){
        this->num = numb;
    };
    ~Couch(){}
    int getNumCouch(){
        return num;
    }
    bool operator>(const Couch& couch){
        return (num > couch.num)? true: false;
    }

};

int main(){
    Tstack<Couch> stackOfCouches;

/// Вложили в стэк вагонов исключительные номера:
    for(int i = 0; i < 10; i++){
        if(i==0) {
            int random = rand() % 10+1;
            Couch couch(random);
            stackOfCouches.push(couch);
        } else{
            int temp = rand() % 10 + 1;
            for(int j =0 ; j < i; j++){
                Couch tempCouch = stackOfCouches.getT(j);
                if(tempCouch.getNumCouch() == temp){
                    temp = rand() % 10+1;
                    j = -1;
                } else{
                    if(j==i-1){
                        Couch couch(temp);
                        stackOfCouches.push(couch);
                    }
                }
            }
        }
    }

    cout << "Checking of random push within 10: " << endl;
    for(int i = 0; i< 10; i++){
        Couch temp = stackOfCouches.getT(i);
        cout << temp.getNumCouch()  << " ";
    }
    cout <<  endl;

/// Вызвали функцию сортировки:
    sort(stackOfCouches.getArray(), 10);

/// Вывели номера вагонов через pop:
    cout << "Checking of pop: " << endl;
    for(int i = 0; i< 10; i++){
        Couch temp = stackOfCouches.pop();
        cout << temp.getNumCouch()  << " ";
    }
    return 0;
}
template<class T>
void sort(T array[], int size) {
    T temp;
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}
// Написать программу, выполняющую сортировку железнодорожного состава с использованием тупика
// Работу выполнить с использованием шаблона класса TStack