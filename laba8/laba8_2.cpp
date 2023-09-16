#include "iostream"
#include "fstream"
#include "stdlib.h"
#include "ctype.h"
using namespace std;

enum open_mode{
    in = 0x01,   // Открыть для чтения
    out = 0x02,  // Открыть для записи
    ate = 0x04,  // Установить указатель в конец файла
    app = 0x08,  // Режим добавления в конец файла
    trunc = 0x10,  // Урезать, если он уже существует
    nocreate = 0x20,  // Открыть файл, если он не существует
    noreplace = 0x40,  // Открыть, если он уже не существует
    binary = 0x80     // Двоичный файл

};

int main(void){
/// Для открытия файлов используются конструкторы классов:
    char fname[25], c;

    cout << "Enter the name of input file: "; // laba8_1_input.txt
    cin >> fname;

    ifstream ifs(fname);
    if(!ifs){
        cout << "Error while opening input file!" << endl;
    }
    cout << "Enter the name of output file: " << endl; // laba8_1_output.txt
    cin >> fname;

    ofstream  ofs(fname);
    if(!ofs){
        cout << "Error while opening output file " << fname <<  endl;
    }
    while (ifs && ofs){
        ifs.get(c);
        c = toupper(c);
        ofs.put(c);
    }

    cout << endl << "Output file is a copy of input file in upper register.";

    ifs.close();
    ofs.close();

/// Для открытия файлов моджно также воспользоваться методом open этих классов
/// Аргументы функции open имеют то же значение, что и параметры конструкторов потока:
    char name[12];
    fstream fin;
    cout << "Enter the name of  file: " << endl; // laba8_1_input.txt
    cin >> name;
    fin.open(name, ios::in);
    if(fin){
        cout << "File " << name << " is opened." << endl;
        fin.close();
    } else{
        cout << "File " << name << " failed to be opened.";
    }
    fin.close();

/// Режимы доступа: можно задать этот параметр из пересичлений битовых масок, определяемых классом ios
/// Параметр mode в конструкторах и методах open классов имеет значения по умолчанию:ios::in для ifstream и ios::out для ofstream

    const char fileName[] = "laba8_2_modes";
    ofstream ofstream(fileName, ios::out); // ios::noreplace
    if(!ofstream){
        cout << "Error situation! File " << fileName << " already exists." << endl;
    }
    else{
        ofstream << "This row is beeng recorded in new file";
        ofstream.close();
        fstream fs;
        fs.open(fileName, ios::out); // ios::ate
        fs << "Now has been added smth";
        fs.close();
        fstream ifstr(fileName);
        if(ifstr){
            cout << "Previous file contains: " << "..." << endl;
            char line[80];
            ifstr.getline(line, sizeof line);
            cout << line;
        } else{
            cout << "Error situation while reopening file " << fileName << endl;
        }
        ifstr.close();
    }

}
// Выполнить программы на стр. 22, 23, 24 метод. указаний "Классы потоков
// языка программирования С++"