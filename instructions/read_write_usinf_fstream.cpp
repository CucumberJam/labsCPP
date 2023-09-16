#include <iostream>
#include <string>
#include <fstream>
#include <windows.h>

using namespace std;

int main(){
    setlocale(LC_ALL, "ru");

    string path = "fstreamFileTest.txt";

    fstream fs; // ����������� ����� (�� ������ � ������
    fs.open(path, fstream::in | fstream::out | fstream::app); // ����� ������ / ������ /��������
    if(!fs.is_open()){
        cout << "Error while opening!" << endl;
    }else{
        int value;
        string msg;
        do {
            cout << "File was opened!" << endl;
            cout << "Enter 1 for recording message to the file or 2 for reading all messages from file: " << endl;
            cin >> value;
        } while (value <1 || value > 2);

        if(value==1){
            cout << "Enter a message: " << endl;
            SetConsoleCP(1251);
            cin >> msg;
            fs << msg << "\n";   // �������� ��������� � ���� ����� �������
            SetConsoleCP(866);
        }
        if(value==2){
            cout << "Reading text file:" << endl;
            while ((!fs.eof())){
                msg="";  // �������� ���������� ����� �� ������������� ��������� �����
                fs >>  msg;
                cout << msg << endl;
            }
        }

    }




    fs.close();
    return 0;
}