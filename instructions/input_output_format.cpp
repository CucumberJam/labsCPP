#include <stdio.h>

int main(void)
{
    char buff[50] = "F 69 123.45";
    char c;
    int n;
    double d;
    sscanf(buff, "%c %d %lf", &c, &n, &d);
    printf("Values: %c, %d, %lf\n", c, n, d);

// Если бы в строке данные были бы разделены запятыми,
// то спецификаторы в формате считывания также были бы разделены запятыми:

    char buff2[50] = "F, 69, 123.45";
    char c2;
    int n2;
    double d2;
    sscanf(buff2, "%c, %d, %lf", &c2, &n2, &d2);
    printf("Values: %c, %d, %.2lf\n", c2, n2, d2);

// Пусть в строке содержатся данные пользователя, как имя, возраст, зарплата.
    char buff3[50] = "Tom 23 505.99";
    char name[10];
    int age;
    double salary;
    sscanf(buff3, "%s %d %lf", name, &age, &salary);
    printf("Name: %s \tAge: %d \tSalary: %.2lf\n", name, age, salary);

// Причем строка форматирования может быть более сложной.
    char *buff4 = "Name is Xyi and age is 38";
    char name2[10];
    int age2;

    sscanf(buff4, "Name is %s and age is %d", name2, &age2);

    printf("Name: %s \tAge: %d\n", name2, age2);


    // Считывание с консоли
    char buff5[50];
    char name3[10];
    int age3;
    double salary2;
    printf("Enter name age and salary:\n");
    if(!fgets(buff5, 50, stdin))
    {
        printf("Fatal Error!\n");
        return 1;
    }
    sscanf(buff5, "%s %d %lf", name3, &age3, &salary2);
    printf("Name: %s \tAge: %d \tSalary: %.2lf\n", name3, age3, salary2);

// Результатом функции sprintf() является длина количество записанный символов плюс нулевой символ.
    int age4 = 38;
    char* name4 = "Tom";
    char text[50];
    int charNumber = sprintf (text, "Name: %s  Age: %d\n", name4, age4);
    printf (text);  // Name: Tom  Age: 38
    printf("text length: %d", charNumber);  // text length: 19

    return 0;
}
