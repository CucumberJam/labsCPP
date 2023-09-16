#include <stdlib.h>
#include <iostream>
using namespace std;

int dlina1(char*);
int dlina2(char*);
int dlina3(char*);

void kopir(char *, char*);
int sravn(char*, char*);
char* konkat(char*, char*);

void show_massive(char*);

int main()
{
    int size;
    cout << "Enter number of elements in array: " << endl;
    cin >> size;
    char *str1, *str2;
    str1 = (char*) malloc(size);
    str2 = (char*) malloc(size);

    cout << "Length row 1: " << dlina1(str1) << ", " << dlina2(str1) << ", " << dlina3(str1)<< endl;
    cout << "Length row 2: " << dlina1(str2) << ", " << dlina2(str2) << ", " << dlina3(str2)<< endl;


    kopir("Stroka 1", str1);
    kopir("Stroka 2", str2);

    cout << "Length after  kopir():" << endl;
    cout << "Length row 1: " << dlina1(str1) << ", " << dlina2(str1) << ", " << dlina3(str1)<< endl;
    cout << "Length row 2: " << dlina1(str2) << ", " << dlina2(str2) << ", " << dlina3(str2)<< endl;

    int compare = sravn(str1, str2);
    cout << "Result of comparing: ";
    if(compare == 1){
        cout << "row1 > row2" << endl;
    } else if(compare == -1){
      cout << "row1 < row 2" << endl;
    } else{
        cout << "row 1 = row 2" << endl;
    }
    cout << "Concat result : row1 + row 2 = " << konkat(str1, str2) << endl;


    free(str1);
    free(str2);

    return 0;
}
int dlina1(char * string){
    int i;
    for(i=0; string[i] != '\0'; i++);
    return i;
}

int dlina2(char* string){
    int i = 0;
    do {
        i++;
    }while(string[i] != '\0');
    return i;
}

int dlina3(char* string){
    int i = 0;
    while(string[i] != '\0') i++;
    return i;
}

void kopir(char* source, char* target){
    int i = 0;
    do{
        target[i] = source[i];
        i++;
    }while(source[i] != '\0');
    target[i]='\0';
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

char* konkat(char* left, char* right){
    int i = 0;
    int sizeL = dlina1(left);
    int sizeR = dlina1(right);
    char* result = (char*) malloc(sizeR+sizeL+1);
    for(int j = 0; j < sizeL; j++, i++){
        result[i] = left[j];
    }
    for(int j = 0; j < sizeR; j++, i++){
        result[i] = right[j];
    }
    result[i] = '\0';

    return result;
}

void show_massive(char* array){
    cout << "Elements of massive: " << endl;
    for(int i = 0; array[i] != '\0'; i++){   // array[i] != '\0'
        cout << array[i] << " ";
    }

}
// Переписать функции так, чтобы они использовали динамическую память при задании строк





















// s.c_str()
//std::string message {"hello"};
//const char* message_ptr = message.c_str();

//     unsigned i;
//    for(i=0; i < size-1; i++){
//       cout << "Enter elements:" << endl;
//        if(cin.peek()==' ') array[++i]=' ';
//        ++i;
//        if(cin.peek()=='\n') break;
//    }
//    array[i] = '\0';

//void create_char_array(char* array){
//    int size;
//    cout << "Enter number of elements in array: " << endl;
//    cin >> size;
//    array = (char*)malloc(size * sizeof(char));
//    cout << "Enter elements of massive: " << endl;
//    int i;
//    for(i = 0; i < size-1; i++){
//        cout << "[" << i+1 << "]: ";
//        cin >> array[i];
//    }
//    array[i]='\0';
//}

// int sravn(char* left, char* right){
//    int sizeL = dlina1(left);
//    int sizeR = dlina1(right);
//    if(sizeL!=sizeR){
//        return sizeL >sizeR ? 1: -1;
//    }
//    int i = 0;
//    do{
//        if(left[i] < right[i]){
//            return -1;
//        } else if(left[i] > right[i]){
//            return 1;
//        }
//    } while (left[i] != '\0' && right[i] != '\0');
//    return 0;
//}