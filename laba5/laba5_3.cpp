#include "stdio.h"
#include <iostream>

#define MAX 30
std::string find_row_in_row(char*, std::string);
using namespace std;

int main(void) {
/// Зададим искомую строку:
    char *seeking_row = (char*)malloc((MAX+1)*sizeof(char));
    printf("Enter seeking row (maximum 30 symbols): ");
    if (fgets(seeking_row, MAX, stdin)) { //  считывание строки с консоли.
        printf("Seeking row: %s\n", seeking_row);
    } else {
        printf("Critical Error!");
    }
   string seek_row = (string)seeking_row;

    /// Откроем файл для чтения (поиска искомой строки):
    char ch;
    string file_text;
    string filename;
    cout << "Enter name of file to read: ";  // C:\\Users\\tutorial\\test2.txt
    getline(cin, filename);
    FILE *fr = fopen(filename.c_str(), "r");

    if (fr == NULL) {
        printf("Error while opening file for reading ", filename.c_str());
    } else {
        while ((ch = getc(fr)) != EOF) {
            file_text.push_back(ch);
        }
        fclose(fr);
    }
    cout << "String of text is: " << file_text << endl; // проверка: вывод текста на экран

    string message = find_row_in_row(seeking_row, file_text);

    /// Откроем файл для записи результата поиска искомой строки:
    string filename2;
    cout << "Enter name of file to write a result: ";  // laba5_3_result.txt
    getline(cin, filename2);
    FILE *fr2 = fopen(filename2.c_str(), "w");
    if (fr2 == NULL) {
        printf("Error while opening file for writing ", filename2.c_str());
    } else {
        fputs(message.c_str(), fr2);                     // записываем строку
        fclose(fr2);
        printf("File has been written\n");
    }

    free(seeking_row);
}

std::string find_row_in_row(char* target, std::string source){
    string message;
    int index = -1;
    int i = 0;
    while(i < source.length()){
        int j = 0;
        while(source[i+j] == target[j]){
            if(target[j] != '\n'){
                j++;
                if(target[j] == '\n'){
                    index = i;
                    message = "Seeking row - " + (string)target + " - was found at position  " + to_string(index);
                    return message;
                }
            }
        }
        ++i;
    }
    if(index==-1) message = "Seeking row was not found.";
    return message;
}
// Дополнить программу первого пункта функцией поиска в текстовом файле заданной строки.
// Искомую строку необходимо передавать в качестве параметра функции.
// Результаты работы сформировать в отдельном файле.

