#include <iostream>

using namespace std;

int dlina1(char*);
int dlina2(char*);
int dlina3(char*);
void kopir(char*, char*);
int sravn(char*, char*);
void konkat(char*, char*);

int main() {
    char str1[] = "qwerty", str2[] = "1234567890";

   cout << "dlina1 of str1 = " << dlina1(str1)<<endl;
   cout << "dlina1 of str2 = " << dlina1(str2)<<endl;

    cout << "dlina2 of str1 = " << dlina2(str1)<<endl;
    cout << "dlina2 of str2 = " << dlina2(str2)<<endl;

    cout << "dlina3 of str1 = " << dlina3(str1)<<endl;
    cout << "dlina3 of str2 = " << dlina3(str2)<<endl;

    kopir(str1, str2);

    if(sravn(str1, str2) != 0){
        cout << "str1 and str2 are not equal " << endl;
    }else {
        cout << "str1 and str2 are  equal " << endl;
    }
    konkat(str1, str2);
    cout << str1 <<endl;

    for(int i = 0; i< sizeof (str1); i++){
        cout <<"i: " << i << " value: " << str1[i] <<endl;
    }
    return 0;
}
int dlina1(char* array){
    int count = 0;
    for(int i = 0; array[i] != '\0'; i++){   // пока не конец строки
        count++;
    }
   return count;
}

int dlina2(char* array){
    int i =0;
    while(array[i] != '\0'){
        i++;
    }
    return i;
}
int dlina3(char* array){
    int i =0;
    do{
        i++;
    }while(array[i] != '\0');
    return i;
}
void kopir(char* array1, char* array2){
    for(int i = 0; array1[i] != '\0'; i++){   // пока не конец строки
        array2[i] = array1[i];
    }
}
int sravn(char*array1, char* array2){
    int size1 = dlina1(array1);
    int size2 = dlina1(array2);
    if(size1<size2) return -1;
    else if(size1>size2) return 1;
    else{
        for(int i = 0; array1[i] != '\0'; i++){   // пока не конец строки
            if(array2[i] != array1[i]){
                if(array1[i]< array2[i]) return -1;
                else if(array1[i]> array2[i]) return 1;
                else return 0;
            }
        }
    }

}
void konkat(char* array1, char* array2){
    int i, j;
    for(i = 0; array1[i] != '\0'; i++);
    for(j = 0; array2[j] != '\0'; j++){
        array1[i] = array2[j];
        i++;
    }
    array1[i] = '\0';
}

// Написать свои варианты функций:
// - определение длины строки (выполнить программу тремя способами)
// - копирование строк
// - сравнения строк
// - конкатенации строк