#include <stdio.h>
#include <iostream>
#include <cstring>
#include <fstream>
#include <wsman.h>
#include <vector>
#include <sstream>

using namespace std;

int main(){

    string name;
    getline(cin,name); // ввод: Dennis Ritchie
    cout << name << '\n';


    string first_name;
    string second_name;
    stringstream ss(name);
    ss>>first_name; // ввод строки Dennis
    ss>>second_name; // ввод строки Ritchie


    string command;
    getline(cin,command); // вводим строку
    stringstream st(command);
    vector<string> words;
    string s;
    while (st>>s) words.push_back(s); // извлекаем отдельные слова

    return 0;
}
