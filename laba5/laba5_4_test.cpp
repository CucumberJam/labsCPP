#include <stdio.h>
#include "string.h"
#include <regex>

int nextLine(char * text, int index);

int main()
{
    char ch, name[50];

    FILE *in;
    printf("������� ��� ����� ��� ���������: ");
    scanf("%s", name);

    if((in= fopen(name, "w"))==NULL) {
        printf("���� %s �� ������!", name);
        return 0;
    }

    char text[] = "-123-\nHello world!\nNewString\f-223-\nNew list\nNewString\f-323-\nEnd list";
    fwrite(text, strlen(text), 1, in);
    fflush(in);
    fclose(in);

    if((in= fopen(name, "r"))==NULL) {
        printf("���� %s �� ������!", name);
        return 0;
    }

    long length = ftell(in);
    rewind(in);

    char * buff = new char[length];

    long i = 0;
    while(!feof(in)) {
        buff[i++]=getc(in);
    }
    printf("\n�� ��������������: \n%s", buff);

    int number = 0;

    char numStr[10];
    int j = 0;
    int result;
    while((result = sscanf(&buff[j], "-%d-\n%*[a-zA-Z !?.,\n\t]", &number)) != EOF)
    {
        if(0 == result) {
            j = nextLine(buff, j);
            continue;
        }

        sprintf(numStr, "-%d-\n", number);
        size_t len = strlen(numStr);
        char * zero = &buff[j], start;
        while((start=zero[len]) != '\f' && start != '\0')
        {
            *zero = zero[len];
            zero++;
        }
        int index = 0;
        for(; index < len; index++) {
            zero[index] = ' ';
        }
        *zero = '\n';

        index = 0;
        sprintf(numStr, "%d", number);
        while(numStr[index] != '\0')
        {
            *(++zero) = numStr[index++];
        }
        *(++zero) = '\n';
        j = nextLine(buff, j);
    }

    printf("\n\n����� ��������������: \n%s", buff);

    return 0;
}

int nextLine(char * text, int index)
{
    while(true) {
        if(text[index] == '\0') {
            return index;
        }

        if(text[index] == '\f') {
            return ++index;
        }
        index++;
    }
}