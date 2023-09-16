#include <stdio.h>

int main(void){
    char * filename = "C:\\Users\\tutorial\\test2.txt"; // файл чтения

    char buffer[256];       // буфер для считывания данных из файла

    FILE *fp = fopen(filename, "r");  // чтение из файла

    if(fp){
        // пока не дойдем до конца, считываем по 256 байт
        while ((fgets(buffer,256,fp)) != NULL){
            printf("%s", buffer);
        }
        fclose(fp);
    }
}