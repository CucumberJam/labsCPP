#include "stdio.h"
#include <iostream>
using namespace std;
int main(void){
    unsigned count{}; // счетчик слов

    char ch;
    string filename;
    cout << "Enter name of file to read: ";  // C:\\Users\\tutorial\\test2.txt
    getline(cin, filename);

    FILE *in = fopen(filename.c_str(), "r");

    if(in == NULL){
        printf("Error while opening file ", filename.c_str());
    } else{
        while ((ch=getc(in)) != EOF){
            if(!isalnum(ch)){   // проверяет, является ли c алфавитно-цифровым символом; аналогично isisalpha(c) || isdigit(c)
                count++;
            }
            printf("%c", ch);
        }
        cout << endl;
        printf("Amount of empty or others symbols is  %d.", count);
        fclose(in);
    }
}
// Дополнить программу предыдущего пункта функцией подсчета "пустых" и "непустых" символов в
// текстовом файле. Под "пустыми" символами понимаются символы, не отображающиеся на экране:
// управляющие символы, пробел, звуковой сигнал и т.д.
