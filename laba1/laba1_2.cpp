#include <iostream>
#define PR(x) printf("x=%u, *x=%d, &x=%u\n", x, *x, &x)
#include <stdio.h>

int main() {
// int type of pointer:
    int masInt[] = {100, 200, 300};
    int *int1, *int2;
    int1 = masInt;
    int2 = &masInt[2];
    std::cout << "x = adress of pointer\n"
                 "*x = value of variable, \n"
                 "&x = adress of reference"
                 <<std::endl;
    std::cout <<std::endl;
    std::cout << "pointer1 to first element of massive : " <<std::endl;
    PR(int1);
    int1++;
    std::cout << "pointer1 to first element of massive "
                 "after increment : " << std::endl;
    PR(int1);
    std::cout << "pointer2 to last element of massive : " << std::endl;
    PR(int2);
    ++int2;
    std::cout << "pointer2 to third element of massive "
                 "after increment : " <<std::endl;
    PR(int2);
    std::cout <<"Difference of two pointers - the difference \n"
                "of their values by the size of the type "
                "in bytes:"<<std::endl;
    printf("pointer2-pointer1 of int type =%u\n", int2-int1);

// pointer modified with constant:

    std::cout <<std::endl;
    const int CI = 1;
    int * constCi = const_cast<int *>(&CI);  // указатель а целую константу
    std::cout << "pointer to  constant variable: " << std::endl;
    PR(constCi);
    std::cout << "Constant variable: " << CI <<std::endl;
    std::cout << "Pointer to a specific type is incremented\n"
                 "by a constant, its value is changed by the value of that\n"
                 "constant multiplied by the size of an object of that type: " << std::endl;
    constCi += CI;
    PR(constCi);

// short type of pointer:

    std::cout <<std::endl;
    short masShort []= {1, 2, 3, 4};
    short * short1 = masShort;
    std::cout << "pointer to  first element of massive of short type: " << std::endl;
    PR(short1);
    short1--;
    std::cout << "pointer to  first element of massive of short type"
                 "after decrement: " << std::endl;
    PR(short1);
    short * short2 = &masShort[3];
    std::cout << "pointer to  fourth element of massive of short type: " << std::endl;
    PR(short2);
    std::cout <<"Difference of two pointers - the difference \n"
                "of their values by the size of the type "
                "in bytes:"<<std::endl;
    printf("pointer2-pointer1 of short type =%u\n", short2-short1);

//  double type of pointer:

    std::cout <<std::endl;
    double masDouble[] = {1.06, -2.99, 3.6, 4.13, 5.66};
    double * double1 = masDouble;
    std::cout << "pointer to  first element of massive of double type: " << std::endl;
    PR(double1);
    --double1;
    std::cout << "pointer to  first element of massive of double type "
                "after decrement: " << std::endl;
    PR(double1);
    double * double2 = &masDouble[4];
    std::cout << "pointer to  fifth element of massive of double type: " << std::endl;
    PR(double2);
    std::cout <<"Difference of two pointers - the difference \n"
                "of their values by the size of the type "
                "in bytes:"<<std::endl;
    printf("pointer2-pointer1 of double type = %u\n", double2-double1);

    std::cout <<std::endl;
    std::cout << "Summation of two pointers is NOT allowed !!!" << std::endl;



    delete int1;
    delete int2;
    delete constCi;
    delete short1;
    delete short2;
    delete double1;
    delete double2;
    return 0;
}
/* Выполнить программу, иллюстрирующую разные операции с указателями.
 * Повторить эксперимент для разных типов данных.*/