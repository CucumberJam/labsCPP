#include <iostream>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;
const int N = 5;

float max_massive(float [][N]);
float min_massive(float [][N]);
float max_massive_low_tr(float [][N]);
float min_massive_low_tr(float [][N]);
float max_massive_high_tr(float [][N]);
float min_massive_high_tr(float [][N]);
float max_massive_diag_major(float [][N]);
float min_massive_diag_major(float [][N]);
float max_massive_diag_add(float [][N]);
float min_massive_diag_add(float [][N]);
float arifmean_massive(float [][N]);
float arifmean_massive_low_tr(float [][N]);
float arifmean_massive_high_tr(float [][N]);
float sum_rows_massive(float [][N], int, int);
float sum_columns_massive(float [][N], int, int);
float minelement_row_massive(float [][N], int);
float maxelement_row_massive(float [][N], int);
float arifmean_row_massive(float [][N], int);
float minelement_column_massive(float [][N], int);
float maxelement_column_massive(float [][N], int);
float arifmean_column_massive(float [][N], int);
float sum_massive_low_tr(float [][N]);
float sum_massive_high_tr(float [][N]);
float sum_massive_high_low_tr(float [][N]);
float closest_arifmean_massive(float [][N]);


int main() {

//// создали массив:
    float m[N][N];

//// заполнили массив:
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            m[i][j] = rand() % 10;
        }
    }

//// вывели массив на экран:
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cout << m[i][j]  << " ";
        } cout <<std::endl;
    }
    cout <<std::endl;

//// вывели максимум функции:
    float max = max_massive(m);
    cout << "Max function: " << max  << endl;

//// вывели минимум функции:
    float min = min_massive(m);
    cout << "Min function: " << min << endl;
    cout <<std::endl;

//// вывели нижнетреугольный массив на экран:
    cout << "Low triangle:";
    for(int i = 0; i < N; i++){
        for(int j = 0; j < i; j++){
            cout << m[i][j]  << " ";
        } cout << endl;
    }

    cout << "Max function in low triangle: " <<
        max_massive_low_tr(m) << endl;

    cout << "Min function in low triangle: " <<
        min_massive_low_tr(m) << endl;
    cout <<endl;

//// вывели верхнетреугольный массив на экран:
    cout << "High triangle:" << endl;
    for(int i = 0; i < N-1; i++){
        for(int j = i+1; j < N; j++){
            cout << m[i][j]  << " ";
        } std::cout <<std::endl;

        for(int j = 0; j <= i; j++){
            cout << "  ";
        }
    }
    cout <<std::endl;
    cout << "Max function in high triangle: " <<
        max_massive_high_tr(m) << endl;

    cout << "Min function in high triangle: " <<
        min_massive_high_tr(m) << endl;
    cout << endl;

//// вывели главную диагональ массива на экран:
    cout << "Main diagonal:" << endl;
    for(int i = 0; i < N; i++){
        cout << m[i][i]  << " ";
        cout << endl;
        for(int j = 0; j <= i; j++){
            cout << "  ";
        }
    }
    cout <<std::endl;
    cout << "Max function in major diagonal: " <<
        max_massive_diag_major(m) << endl;

    cout << "Min function in major diagonal: " <<
        min_massive_diag_major(m) << endl;
    cout << endl;

//// вывели второстепенную диагональ массива на экран:
    cout << "Additional diagonal:" << endl;
    for(int k=4, i = 0; i < N; i++){
        for(int j = 4-i; j >= k; j--){
            for(int n = 0; n < j ; n++){
                cout << "  ";
            }
            cout << m[i][j]  << " ";
        } k--;
        cout << endl;
    }
    cout << endl;

    cout << "Max function in additional diagonal: " <<
        max_massive_diag_add(m) << endl;

    cout << "Min function in additional diagonal: " <<
        min_massive_diag_add(m) << endl;
    cout << endl;

//// вывели среднее арифметическое значение элементов массива:
    cout << "Arithmetic mean of array elements: " <<
        arifmean_massive(m) << endl;
    cout << endl;

//// вывели среднее арифметическое значение элементов массива нижнетреугольной матрицы:
    cout << "Arithmetic mean of array elements in low triangle: " <<
        arifmean_massive_low_tr(m) << endl;
    cout << endl;

//// вывели среднее арифметическое значение элементов массива верхнетреугольной матрицы:
    cout << "Arithmetic mean of array elements in high triangle: " <<
        arifmean_massive_high_tr(m) << endl;
    cout << endl;

//// вывели сумму строк массива:
    int row1, row2;
