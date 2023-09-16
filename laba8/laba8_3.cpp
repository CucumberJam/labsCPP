#include "stdio.h"
#include <iostream>
#include "math.h"

using namespace std;
void encrypt(string& nameFr, string& key, string& nameFwr);
void check(string& nameFr, string& key);

int main(void){
    string key;
    cout << "Enter key as a row: " << endl;
    getline(cin, key);

    string pathFileRead;
    cout << "Enter name of file to read: ";
    // C:\Users\tutorial\laba5_5_file_to_read.txt
    getline(cin, pathFileRead);

    string pathFileWrite;
    cout << "Enter name of file to write: " << endl;
    // data_laba8_3.txt
    getline(cin, pathFileWrite);

    encrypt(pathFileRead, key, pathFileWrite) ;

/// Проверка:
    cout << endl;
    cout << "After checking:" << endl;
    check(pathFileWrite, key);

}
void encrypt(string& nameFr,string& key, string& nameFwr){
    FILE * file_ptr = fopen(nameFr.c_str(), "r");
    if(file_ptr == NULL) {
        cout << "Problem with opening file for reading\n";
    }
    FILE * resultFile = fopen(nameFwr.c_str(), "w");
    if(resultFile == NULL) {
        printf("Problem with opening file for writing\n");
    }

    char ch;
    int keyIndex = 0;
    while (!feof(file_ptr)){
        ch = getc(file_ptr);
        printf("%c", ch);
        int keyVal = (int) key[keyIndex];
        if(keyIndex == key.length()-1) {
            keyIndex = 0;
        } else{
            keyIndex++;
        }

        char resch = (char)pow(ch, keyVal)%256; //(ch^keyVal)%256
        cout << resch;
        fputc(resch, resultFile);

    }
    fclose(file_ptr);
    fclose(resultFile);
}

void check(string& nameFr, string& key) {
    FILE *file_ptr = fopen(nameFr.c_str(), "r");
    if (file_ptr == NULL) {
        cout << "Problem with opening file for reading during checking\n";
    }
    char ch;
    int keyIndex = 0;
    while (!feof(file_ptr)) {
        ch = getc(file_ptr);
        int keyVal = (int) key[keyIndex++];
        if(keyIndex == key.length()-1) {
            keyIndex = 0;
        } else{
            keyIndex++;
        }

        char resch = (char) (ch ^ keyVal);
        cout << resch;
    }
}
// Написать программу - шифратор файлов
// Она читает из файла и пишет в другой файл закодированные символы.
// Схема шифровки: с=с:  , где с - символ, считанный из файла
//  - ключ шифрования, строка, которая передается как параметр заданной строки.
// Программа использует символы из циклически, пока не будет считан весь ввод.
// Для проверки правильности программы зашифровать шифрованный файл еще раз с тем же ключом.
// Должен получиться файл - ТОЧНАЯ копия исходного файла.
// Дополнить программу п. 5 возможностью вводить имя файла и ключ из командной строки.
