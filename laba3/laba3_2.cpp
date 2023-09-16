#include <iostream>
using namespace std;
int const N = 10;

void show_massive(int [], int);
void bubble_sort(int [], int);
void quick_sort(int [], int);

int main() {

    int array1[] = {10, 1, 9, 2, 8,
                   3, 7, 4, 6, -4};
    cout << "Aray1: ";
    show_massive(array1, N);
    bubble_sort(array1, N);
    cout << "Aray1 after bubble sort: ";
    show_massive(array1, N);



    int array2[] = {67, -8, 23, 5, 1,
                    100, 12, 0, -1, 0};
    cout << "Aray2: ";
    show_massive(array2, N);
    quick_sort(array2, N);
    cout << "Aray2 after quick sort2: ";
    show_massive(array2, N);

    return 0;
}
void show_massive(int array[], int size){
    for(int  i = 0; i < size; i++){
        cout << array[i] << " ";
    }
    cout << endl;
}
void bubble_sort(int array[], int size){
    int temp;
    for(int i = 0; i < size-1; i++ ){
        for(int j = 0; j < size-i-1; j++){
            if(array[j]>array[j+1]){
                temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
}
void quick_sort(int *array , int size){
    int i =0;
    int j = size - 1;

    int mid = array[size/2];

    do{
        while (array[i] < mid){
            i++;
        }
        while (array[j] > mid){
            j--;
        }
        if(i<=j){
            int temp = array[i];
            array[i] = array[j];
            array[j] = temp;
            i++;
            j--;
        }
    } while (i<=j);

    if(j>0){
        quick_sort(array, j+1);
    }
    if(i < size){
        quick_sort(&array[i], size-i);
    }

}

// Написать программы, сортирующие одномерный массив методами "пузырька"
// и "быстрой сортировки"