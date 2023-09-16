#include <iostream>
using namespace std;
int const N = 10;

void show_massive(int [], int);
void quick_sort(int [], int, int);
int partition(int [], int, int);


int main() {

    int array2[] = {6, 8, 3, 2, 1,
                    5, 9, 0, -2, -4};
    cout << "Aray2: ";
    show_massive(array2, N);
    quick_sort(array2, 0, N-1);
    cout << "Aray2 after quick sort: ";
    show_massive(array2, N+1);

    return 0;
}
void quick_sort(int array[], int start, int end) {

    if (start >= end) return;

    int pivot = partition(array, start, end);

    quick_sort(array, start, pivot - 1);
    quick_sort(array, pivot + 1, end);
}

int partition(int array[], int start, int end) {

    int pivot = array[end];
    int pi = start;

    for (int i = start; i < end; i++)
    {
        if (array[i] <= pivot)
        {
            swap(array[i], array[pi]);
            pi++;

        }
    }
    swap(array[pi], array[end]);

    return pi;
}
