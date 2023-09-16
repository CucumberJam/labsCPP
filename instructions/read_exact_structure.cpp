#include <stdio.h>
#include <stdlib.h>

struct person{
    char name[20];
    int age;
};

int save(char * filename, struct person *st, int n);
int load(char * filename);

int main(void)
{
    char * filename = "people.dat";
    struct person people[] = { {"Tom", 23}, {"Alice", 27}, {"Bob", 31}, {"Kate", 29} };
    int n = sizeof(people) / sizeof(people[0]);

    save(filename, people, n);
    load(filename);

    return 0;
}

// запись в файл массива структур
int save(char * filename, struct person * st, int n)
{
    char *c;    // указатель для посимвольной записи данных
    // число записываемых байтов
    int size = n * sizeof(struct person);

    FILE * fp = fopen(filename, "wb");
    if (!fp)
    {
        printf("Error occured while opening file\n");
        return 1;
    }
    // записываем количество структур
    c = (char *)&n;
    for (int i = 0; i < sizeof(n); i++)
    {
        putc(*c++, fp);
    }

    // посимвольно записываем в файл все структуры
    c = (char *)st;
    for (int i = 0; i < size; i++)
    {
        putc(*c, fp);
        c++;
    }
    fclose(fp);
    return 0;
}

// загрузка из файла массива структур
int load(char * filename)
{
    char *c;    // указатель на считывания очередного символа
    int n = sizeof(struct person);  // сколько байт надо считать для структуры
    int index;  // номер структуры из файла:
    printf("Enter user number: ");  // ввод номера структуры
    scanf("%d", &index);

    FILE * fp = fopen(filename, "rb"); // открываем файл на чтение
    if (!fp)
    {
        printf("Error occured while opening file\n");
        return 1;
    }

    // выделяем память для количества структур
    int *ptr_count = (int*)malloc(sizeof(int));
    // считываем количество структур
    c = (char *)ptr_count;
    int m = sizeof(int);    // сколько надо считать структур
    // пока не считаем m байт
    while (m > 0 && (*c = getc(fp))!=EOF)  // сохраняем байт в выделенный блок для размера массива
    {
        c++;
        m--;
    }
    //получаем число элементов
    int count = *ptr_count;
    free(ptr_count);    // освобождаем память
    // если номер запрощенной структуры меньше кол-ва структур
    if(index > count)
    {
        printf("User number out of range\n");
        fclose(fp);
        return 1;
    }

    // получаем, на сколько байтов надо перемотать указатель относительно начала позиции
    int pos = (index-1) * n + 4;
    // перемещаем указатель на нужную позицию
    fseek(fp, pos, SEEK_SET);

    // выделяем память для считываемой структуры
    struct person * ptr = (person*)malloc(sizeof(struct person));

    // устанавливаем указатель на начало блока памяти
    c = (char *)ptr;
    // после записи считываем посимвольно из файла
    while(n > 0 && (*c=getc(fp))!=EOF)
    {
        c++;
        n--;
    }
    // вывод считанных данных на консоль
    printf("%-10s %5d \n", ptr->name, ptr->age);
    free(ptr);
    fclose(fp);
    return 0;
}
