/// ���������� ������ �� ���������� STL - ������������ �������� ������, ������� �����
/// ������ ������� � ��������� ������� � ����� ����� ���������� (�������� ���������� �������)
/// � ����� ������ ���������� ����� ���������� ������, ������ ����� ���������
/// ����������� ���������� ����� � �������� ��� (������ ��������������� ����� ������ �������)
#include "iostream"
#include "list"
using namespace std;

template <typename T>
void printList(const list<T> &list){
    for(auto i = list.begin(); i != list.end(); ++i){
        cout << *i << endl;
    }

}
int main(){
    std::list<int> list1;             // ������ ������
    std::list<int> list2(5);          // ������ list2 ������� �� 5 �����, ������ ������� ����� �������� �� ���������
    std::list<int> list3(5, 2);           // ������ list3 ������� �� 5 �����, ������ ����� ����� 2
    std::list<int> list4{ 1, 2, 4, 5 };   // ������ list4 ������� �� ����� 1, 2, 4, 5
    std::list<int> list5 = { 1, 2, 3, 5 }; // ������ list5 ������� �� ����� 1, 2, 4, 5
    list4.swap(list5);
    std::list<int> list6(list4);          // ������ list6 - ����� ������ list4
    std::list<int> list7 = list4;         // ������ list7 - ����� ������ list4


    list<int> myList = {15,64,979};
    myList.push_back(1);
    myList.push_front(99);
    cout <<"Size of list: " << myList.size() << endl;
    list<int>::iterator it = myList.begin();

    printList(myList);

    myList.sort();
    printList(myList);

    myList.pop_back();
    printList(myList);
    myList.pop_front();
    printList(myList);
    cout <<"Size of list: " << myList.size() << endl;

    myList.unique(); // ������� ����� ����� ������� ���� ���������������
    myList.reverse(); // ������ �������� � �������� �������
    myList.clear();   // ������� ��� ��������

    ++it;  // �� �������� ������������ ����������� �������� ���������
    advance(it, 1); // �������� ��������  �� ������������ ����������
    myList.insert(it, 45);

    myList.remove(15); // ������� ���������� ������� (�������� ���� ��� �����  ������)
    myList.assign(3, 44);  // ��������� ���� ������ �� ����������, ������ ���������� (3) �� �������
    auto begin = ++it;
    auto end = ++it;
    myList.assign(begin, end); // �������� ���������� ���������� ���������� �� ���������, �� ������ � ����� �������� ��������� ��������� begin � end


    printList(myList);
/// assign ������������ ��� ���� ����� ����������� �������� ������ ����� � ������ ����
    list<int> myList2 = {150,160,170};
    list<int> myList3 = {250,260,270};
    list<int> myList4;
    myList4.assign(myList2.begin(), myList2.end()); // ����������� �������� � �������� 2 ����� � 4
    printList(myList4);





    return 0;
}
