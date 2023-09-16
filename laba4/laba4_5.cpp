#include "iostream"
#include "malloc.h"
#include <stdlib.h>
#define N 5

using namespace std;

int dlina1(char*);
int dlina1(const char* string);
int dlina2(char*);
int dlina3(char*);

void kopir(char*, char*);
void kopir(const char*, char*);
int sravn(char*, char*);
int sravn(const char*, const char*);
char* konkat(char*, char*);
char* konkat(const char*, const char*);

int main()
{
    string matrix[N] = {"qwer", "asdf", "zxcv", "123456", "qwer987"};
    int i;

    for (i = 0; i < N; i++) {
        cout << "Size of string["<<i<<"]="<<dlina1(matrix[i].c_str()) << endl;
    }

    for (i = 0; i < N-1; i++) {
        int comp = sravn(matrix[i+1].c_str(), matrix[i].c_str());
        cout << "Compare result str1 and str2: " << (comp == 1 ? " str1 > str2" : (comp == 0) ? " str1 = str2" : " str1 < str2") << endl;

        kopir(matrix[i+1].c_str(), (char*) matrix[i].c_str());
        cout << "Copy result: str1=" << matrix[i].c_str() << ", str2=" << matrix[i+1].c_str() << endl;

        cout << "Concat result: str1+str2=" << konkat(matrix[i+1].c_str(), matrix[i].c_str()) << endl;
        cout<<endl;
    }

    return 0;
}

int dlina1(char* string){
    int i;
    for(i = 0; string[i] != '\0'; i++);
    return i;
}

int dlina1(const char* string){
    int i;
    for(i = 0; string[i] != '\0'; i++);
    return i;
}

int dlina2(char* string){
    int i = 0;
    do {
        i++;
    } while(string[i] != '\0');
    return i;
}

int dlina3(char* string){
    int i = 0;
    while(string[i] != '\0') i++;
    return i;
}

void kopir(char* source, char* target){
    int i = 0;
    do {
        target[i] = source[i];
        i++;
    } while (source[i] != '\0');
    target[i] = '\0';
}

void kopir(const char* source, char* target){
    int i = 0;
    do {
        target[i] = source[i];
        i++;
    } while (source[i] != '\0');
    target[i] = '\0';
}

int sravn(char* left, char* right){
    int sizeL = dlina1(left);
    int sizeR = dlina1(right);
    if(sizeL != sizeR) {
        return sizeL > sizeR ? 1 : -1;
    }
    int i = 0;
    do {
        if(left[i] < right[i]) {
            return -1;
        } else if(left[i] > right[i]){
            return 1;
        }
    } while (left[i] != '\0' && right[i] != '\0');
    return 0;
}

int sravn(const char* left, const char* right){
    int sizeL = dlina1(left);
    int sizeR = dlina1(right);
    if(sizeL != sizeR) {
        return sizeL > sizeR ? 1 : -1;
    }
    int i = 0;
    do {
        if(left[i] < right[i]) {
            return -1;
        } else if(left[i] > right[i]){
            return 1;
        }
    } while (left[i] != '\0' && right[i] != '\0');
    return 0;
}

char* konkat(char* left, char* right){
    int i = 0;
    int sizeL = dlina1(left);
    int sizeR = dlina1(right);
    char* result = (char*) calloc(sizeL + sizeR + 1, sizeof(char));
    for (int j = 0; j < sizeL; j++, i++) {
        result[i] = left[j];
    }

    for (int j = 0; j < sizeR; j++, i++) {
        result[i] = right[j];
    }
    result[i] = '\0';
    return result;
}

char* konkat(const char* left, const char* right){
    int i = 0;
    int sizeL = dlina1(left);
    int sizeR = dlina1(right);
    char* result = (char*) calloc(sizeL + sizeR + 1, sizeof(char));
    for (int j = 0; j < sizeL; j++, i++) {
        result[i] = left[j];
    }
    for (int j = 0; j < sizeR; j++, i++) {
        result[i] = right[j];
    }
    result[i] = '\0';
    return result;
}
// Организоватьм ассив строк. Применить функции, написанные в предыдущем пункте к строкам
// составляющим этот массив