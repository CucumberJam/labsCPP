#include "string"
#include "iostream"
#include "memory"

using namespace std;

int main(){
    int SIZE;
    cin >> SIZE;
//    int *arr = new int [SIZE];
//    shared_ptr<int[]> ptr(arr);
    shared_ptr<int[]> ptr(new int[SIZE] {1, 2,44,72});

    for(int i  = 0; i< SIZE; i++){
        ptr[i] = rand() % 10;
        cout << ptr[i] << endl;
    }




    return 0;
}