//    row1 = 0;  // не забудь потом закомментить
//    row2 = 4;  // не забудь потом закомментить
    do{
        std::cout << "Enter a first number of rows to add (1-5): \n";
        std:: cin >>  row1;
    } while (row1 <= 0 ||  row1 > 5);
    do{
        std::cout << "Enter a second number of rows to add (1-5): \n";
        std:: cin >>  row2;
    } while (row2 <= 0 ||  row2 > 5);
    row1--;
    row2--;
    cout << "Sum of rows " << row1 << " and " << row2 << " in massive is: " <<
        sum_rows_massive(m, row1, row2) << endl;
    cout << endl;

//// вывели сумму столбцов массива:
    int column1, column2;
//    column1 = 0;  // не забудь потом закомментить
//    column2 = 4;  // не забудь потом закомментить
    do{
        std::cout << "Enter a first number of columns to add (1-5): \n";
        std:: cin >>  column1;
    } while (column1 <= 0 ||  column1 > 5);
    do{
        std::cout << "Enter a second number of columns to add (1-5): \n";
        std:: cin >>  column2;
    } while (column2 <= 0 ||  column2 > 5);
    column1--;
    column2--;
    cout << "Sum of columns " << column1+1 << " and " << column2+1 << " in massive is: " <<
        sum_columns_massive(m, column1, column2) << endl;
    cout << endl;

//// вывели минимальное значение строки массива:
    cout << "Minimum element of row " << row1+1 << " in massive is: " <<
    minelement_row_massive(m, row1) << endl;

//// вывели максимальное значение строки массива:
    cout << "Maximum element of row " << row2+1 << " in massive is: " <<
        maxelement_row_massive(m, row2) << endl;

//// вывели среднеарифметическое значение строки массива:
    cout << "Arithmetic mean of row " << row2+1 << " in massive is: " <<
        arifmean_row_massive(m, row2) << endl;
    cout << endl;

//// вывели минимальное значение столбца массива:
    cout << "Minimum element of column " << column1+1 << " in massive is: " <<
        minelement_column_massive(m, column1) << endl;

//// вывели максимальное значение столбца массива:
    cout << "Maximum element of column " << column2+1 << " in massive is: " <<
        maxelement_column_massive(m, column2) << endl;

//// вывели среднеарифметическое значение столбца массива:
    cout << "Arithmetic mean of column " << column2+1 << " in massive is: " <<
        arifmean_column_massive(m, column2) << endl;
    cout << endl;

//// вывели суммы нижне- верхнетреугольных частей массива:
    cout << "Sum of of array elements in low and high triangles: "
        <<  sum_massive_high_low_tr(m) << endl;
    cout << endl;

//// вывели элемент, наиболее близкий по значению к среднеарифметическому элементу массива:
    cout << "the element closest in group to the arithmetic mean element of the array: "
         <<  closest_arifmean_massive(m) << endl;
    cout << endl;

    return 0;
}

 float max_massive(float massive[][N]){
    float min=massive[0][0],max=massive[0][0];
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(massive[i][j]>max) max=massive[i][j];
            if(massive[i][j]<min) min=massive[i][j];
        }
    }
    return max;
}

float min_massive(float massive[][N]){
    float min=massive[0][0],max=massive[0][0];
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(massive[i][j]>max) max=massive[i][j];
            if(massive[i][j]<min) min=massive[i][j];
        }
    }
    return min;
}

float max_massive_low_tr(float massive[][N]){
    float min=massive[0][0],max=massive[0][0];
    for(int i=0;i<N;i++){
        for(int j=0;j<i;j++){
            if(massive[i][j]>max) max=massive[i][j];
            if(massive[i][j]<min) min=massive[i][j];
        }
    }
    return max;
}
float min_massive_low_tr(float massive[][N]){
    float min=massive[0][0],max=massive[0][0];
    for(int i=0;i<N;i++){
        for(int j=0;j<i;j++){
            if(massive[i][j]>max) max=massive[i][j];
            if(massive[i][j]<min) min=massive[i][j];
        }
    }
    return min;
}
float max_massive_high_tr(float massive[][N]){
    float min=massive[0][0],max=massive[0][0];
    for(int i = 0; i < N; i++){
        for(int j = i+1; j < N; j++){
            if(massive[i][j]>max) max=massive[i][j];
            if(massive[i][j]<min) min=massive[i][j];
        }
    }
    return max;
}

