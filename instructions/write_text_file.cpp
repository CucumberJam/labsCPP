#include <stdio.h>

int main(void){
    char * message = "An apple a day keeps the doctor away"; // строка для записи
    char * filename = "data.txt";                           // файл для записи
    FILE *fp = fopen(filename, "w");            // запись в файл
    if(fp)
    {
        fputs(message, fp);                     // записываем строку
        fclose(fp);
        printf("File has been written\n");
    }



}
