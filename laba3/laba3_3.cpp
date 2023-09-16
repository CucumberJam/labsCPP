#include <iostream>
using namespace std;
int const N = 10;

void show_massive(int [], int);
void sort_even_rise(int [], int);
void sort_add_down(int [], int);

int main() {

    int mas1[] = {2,5,-8,1,-4,6,3,
                 -5,-9,13,};
    cout << "Massive first: ";
    show_massive(mas1, N);
    sort_even_rise(mas1, N);
    cout << "Massive first after sort_even_rise: ";
    show_massive(mas1, N);


    int mas2[] = {9,-4,0,5,-2,3,8,
                  7,-2,1,};
    cout << "Massive second: ";
    show_massive(mas2, N);
    sort_add_down(mas2, N);
    cout << "Massive second after sort_add_down: ";
    show_massive(mas2, N);


    return 0;
}
void show_massive(int array[], int size){
    for(int  i = 0; i < size; i++){
        cout << array[i] << " ";
    }
    cout << endl;
}
void sort_even_rise(int array[], int size) {
    for (int i = 0; i < size - 1; i++) {
        if (array[i] % 2 == 0){
            for (int j = i+1; j < size; j++) {
                if ((array[j] % 2 == 0) && (array[i] > array[j])) {
                    swap(array[i], array[j]);
                }
            }
        }
    }
}

void sort_add_down(int array[], int size){
    for (int i = 0; i < size - 1; i++) {
        for (int j = i+1; j < size; j++) {
            if (array[i] % 2 !=0 && array[j] % 2 != 0 && (array[i] < array[j])) {
                swap(array[i], array[j]);

            }
        }
    }
}
//  для массива целых значений выполнить сортировку по возрастанию четных
// и по убыванию нечетных значений
