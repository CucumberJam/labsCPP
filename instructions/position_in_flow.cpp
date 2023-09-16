#include <stdio.h>

void load(char *, int);
void save(char *);

int main(void)
{
    // файл для записи и чтения
    char * filename = "data.txt";
    // позиция, с которой начинается считывание
    int position = 6;
    save(filename);
    load(filename, position);

    return 0;
}
void load(char * filename, int position)
{
    // буфер для считавания данных из файла
    char buffer[256];
    // чтение из файла
    FILE *fp = fopen(filename, "r");
    if(!fp)
    {
        printf("Error occured while opening file\n");
        return;
    }
    // перемещаем указатель в файле на позицию position
    fseek(fp, position, SEEK_SET);
    // пока не дойдем до конца, считываем по 256 байт
    while((fgets(buffer, 256, fp)))
    {
        printf("%s", buffer);
    }

    fclose(fp);
}
void save(char * filename)
{
    // строка для записи
    char * message = "Hello METANIT.COM!";
    // запись в файл
    FILE *fp = fopen(filename, "w");
    if(!fp)
    {
        printf("Error occured while opening file\n");
        return;
    }
    // записываем строку
    fputs(message, fp);

    fclose(fp);
    printf("File has been written\n");
}
