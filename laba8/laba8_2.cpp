#include "iostream"
#include "fstream"
#include "stdlib.h"
#include "ctype.h"
using namespace std;

enum open_mode{
    in = 0x01,   // ������� ��� ������
    out = 0x02,  // ������� ��� ������
    ate = 0x04,  // ���������� ��������� � ����� �����
    app = 0x08,  // ����� ���������� � ����� �����
    trunc = 0x10,  // �������, ���� �� ��� ����������
    nocreate = 0x20,  // ������� ����, ���� �� �� ����������
    noreplace = 0x40,  // �������, ���� �� ��� �� ����������
    binary = 0x80     // �������� ����

};

int main(void){
/// ��� �������� ������ ������������ ������������ �������:
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

/// ��� �������� ������ ������ ����� ��������������� ������� open ���� �������
/// ��������� ������� open ����� �� �� ��������, ��� � ��������� ������������� ������:
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

/// ������ �������: ����� ������ ���� �������� �� ������������ ������� �����, ������������ ������� ios
/// �������� mode � ������������� � ������� open ������� ����� �������� �� ���������:ios::in ��� ifstream � ios::out ��� ofstream

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
// ��������� ��������� �� ���. 22, 23, 24 �����. �������� "������ �������
// ����� ���������������� �++"