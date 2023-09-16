#include <list>
#include "iostream"
#include "forward_list"
using namespace std;

int main(){
    std::forward_list<int> list1;                     // ������ ������
    std::forward_list<int> list2(5);                  // list2 ����� 5 ���������, ������ �� ������� ����� �������� �� ���������
    std::forward_list<int> list3(5, 2);               // list3 ������� �� 5 �����, ������ ����� ����� 2
    std::forward_list<int> list4{ 1, 2, 4, 5 };       // list4 ������� �� ����� 1, 2, 4, 5
    std::forward_list<int> list5 = { 1, 2, 3, 4, 5 }; // list5 ������� �� ����� 1, 2, 3, 4, 5
    std::forward_list<int> list6(list4);              // list6 - ����� ������ list4
    std::forward_list<int> list7 = list4;             // list7 - ����� ������ list4
    std::forward_list<int> list8({ 1, 2, 3, 4, 5, 6 }); // list8  ������� �� ����� 1, 2, 3, 4, 5, 6

    ///��������� ��������� - �������� � ������ forward_list ����� �������� ������ ������ �������
    std::forward_list<int> numbers { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    int first {numbers.front()};    // 1
    std::cout << "First: " << first << std::endl;

    for (int n : numbers)
        std::cout << n << "\t";
    cout << std::endl;

    auto current = numbers.begin();
    auto end = numbers.end();
    while (current!=end){
        cout << *current << "\t";
        current++;
    }
    cout << std::endl;

    // before_begin() � cbefore_begin(). ��� ������� ���������� ��������
    // (������ ������� ���������� ����������� �������� const_iterator) ��
    // �������������� ������� ��������������� ����� ������� ������
    auto prev = numbers.before_begin();
    while (++prev != end)
    {
        std::cout << *prev << "\t";
    }
    std::cout << std::endl;
    numbers.resize(4);  // ��������� ������ ������ �������� - numbers = {1, 2, 3, 4}
// resize(n, value): ����� ��������� � ������ n ������ ���������. ���� ������ ������ ������ n, �� ����������� ����������� �������� �� ��������� value
    numbers.resize(6, 8);    // numbers = {1, 2, 3, 4, 8, 8}

    /// ��������� ��������� ������
    // ������� assign() ��������� �������� ��� �������� ������ ������������ �������
    numbers.assign({ 21, 22, 23, 24, 25 }); // numbers = { 21, 22, 23, 24, 25 }

    numbers.assign(4, 3);       // numbers = {3, 3, 3, 3}

    std::list<int> values{ 6, 7, 8, 9, 10, 11 };
    auto start2 = ++values.begin();  // �������� ��������� �� ������ ������� �� values
    auto end2 = values.end();
    numbers.assign(start2, end2); //  numbers = { 7, 8, 9, 10, 11 }

    std::forward_list<int> list_1{ 1, 2, 3, 4, 5 };
    std::forward_list<int> list_2{ 6, 7, 8, 9};
    list_1.swap(list_2);

    /// ���������� ���������
    std::forward_list<int> numbers2{ 7, 8 };
    numbers2.push_front(6);  // ��������� ������ val � ������ ������ - 6
    // numbers =  { 6, 7, 8 }

    numbers2.emplace_front(-3);  // ��������� ������ val � ������ ������ - -3
    // numbers =  { -3, 6, 7, 8 }

    auto iter = numbers2.begin();
    // ��������� ������ val ����� ��������, �� ������� ��������� �������� p.
    // ���������� �������� �� ����������� �������.
    // ���� p ������������ �������� �� ������� ����� ����� ������, �� ��������� �����������.
    iter = numbers2.emplace_after(iter, -2); // ��������� ����� ��������� ����� -2
    // numbers =  { -3, -2, 6, 7, 8 }

    // ��������� ������ val ����� ��������, �� ������� ��������� �������� p.
    // ���������� �������� �� ����������� �������
    iter = numbers2.insert_after(iter, -1);
    // numbers =  { -3, -2, -1, 6, 7, 8 }

    // insert_after(p, n, val): ��������� n �������� val ����� ��������,
    // �� ������� ��������� �������� p. ���������� �������� �� ��������� ����������� �������.
    iter = numbers2.insert_after(iter, 3, 0);    // ��������� ��� ����
    // numbers =  { -3, -2, -1, 0, 0, 0, 6, 7, 8 }

    // insert_after(p, begin, end): ��������� ����� ��������, �� ������� ��������� �������� p,
    // ����� �������� �� ������� ����������, ������ � ����� �������� ������������ ����������� begin � end.
    // ���������� �������� �� ��������� ����������� �������.
    std::list<int> values2{ 1, 2, 3 };
    iter = numbers2.insert_after(iter, values2.begin(), values.end()); // ��������� ��� �������� �� values
    // numbers =  { -3, -2, -1, 0, 0, 0, 1, 2, 3, 6, 7, 8 }

    // insert_after(p, il): ��������� ����� ��������, �� ������� ��������� �������� p,
    // ������ ������������� il. ���������� �������� �� ��������� ����������� �������.
    numbers2.insert_after(iter, { 4, 5 }); // ��������� ������ { 4, 5 }
    // numbers =  { -3, -2, -1, 0, 0, 0, 1, 2, 3, 4, 5, 6, 7, 8 }

    for(int n : numbers2)
        std::cout << n << "\t";
    std::cout << std::endl;

    /// �������� ���������
    std::forward_list<int> numbers3{ 1, 2, 3, 4, 5, 6, 7};

    numbers3.pop_front();  // ������� ������ �������
// numbers = { 2, 3, 4, 5, 6, 7};

    //  ������� ������� ����� ��������, �� ������� ��������� �������� p.
    //  ���������� �������� �� ������� ����� ����������
    auto iter2 = numbers3.erase_after(numbers3.begin());
// numbers = { 2, 4, 5, 6, 7 };
// iter ��������� �� ������� 4

    // ������� �������� ���������, �� ������ � ����� �������� ���������
    // �������������� ��������� begin � end.
    // ���������� �������� �� ������� ����� ���������� ����������
    numbers3.erase_after(iter2, numbers3.end());
// numbers = { 2, 4 };

    return 0;
}
