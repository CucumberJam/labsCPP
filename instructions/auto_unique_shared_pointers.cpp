#include "string"
#include "iostream"
#include "memory"
/* auto_ptr - ������� � ����� �� unique
 * unique_ptr - �� ���� ��������� �� ����, �� ���� ���� �� ���� ������, ������ ������
 * shared_ptr - ����� �������� ����������� ����������� ����� � ��� �� �������� �����. ������ ��� ����� ��� �����������
 */
using namespace std;

template<class T>
class SmartPointer{
public:
    SmartPointer(T *ptr){
        this->ptr = ptr;
        cout<< "Constructor" << endl;
    }
    ~SmartPointer(){
        delete ptr;
        cout<< "Destructor" << endl;
    }
    T& operator*(){
        return *ptr;
    }
private:
    T *ptr;
};

int main(){
    auto_ptr<int> ap1(new int(5));
    auto_ptr<int> ap2(ap1);
// auto_ptr1 - �������� ��������� ������ ��� �������� �������, ����� �����7

    unique_ptr<int> up1(new int(5));
// unique_ptr - �� ���� ��������� �� ���� ���� ���� - �� ��������
    unique_ptr<int> up2;
    up2 = move(up1); // ������ ������ ���� ��������� ������, � �� ������ 5
    up1.swap(up2); // ������ ��� ����� �������� �������

    int *up3 = up1.get(); // ������ ������ ���������

    int *p = new int(5);
    unique_ptr<int> up4(p);
    up4.reset(); // �������� ������ �� ������� ��������� ���� ���������

    int *p2 = new int(15);
    unique_ptr<int> up5(p2);
    up5.release(); // ������ �� ������� ��������� ���� ��������� ��������?, �� ��������� ����

    shared_ptr<int> sp1(new int(10));
    shared_ptr<int> sp2(sp1); // ���������� ���������� ������ �� ������ ���������


    return 0;
}
