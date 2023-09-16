#include <stdio.h>
void main(void ){
/// записываемая строка
    char message[] = "Hello and fuck off!";

/// файл для записи
    char * filename = "data.txt";

/// находим длину записываемой строки
    int n = sizeof (message)/sizeof (message[0]);

/// открывается  поток (имя открываемого файла, режим открытия)
/// "w": - текстовый файл открывается для записи.
/// Если файл ранее существовал, то он пересоздается и записывается заново:
    FILE * fp = fopen(filename, "w");

/// Если поток открыт, то посимвольно записываем в файл:
    if(fp){
        for(int i = 0; i<n;i++){
            putc(message[i], fp);
        }
        fclose(fp);
        printf("File has been written\n");
    }

}
