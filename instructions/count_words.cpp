#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
    string text; // �������� �����
    cout << "Enter some text: ";
    getline(std::cin, text);
    const string separators{ " ,;:.\"!?'*\n" }; // ����������� ����
    vector<string> words; // ������ ��� �������� ����
    size_t start { text.find_first_not_of(separators) }; // ��������� ������ ������� �����
    while (start != string::npos) // ��������, ���� � ������ �� �������� ������ ��������, ����� separators
    {
        size_t end = text.find_first_of(separators, start + 1); // �������, ��� ��������� �����
        if (end == string::npos) // ���� �� ������ �� ���� �� ��������-������������
            end = text.length();        // ������������� ���������� end �� ����� ������
        words.push_back(text.substr(start, end - start)); // ��������� � ������ �����
        start = text.find_first_not_of(separators, end + 1); // ������� ��������� ������ ���������� ����� � ����������������� start
    }
    // ������� ���������� ����
    std::cout << "\nText contains " << words.size() << " words:" << std::endl;
    // ������� ��� ����� �� �������
    for (const auto& word : words)
    {
        std::cout << word << std::endl;
    }
    return 0;
}


// #include <iostream>
//#include <fstream>
//#include <string>
//#include <vector>
//
//class Person
//{
//public:
//    std::string name;
//    int age;
//    Person(std::string n, int a): name(n),age(a) { }
//    Person(){ }
//};
//std::ostream& operator << (std::ostream &os, const Person &p)
//{
//    return os << p.name << " " << p.age;
//}
//std::istream& operator >> (std::istream& in, Person& p)
//{
//    in >> p.name >> p.age;
//    if (!in)
//    {
//        p = Person();
//    }
//    return in;
//}
//int main()
//{
//    // ��������� ������ - ������ �������� Person
//    std::vector<Person> people =
//    {
//        Person("Tom", 23),
//        Person("Bob", 25),
//        Person("Alice", 22),
//        Person("Kate", 31)
//    };
//    // ������ ������ � ����
//    std::ofstream out("D:\\users.txt");
//    if (out.is_open())
//    {
//        for (int i = 0; i < people.size(); i++)
//        {
//            out << people[i] << std::endl;
//        }
//    }
//    out.close();
//    // ������ ��� ����������� ������
//    std::vector<Person> users;
//    // ������ ����� ���������� ������ �� �����
//    std::ifstream in("D:\\users.txt");
//    if (in.is_open())
//    {
//        Person p;
//        while (in >> p)
//        {
//            users.push_back(p);
//        }
//    }
//    in.close();
//    // ����� ��������� ������ �� �������
//    std::cout << "All users:" << std::endl;
//    for (int i = 0; i < users.size(); i++)
//    {
//        std::cout << users[i] << std::endl;
//    }
//
//    return 0;
//}
