#include "stdio.h"

void main(void){

/// символ для считывания:
    char c;

/// файл для чтения:
    char * filename = "data.txt";

    FILE * fp = fopen(filename, "r");

/// считываем посимвольно из файла через вызов getc()
/// Когда будет достигнут конец файла, функция getc() возвратит значение EOF^
    if(fp){
        while ((c=getc(fp)) != EOF){
            printf("%c", c);
        }
        fclose(fp);
    }


}
//     std::string filename;
//    std::cout<<"Enter filename\n";
//    std::getline(std::cin, filename);
//    std::ifstream ifs(filename.c_str());