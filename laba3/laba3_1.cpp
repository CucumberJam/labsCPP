#include <iostream>
using namespace std;

int main(void) {

    int mas[] = {2,5,-8,1,-4,6,3,
                 -5,-9,13,0,4,9};

    int imin;
    imin = 0;
    int size = sizeof(mas)/sizeof(int);

    for(int i = 0; i< size; i++){
        cout << mas[i] << " ";
    }
    cout << endl;

    for(int i = 0; i< size-1; i++){             // перебирает массив с первого по предпоследний элемент;
        imin = i;                               // переменной присваивается позиция первого сравниваемого элемента массива;
        for(int j = i+1; j < size; j++){       // перебирает массив со второго по последний элемент;
            if(mas[j] < mas[imin]) imin = j;   // если следующий элемент меньше текущего, то переменной присваивается индекс следующего элемента
        }                                       // соответственно результатом перебора массива является индекс самого маленького элемента;
        int t = mas[i];                       // временной переменной присваиваится значение текущего элемента массива;
        mas[i] = mas[imin];                   // текущему элементу присваивается значение самого маленького элемента из текущей итерации;
        mas[imin] = t;                         // в номер самого маленького элемента записывается значение текущего элемента массива
    }                                           // соответственно результат - обмен позициями в массиве самого маленького и текущего значений

    for(int i = 0; i< size; i++){
        cout << mas[i] << " ";
    }
    cout << endl;
}
// Разобраться как работаетп редложенная программа сортировки массива методом мини-макса
















//    j=size;
//    while (i!=j)
//    {
//        for(m=0;m<size-1;m++)
//        {
//            min=mas[i];
//            max=mas[j];
//            for(i=1;i<size-1;i++)
//            {
//                if(mas[i]<min)
//                {
//                    min=mas[i];
//                }
//                else
//                    if(mas[i]>max)
//                    {
//                        max=mas[i];
//                    }
//            }
//            mas[i]=min;
//            mas[size-1]=max;
//            i++;
//            j--;
//        }
//    }