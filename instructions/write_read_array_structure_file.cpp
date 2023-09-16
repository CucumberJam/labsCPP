#include "stdio.h"
#include "stdlib.h"

struct person{
    char name[16];
    int age;
};

int save(char * filename, struct person *st, int n);
int load(char * filenaqme);

void main(void) {
    char * filename = "people.dat";
    struct person people[] = { {"Tom", 23}, {"Alice", 27}, {"Bob", 31}, {"Kate", 29 }};
    int n = sizeof(people) / sizeof(people[0]);

    save(filename, people, n);
    load(filename);
    return 0;

}
/// запись структуры в файл:
int save(char * filename, struct person * st, int n){
    char *c;                            // для записи отдельных символов
    int size = n * sizeof (struct person); // количество записываемых байтов

    FILE *fp= fopen(filename,"wb"); //открываем файл для бинарной записи
    if(!fp){                                // если не удалось открыть файл
        printf("Error occured while opening file \n");
        return 1;
    }

/// записываем количество структур (присваиваем указатели на каждый элемент массива (структуру):
    c = (char*)&n;
    for(int i = 0; i<sizeof(n); i++){
        putc(*c++, fp);          // с шагает (арифм операция) с указателям поэтому n приводили к типу char
    }

/// устанавливаем указатель на начало структуры (на первый байт массива структур):
    c = (char*)st;

/// посимвольно записываем в файл все структуры:
    for(int i = 0; i < size; i++){                  // записываем size байт в файл:
        putc(*c, fp);
        c++;
    }
    fclose(fp);
    return 0;
}

/// загрузка из файла массива структуры (когда не знаешь количество структур):
int load(char * filenaqme){
    char *c;                                  // для считывания отдельных символов
    int m = sizeof(int);                      // сколько надо считать для получения размера массива
    int n;                                    // количество структур в массиве

    FILE * fp = fopen(filenaqme, "r");  // открываем файл для бинарного чтения
    if(!fp){                                    // если не удалось открыть файл
        printf("Error occured while opening file \n");
        return 1;
    }
/// выделяем память для хранения количества данных (количества элементов):
    int * ptr_count = (int*)malloc(m);

/// устанавливаем указатель на количество структур:
    c = (char *)ptr_count;
/// пока не считаем m байт, сохраняем байт в выделенный блок для размера массива:
    while(m > 0 && (*c = getc(fp)) != EOF ){
        c++;
        m--;
    }
///получаем число элементов:
    n = *ptr_count;
    free(ptr_count);    // освобождаем память

/// выделяем память для считанного массива структур:
    struct person * ptr = (person*)malloc(n * sizeof(struct person));

/// устанавливаем указатель на начало блока выделенной памяти:
    c = (char*)ptr;
/// считываем посимвольно из файла:
    while ((*c = getc(fp))!=EOF)
    {
        c++;
    }

/// перебор загруженных элементов и вывод на консоль:
    printf("\nFound %d people\n\n", n);

    for (int i = 0; i < n; i++)
    {
        printf("%-5d %-10s %5d \n", i + 1, (ptr + i)->name, (ptr + i)->age);
        // или так
        // printf("%-5d %-10s %5d \n", i + 1, ptr[i].name, ptr[i].age);
    }

    free(ptr);
    fclose(fp);

    return 0;
}