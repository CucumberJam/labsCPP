#include "iostream"
#include "fstream"
#include "stdlib.h"
#include "ctype.h"
using namespace std;

class _EXPCLASSios{
public:
    enum io_state{
        goodbit = 0x00,  // все в порядке
        eofbit = 0x01,  // достугнут конец файла
        failbit = 0x02,  // ошибка форматирования или преобразования (несоотв. формат)
        badbit= 0x04,    // серьезная ошибка с буферными операциями (поиск за пределами файла)
        hardbit = 0x08,  // неисправимая ошибка с неисправностью оборудования
    };
};
/// Опрос и установка состояния потока (методы опроса):
// int rdstate();  - возвращает текущее состояние
// int eof();  - возвращает ненулевое значение, если установлен флаг ios::eofbit
// int fail(); - возвращает ненулевое значение, если установлен один из флагов ios::badbit ios::hardfail
// int bad(); - возвращает ненулевое значение, если установлен один из флагов ios::badbit ios::hardfail
// int good(); - возвращает ненулевое значение, если сброшены все биты ошибок
// void clear(int=0); - если параметр = 0, то все биты очищаются, иначе параметр принимается в качестве состояния ошибки
// operator void*(); - возвращает нулевый указатель, если установлен один из битов ios::failbit, ios::badbit, ios::hardbit
// int operatorl(); - возвращает ненулевое значение, если установлен один из битов ios::failbit, ios::badbit, ios::hardbit

// while(streamMy){
//     Поток в порядке, можно выполнять операции ввода/вывода
// }

/// Действия над состояние потока (операции с флагами):
// if(strm.rdstate() &ios::flag) - проверить, установлен ли флаг
// strm.clear(rdstate() & ¬ios::flag) - сбросить флаг
// strm.clear(rdstate() | ios::flag) - установить флаг
// strm.clear(ios::flag) - установить флаг (сбрасывает все другие флаги)
// strm.clear() - сбросить все флаги

int main(void){
    string filenameSource;
    cout << "Enter name of file for reading: \n";   // laba8_4_read.txt
    getline(cin,filenameSource);
    ifstream fr(filenameSource, ios_base::in);
    //FILE * fr = fopen(filenameSource.c_str(), "r");

    string filenameTarget;
    cout << "Enter name of file for writing: \n";  // laba8_4_write.txt
    getline(cin,filenameTarget);
    FILE * fw = fopen(filenameTarget.c_str(), "w");


    char ch;
    if(fr.good()){
        ios_base::iostate old_state = cin.rdstate();
        while ((ch=fr.get()) != EOF){
            if(isdigit(ch)){                           //isalnum(ch);
                fr.setstate(ios_base::failbit | ios_base::badbit);
                ios_base::iostate new_state = cin.rdstate();
            }else{
                fputc(ch, fw);
                printf("%c", ch);
            }
            cin.clear( old_state );
        }
        if(fr.rdstate() &ios::goodbit) cout << "Stream good.\n";
        fclose(fw);
    }
    return 0;
}
