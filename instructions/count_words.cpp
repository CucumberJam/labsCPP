#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
    string text; // Исходный текст
    cout << "Enter some text: ";
    getline(std::cin, text);
    const string separators{ " ,;:.\"!?'*\n" }; // разделители слов
    vector<string> words; // вектор для хранения слов
    size_t start { text.find_first_not_of(separators) }; // начальный индекс первого слова
    while (start != string::npos) // проходим, пока в строке не окажется других символов, кроме separators
    {
        size_t end = text.find_first_of(separators, start + 1); // находим, где кончается слово
        if (end == string::npos) // если НЕ найден ни один из символов-разделителей
            end = text.length();        // устанавливаем переменную end на конец текста
        words.push_back(text.substr(start, end - start)); // добавляем в вектор слово
        start = text.find_first_not_of(separators, end + 1); // находим начальный индекс следующего слова и переустанавливаем start
    }
    // выводим количество слов
    std::cout << "\nText contains " << words.size() << " words:" << std::endl;
    // выводим все слова на консоль
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
//    // начальные данные - вектор объектов Person
//    std::vector<Person> people =
//    {
//        Person("Tom", 23),
//        Person("Bob", 25),
//        Person("Alice", 22),
//        Person("Kate", 31)
//    };
//    // запись данных в файл
//    std::ofstream out("D:\\users.txt");
//    if (out.is_open())
//    {
//        for (int i = 0; i < people.size(); i++)
//        {
//            out << people[i] << std::endl;
//        }
//    }
//    out.close();
//    // вектор для считываемых данных
//    std::vector<Person> users;
//    // чтение ранее записанных данных из файла
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
//    // вывод считанных данных на консоль
//    std::cout << "All users:" << std::endl;
//    for (int i = 0; i < users.size(); i++)
//    {
//        std::cout << users[i] << std::endl;
//    }
//
//    return 0;
//}
