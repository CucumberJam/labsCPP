#include "iostream"
#include "fstream"
#include "stdlib.h"
#include "ctype.h"
using namespace std;

class _EXPCLASSios{
public:
    enum io_state{
        goodbit = 0x00,  // ��� � �������
        eofbit = 0x01,  // ��������� ����� �����
        failbit = 0x02,  // ������ �������������� ��� �������������� (�������. ������)
        badbit= 0x04,    // ��������� ������ � ��������� ���������� (����� �� ��������� �����)
        hardbit = 0x08,  // ������������ ������ � �������������� ������������
    };
};
/// ����� � ��������� ��������� ������ (������ ������):
// int rdstate();  - ���������� ������� ���������
// int eof();  - ���������� ��������� ��������, ���� ���������� ���� ios::eofbit
// int fail(); - ���������� ��������� ��������, ���� ���������� ���� �� ������ ios::badbit ios::hardfail
// int bad(); - ���������� ��������� ��������, ���� ���������� ���� �� ������ ios::badbit ios::hardfail
// int good(); - ���������� ��������� ��������, ���� �������� ��� ���� ������
// void clear(int=0); - ���� �������� = 0, �� ��� ���� ���������, ����� �������� ����������� � �������� ��������� ������
// operator void*(); - ���������� ������� ���������, ���� ���������� ���� �� ����� ios::failbit, ios::badbit, ios::hardbit
// int operatorl(); - ���������� ��������� ��������, ���� ���������� ���� �� ����� ios::failbit, ios::badbit, ios::hardbit

// while(streamMy){
//     ����� � �������, ����� ��������� �������� �����/������
// }

/// �������� ��� ��������� ������ (�������� � �������):
// if(strm.rdstate() &ios::flag) - ���������, ���������� �� ����
// strm.clear(rdstate() & �ios::flag) - �������� ����
// strm.clear(rdstate() | ios::flag) - ���������� ����
// strm.clear(ios::flag) - ���������� ���� (���������� ��� ������ �����)
// strm.clear() - �������� ��� �����

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
