#include <array>
#include "iostream"
using namespace std;

int main(){
    std::array<int, 5> numbers1 { 1, 2, 3, 4, 5 };
    std::array<int, 5> numbers2 = numbers1;       // так можно сделать
    for(int n : numbers1)
        cout << n << "\t";      // 5    3   10
    std::cout << std::endl;
    std::cout << std::boolalpha << (numbers1 == numbers2) << std::endl;       // true
    std::cout << std::boolalpha << (numbers1 != numbers2) << std::endl;       // false
    std::cout << std::boolalpha << (numbers1 > numbers2) << std::endl;         // false
    std::cout << std::boolalpha << (numbers1 < numbers2) << std::endl;     // false


    std::array<std::string, 3> people { "Tom", "Bob", "Sam" };
    std::string second = people.at(1);    // Bob
    std::string first = people.front();  // Tom
    std::string last = people.back();    // Sam

    std::cout << second << std::endl;   // Bob
    std::cout << first << std::endl;    // Tom
    std::cout << last << std::endl;     // Sam

    // присваиваем всем элементам "Undefined"
    people.fill("Undefined");  // people = { "Undefined", "Undefined", "Undefined" }
    // проверяем
    for (int i{}; i< people.size(); i++)
    {
        std::cout << people[i] << std::endl;
    }


    return 0;
}