float min_massive_high_tr(float massive[][N]){
    float min=massive[0][0],max=massive[0][0];
    for(int i = 0; i < N; i++){
        for(int j = i+1; j < N; j++){
            if(massive[i][j]>max) max=massive[i][j];
            if(massive[i][j]<min) min=massive[i][j];
        }
    }
    return min;
}
float max_massive_diag_major(float massive[][N]){
    float min=massive[0][0],max=massive[0][0];
    for(int i = 0; i < N; i++){
            if(massive[i][i]>max) max=massive[i][i];
            if(massive[i][i]<min) min=massive[i][i];
        }
    return max;
}
float min_massive_diag_major(float massive[][N]){
    float min=massive[0][0],max=massive[0][0];
    for(int i = 0; i < N; i++){
        if(massive[i][i]>max) max=massive[i][i];
        if(massive[i][i]<min) min=massive[i][i];
    }
    return min;
}
float max_massive_diag_add(float massive[][N]){
    float min=massive[0][0],max=massive[0][0];
    for(int k=4, i = 0; i < N; i++){
        for(int j = 4-i; j >= k; j--){
            if(massive[i][j]>max) max=massive[i][j];
            if(massive[i][j]<min) min=massive[i][j];
        } k--;
    }
    return max;
}
float min_massive_diag_add(float massive[][5]){
    float min=massive[0][0],max=massive[0][0];
    for(int k=4, i = 0; i < N; i++){
        for(int j = 4-i; j >= k; j--){
            if(massive[i][j]>max) max=massive[i][j];
            if(massive[i][j]<min) min=massive[i][j];
        } k--;
    }
    return min;
}
float arifmean_massive(float massive[][N]){
    float sum = 0;
    float getArrayLength=0;
    for(int i = 0;i < N;i++){
        for(int j = 0;j < N;j++){
            sum+= massive[i][j];
            getArrayLength++;
        }
    }
    return sum / getArrayLength;
}
float arifmean_massive_low_tr(float massive[][N]){
    float sum = 0;
    float getArrayLength=0;
    for(int i=0;i<N;i++){
        for(int j=0;j<i;j++){
            sum+= massive[i][j];
            getArrayLength++;
        }
    }
    return sum / getArrayLength;
}
float arifmean_massive_high_tr(float massive[][5]){
    float sum = 0;
    float getArrayLength = 0;
    for(int i = 0; i <= 4; i++){
        for(int j = i+1; j <=4; j++){
            sum+= massive[i][j];
            getArrayLength++;
        }
    }
    return sum / getArrayLength;
}

float sum_rows_massive(float massive[][N], int row1, int row2){
    float sum = 0;
    for(int j = 0; j < N; j++){
        sum += massive[row1][j];
    }
    for(int j = 0; j < N; j++){
        sum += massive[row2][j];
    }
    return sum;
}
float sum_columns_massive(float massive[][N], int column1, int column2){
    float sum = 0;
    for(int i = 0; i < N; i++){
        sum += massive[i][column1];
    }
    for(int i = 0; i < N; i++){
        sum += massive[i][column2];
    }
    return sum;
}

float minelement_row_massive(float massive[][N], int row){
    float temp = massive[row][0];
    for(int j = 1; j < N; j++){
        if(temp>massive[row][j]){
            temp = massive[row][j];
        }
    }
    return temp;
}
float maxelement_row_massive(float massive[][N], int row){
    float temp = massive[row][0];
    for(int j = 1; j < N; j++){
        if(temp<massive[row][j]){
            temp = massive[row][j];
        }
    }
    return temp;
}
float arifmean_row_massive(float massive[][N], int row){
    float sum, numbers;
    sum = numbers = 0;
    for(int j = 0; j < N; j++){
        sum +=massive[row][j];
        numbers++;
    }
    return sum/numbers;
}

float minelement_column_massive(float massive[][N], int column){
    float temp = massive[0][column];
    for(int i = 1; i < N; i++){
        if(temp>massive[i][column]){
            temp = massive[i][column];
        }
    }
    return temp;
}
float maxelement_column_massive(float massive[][N], int column){
    float temp = massive[0][column];
    for(int i = 1; i < N; i++){
        if(temp<massive[i][column]){
            temp = massive[i][column];
        }
    }
    return temp;
}

float arifmean_column_massive(float massive[][N], int column){
    float sum, numbers;
    sum = numbers = 0;
    for(int i = 0; i < N; i++) {
        sum += massive[i][column];
        numbers++;
    }
    return sum/numbers;
}
float sum_massive_low_tr(float massive[][N]){
    float sum = 0;
    for(int i = 0;i < N;i++){
        for(int j = 0;j<i;j++){
            sum+= massive[i][j];
        }
    }
    return sum;
}
float sum_massive_high_tr(float massive[][N]){
    float sum = 0;
    for(int i = 0; i < N; i++){
        for(int j = i+1; j < N; j++){
            sum+= massive[i][j];
        }
    }
    return sum;
}
float sum_massive_high_low_tr(float massive[][N]){
    float sum = sum_massive_high_tr(massive) + sum_massive_low_tr(massive);
    return sum;
}
float closest_arifmean_massive(float massive[][N]){
    float element = 0;
    float average = arifmean_massive(massive);
    float min = abs(massive[0][0] - average);
    for(int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            float temp = abs(massive[i][j] - average);
            if(temp < min){
                min = temp;
                element = massive[i][j];
            }
        }
    }
    return element;
}
