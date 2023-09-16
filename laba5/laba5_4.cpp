#include "stdio.h"
#include <iostream>
#include <cstring>

using namespace std;

int main(){
    char ch, ch2;
    string filename;
    cout << "Enter name of file to read: ";  // C:\Users\tutorial\test3.txt
    getline(cin, filename);
    FILE *in = fopen(filename.c_str(), "r");

/// Найдем количество строк:
    int count = 0;
    if(in == NULL){
        printf("Error while opening file %s", filename.c_str());
    } else{
        while ((ch=getc(in)) != EOF){
            if(ch == '\n'){
                count++;
            }
            printf("%c", ch);
        }
        fclose(in);
        cout << endl;
        printf("Amount of rows in file: %d\n", count);
    }

/// Внесем строки в массив:
    FILE * in2 = fopen(filename.c_str(), "r");
    string array_text[count];

    for(int i = 0; i < count; i++) {
        while ((ch2 = getc(in2)) != '\n') {
            array_text[i] += ch2;
        }
        array_text[i] += '\n';
    }
    fclose(in2);

/// Перенесем номера страниц из первой строки в последнюю:
    for(int i = 0; i < count-1; i++) {
        string temp = array_text[i];
        array_text[i] = array_text[i+1];
        array_text[i+1] = temp;
    }

//    cout << array_text[0]<< endl;
//    cout << array_text[count-1]<< endl;

/// Уберем из последней строки все что не цифры:
    const char* ptr = array_text[count-1].c_str();
    for(int i = 0; i < strlen(ptr); i++) {
        if(!isdigit(ptr[i])){
            array_text[count-1].erase(i, 1);
        }
    }

//    cout << array_text[count-1]<< endl;

/// Перезапишем массив обратно в файл:
    const char *pch;
    char * pathResult = "laba5_4.txt";
    FILE * wr = fopen(pathResult, "w");
    if(wr == NULL) {
        printf("Error while file opening.\n");
    } else{
        for(int i = 0; i < count;i++){
            pch = array_text[i].c_str();
            fputs(pch, wr);
        }
        printf("File has been written\n");
    }
    fclose(wr);

    delete ptr, pch;
    return 0;
}
// Написать программу, которая обрабатывает текстовый файл следующим образом:
// В исходном тексте номера страниц проставлены первой строке страницы.
// Требуется перенести эти нмоера в последнюю строку страницы и убрать знаки переноса.
// Например, номер страницы: - 34 -.
// Необходимо получить 34.
// Признаком перехода на следующую страницу является управляющий символ '\f'.








//fwrite(array_text+i,sizeof (string), 1, wr); //fprintf(wr, "%s\n", array_text[i].c_str());

// Другой вариант открытия файла для строковой записи из строкового массива:
//    ofstream out;    // поток для записи
//    out.open(name); // окрываем файл для записи
//    if(out.is_open()){
//        for(int i = 0; i < count;i++){
//            out << array_text[i] << endl;
//        }
//    }else{
//        printf("Error while file opening.\n");
//    }
//    out.close();