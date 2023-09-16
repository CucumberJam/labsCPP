#include <iostream>
using namespace std;
int const N = 10;

void show_massive(int [], int);
void sort_period_down(int [], int, int);

int main() {

    int index1, index2;
    int mas[] = {1,12,-8,0,-4,-88,3,
                 -5,-9,28,};
    cout << "Massive before sorting: ";
    show_massive(mas, N);

    do{
        cout << "Enter index from which sort massive (1-9): ";
        cin >> index1;
    }while (index1 < 1 || index1 > 9);
    do{
        cout << "Enter index to which sort massive (2-10): ";
        cin >> index2;
    }while (index2 < 2 || index1 > 10);
    index1--;
    index2--;


    sort_period_down(mas, index1, index2);
    cout << "Massive after sorting from highest to lowest from index: " << index1+1 << " to index " << index2+1 <<": " << endl;
    show_massive(mas, N);


    return 0;
}

void show_massive(int array[], int size){
    for(int  i = 0; i < size; i++){
        cout << array[i] << " ";
    }
    cout << endl;
}

void sort_period_down(int array[], int index1, int index2){
    for(int i = index1; i < index2; i++){
        for(int j= i+1; j<= index2; j++){
            if(array[i] < array[j]) {
                swap(array[i], array[j]);
            }
        }
    }

}
// Отсортировать массив по убыванию на интервале индексов от N1 до N2