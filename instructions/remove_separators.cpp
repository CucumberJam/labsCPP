#include "stdio.h"
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;
int main(void){

    string line;
    cout << "Enter the name of the file for reading: \n";
    getline(cin,line); // вводим строку line
    for (int i=0; i<line.size(); ++i){  //заменяем знаки пунктуации пробелами
        switch(line[i]) {
            case ';': case '.': case ',': case '?': case '!':
                line[i] = ' ';
        }
    }
    stringstream ss(line);  // создаем поток istream ss, вводя в него строку line
    vector<string> vs;
    string word;
    while (ss>>word) // считываем слова без знаков пунктуации
        vs.push_back(word);

}
