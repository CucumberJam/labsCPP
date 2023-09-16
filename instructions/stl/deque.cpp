/// ������������ ������������ ������ � ��������� ����������, �� � ������� �� ������� �����
/// ������������ ���������� � ������ ����������. ����� ����, �� ���������� ���������� deque
/// ��� ��������� ������� �� �������� ����� ������ � ������ ��� �������� ������ ������ ���������,
/// � ������������ �����������.

#include <list>
#include "iostream"
#include "deque"
using namespace std;

int main() {
    std::deque<int> deque1;                   // ������ �������
    std::deque<int> deque2(5);                // deque2 ������� �� 5 �����, ������ ������� ����� �������� �� ���������
    std::deque<int> deque(5, 2);              // deque3 ������� �� 5 �����, ������ ����� ����� 2
    std::deque<int> deque4{ 1, 2, 4, 5 };     // deque4 ������� �� ����� 1, 2, 4, 5
    std::deque<int> deque5 = { 1, 2, 3, 5 };  // deque5 ������� �� ����� 1, 2, 3, 5
    std::deque<int> deque6({ 1, 2, 3, 4, 5 }); // deque6  ������� �� ����� 1, 2, 3, 4, 5
    std::deque<int> deque7(deque4);           // deque7 - ����� ������� deque4
    std::deque<int> deque8 = deque7;          // deque8 - ����� ������� deque7

    /// ��������� ��������� �������
    int first = deque6.front();    // 1
    int last = deque6.back();      // 5
    int second = deque6[1];        // 2
    int third = deque6.at(2);      // 3  ��� ��������� �� ������������� ������� ��� ���������� ���������� out_of_range:
    std::cout << first << second << third << last << std::endl; // 1235

    try
    {
        int n { deque6.at(7) };
        std::cout << n << std::endl;
    }
    catch (const std::out_of_range&)
    {
        std::cout << "Incorrect index" << std::endl;
    }

    /// ������ �������
    if (deque6.empty())
    {
        std::cout << "Deque is empty" << std::endl;
    }
    else
    {
        int n = deque6.size();
        std::cout << "Deque has " << n << " elements" << std::endl;
    }
    deque6.resize(4);  // ��������� ������ ������ ��������
    deque6.resize(6, 8);    // ��������� � ������� n ������ ���������. ���� ������ ������� ������ n, �� ����������� ����������� �������� �� ��������� value

    /// ��������� ��������� �������
    deque6.assign({ 21, 22, 23, 24, 25 }); // numbers = { 21, 22, 23, 24, 25 }

    deque6.assign(4, 3);                   // numbers = {3, 3, 3, 3}

    std::deque<int> values { 6, 7, 8, 9, 10, 11 };
    auto start = values.begin() + 2;    // �������� ��������� �� ������ �������
    auto end = values.end();            // �������� ��������� �� ��������� �������
    deque6.assign(start, end);         //  numbers = { 8, 9, 10, 11 }

    /// ���������� ���������
    std::deque<int> numbers { 1, 2, 3, 4, 5 };
    numbers.push_back(6);   // { 1, 2, 3, 4, 5, 6 }
    numbers.push_front(0);  // { 0, 1, 2, 3, 4, 5, 6 }
    numbers.emplace_back(7);    // { 0, 1, 2, 3, 4, 5, 6, 7 }
    numbers.emplace_front(-1);  // { -1, 0, 1, 2, 3, 4, 5, 6, 7 }

// ���������� � �������� ������ � ������� ������� emplace():
    auto iter = ++numbers.cbegin(); // �������� ��������� �� ������ �������
    numbers.emplace(iter, 8); // ��������� ����� ������� ��������  numbers = { 1, 8, 2, 3, 4, 5};

    // ���������� � �������� ������ � ������� ������� insert():
    std::deque<int> numbers1 { 1, 2, 3, 4, 5 };
    auto iter1 = numbers1.cbegin(); // �������� ��������� �� ������ �������
    numbers1.insert(iter1 + 2, 8); // ��������� ����� ������� ��������
//numbers1 = { 1, 2, 8, 3, 4, 5};

    std::deque<int> numbers2 { 1, 2, 3, 4, 5 };
    auto iter2 = numbers2.cbegin(); // �������� ��������� �� ������ �������
    numbers2.insert(iter2, 3, 4); // ��������� ������� ��� ��������
//numbers2 = { 4, 4, 4, 1, 2, 3, 4, 5};

    std::deque<int> values2 { 10, 20, 30, 40, 50 };
    std::deque<int> numbers3 { 1, 2, 3, 4, 5 };
    auto iter3 = numbers3.cbegin(); // �������� ��������� �� ������ �������
// ��������� � ������ ��� �������� �� values
    numbers3.insert(iter3, values2.begin(), values2.end());
//numbers3 = { 10, 20, 30, 40, 50, 1, 2, 3, 4, 5};

    std::deque<int> numbers4 { 1, 2, 3, 4, 5 };
    auto iter4 = numbers4.cend();   // �������� ��������� �� ������� �� ��������� ���������
// ��������� ����� ���������� �������� ������ { 21, 22, 23 }
    numbers4.insert(iter4, { 21, 22, 23 });
//numbers4 = { 1, 2, 3, 4, 5, 21, 22, 23};

/// �������� ���������
    std::deque<int> numbers5{ 1, 2, 3, 4, 5 };
    numbers5.pop_front();    // numbers = { 2, 3, 4, 5 }
    numbers5.pop_back();     // numbers = { 2, 3, 4 }
    numbers5.clear();    // numbers ={}

    numbers5 = { 1, 2, 3, 4, 5 };
    auto iter5 = numbers5.cbegin(); // ��������� �� ������ �������
    numbers5.erase(iter5);    // ������� ������ �������
// numbers = { 2, 4, 5, 6 }

    numbers5 = { 1, 2, 3, 4, 5 };
    auto begin = numbers5.begin(); // ��������� �� ������ �������
    auto end5 = numbers5.end();       // ��������� �� ��������� �������
    numbers5.erase(++begin, --end5);  // ������� �� ������� �������� �� ����������
//numbers = {1, 5}

    return 0;
}
