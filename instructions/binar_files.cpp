#include <stdio.h>
#include <iostream>
#include <cstring>
#include <fstream>
#include <wsman.h>
#include <vector>

using namespace std;

int main()
{
/// открываем поток istream для двоичного ввода из файла:
    cout << "Enter the name of the file for reading: \n";
    std::string name;
    cin >> name;
    ifstream ifs(name.c_str(),ios_base::binary); // binary сообщает потоку, чтобы он ничего не делал с байтами

    if (!ifs) printf("Error while opening file %s\n", name.c_str());

/// открываем поток ostream для двоичного вывода в файл:
    cout << "Enter the name of the file for reading for writting: \n";
    cin >> name;
    ofstream ofs(name.c_str(),ios_base::binary); // binary сообщает потоку, чтобы он ничего не делал с байтами

    if (!ofs) printf("Error while opening file %s\n", name.c_str());

    vector<int> v;
// чтение из бинарного файла:
    int i;
//   while (ifs.read(as_bytes(i),sizeof(int))) // читаем байты
        v.push_back(i);

// записываем в двоичный файл:
    for(int i=0; i<v.size(); ++i)
//        ofs.write(as_bytes(v[i]),sizeof(int));

        return 0;
}
//ios_base::app Добавить (т.е. приписать в конце файла)
//ios_base::ate В конец (открыть и перейти в конец файла)
//ios_base::binary Бинарный режим — зависит от специфики системы
//ios_base::in Для чтения
//ios_base::out Для записи
//ios_base::trunc Обрезать файл до нулевой длин
