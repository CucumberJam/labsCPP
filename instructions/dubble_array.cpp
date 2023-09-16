#include <iostream>

using namespace std;

int main() {

    int **dinamic_array2 = new int* [5];   // создаем
    for (int i = 0; i < 5; i++) {          // двумерный
        dinamic_array2[i] = new int [i + 1]; // массив
    }                                      // !

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < i + 1; j++) {
            cout << "Enter numbers" << "(" << i + 1 << ")" << "(" << j + 1 << ")" << ":";
            cin >> dinamic_array2[i][j];
        }
    }

    for (int i = 0; i < 5; i++) {
        int sum = 0;
        for (int j = 0; j < i + 1; j++) {
            sum += dinamic_array2[i][j];
        }
        cout << "Sum " << i + 1 << " of array is " << sum << endl;
    }

    for (int i = 0; i < 5; i++) {
        delete [] dinamic_array2[i];  // удаляем массив
    }

    delete []dinamic_array2;

    system("pause");
    return 0;
}
