#include "iostream"
#include "string"

using namespace std;

/// �� ��������� ���� � ������ ���������
/// �� ��������� ��� ������������ ��� ���� ������������ ��� ����������
class Myclass{
public:
    int a = 10;
    void print(){
        cout << a << endl;
    }
};
class Myclass2: public Myclass{  // ���� ���� �� ������� ���� �� ��� ���� ����� ���������� � �� ����������

};
/// �� ��������� ���� � ��������� ���������
/// �� ��������� ��� ������������ ��� ���� ������������ ��� ���������
struct Mystruct{
    Mystruct(){
        a = 22;
    }
    ~Mystruct(){};
    int a = 22;
    void print(){
        cout << a << endl;
    }
};
struct Mystruct2: Mystruct{

};

int main(){
    Myclass m;
    Mystruct ms;

    ms.print();
    ms.a = 10;
    ms.print();

    m.print();

    Myclass2 m2;
    m2.print();

    Mystruct2 ms2;
    ms2.print();

    return 0;
}