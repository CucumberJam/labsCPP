#include <stdio.h>
#include <iostream>
#define MAX 15

int main(void)
{
    /// Ввод и вывод символов
    char c = 'A';
    putchar(c);     // Выводим символ A
    std::cout << "\n";
/// Демонстр-ый пример как в буфер считывается введенный символ и Enter:
//    printf("1");
//    getchar(); // ожидание ввода символа
//    printf("2");
//    getchar(); // ожидание ввода символа
//    printf("3");

    ///  Для вывода из программы необходимо ввести комбинацию клавиш Ctrl+C.
//    int p;

//    while((p=getchar())!=EOF)  // Функция getchar() считывает числовой код символа,
//    {
//        putchar(p);         //который потом выводится в функции putchar()
//    }

    /// Вывод строк
    puts("Row literal in function puts()");        // выводим строковый литерал

    char* name = "Pointer to the row in function puts()";
    puts(name);                 // выводим значение переменной

    fputs("Function recording on console by fputs()\n", stdout);

    /// Ввод строк:
    char name2[MAX];
    printf("Enter name: ");
    if( fgets(name2, MAX, stdin) != NULL) //  считывание строки с консоли.
    { // if(fgets(name, MAX, stdin)) - можно сократить
        printf("Your name: %s\n", name2);
    } else{
        printf("Critical Error!");
    }
    return 0;
}
