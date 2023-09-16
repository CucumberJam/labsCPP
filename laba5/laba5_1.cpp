#include "stdio.h"
#include <fstream>		//для работы с файлами
#include <iostream>

using namespace std;
int main(void){
    char ch;
    string filename;
    cout << "Enter name of file to read: ";
    getline(cin, filename); // C:\\Users\\tutorial\\test2.txt

    FILE *in = fopen(filename.c_str(), "r");

    if(in == NULL){
        printf("Error while opening file %s", filename.c_str());
    } else{
        while ((ch=getc(in)) != EOF){
            printf("%c", ch);
        }
        fclose(in);
    }
}
// Разработать пррограмму, выводящую содержимое текстового файла на экран.
// Как можно сократить текст программы?