/// поддерживает произвольный доступ к элементам контейнера, но в отличие от вектора также
/// поддерживает добавление в начало контейнера. Кроме того, во внутренней реализации deque
/// при изменении размера не выделяет новый массив в памяти для вмещения нового набора элементов,
/// а манипулирует указателями.

#include <list>
#include "iostream"
#include "deque"
using namespace std;

int main() {
    std::deque<int> deque1;                   // пустая очередь
    std::deque<int> deque2(5);                // deque2 состоит из 5 чисел, каждый элемент имеет значение по умолчанию
    std::deque<int> deque(5, 2);              // deque3 состоит из 5 чисел, каждое число равно 2
    std::deque<int> deque4{ 1, 2, 4, 5 };     // deque4 состоит из чисел 1, 2, 4, 5
    std::deque<int> deque5 = { 1, 2, 3, 5 };  // deque5 состоит из чисел 1, 2, 3, 5
    std::deque<int> deque6({ 1, 2, 3, 4, 5 }); // deque6  состоит из чисел 1, 2, 3, 4, 5
    std::deque<int> deque7(deque4);           // deque7 - копия очереди deque4
    std::deque<int> deque8 = deque7;          // deque8 - копия очереди deque7

    /// Получение элементов очереди
    int first = deque6.front();    // 1
    int last = deque6.back();      // 5
    int second = deque6[1];        // 2
    int third = deque6.at(2);      // 3  при обращении по некорректному индексу она генерирует исключение out_of_range:
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

    /// Размер очереди
    if (deque6.empty())
    {
        std::cout << "Deque is empty" << std::endl;
    }
    else
    {
        int n = deque6.size();
        std::cout << "Deque has " << n << " elements" << std::endl;
    }
    deque6.resize(4);  // оставляем первые четыре элемента
    deque6.resize(6, 8);    // оставляет в очереди n первых элементов. Если размер очереди меньше n, то добавляются недостающие элементы со значением value

    /// Изменение элементов очереди
    deque6.assign({ 21, 22, 23, 24, 25 }); // numbers = { 21, 22, 23, 24, 25 }

    deque6.assign(4, 3);                   // numbers = {3, 3, 3, 3}

    std::deque<int> values { 6, 7, 8, 9, 10, 11 };
    auto start = values.begin() + 2;    // итератор указывает на третий элемент
    auto end = values.end();            // итератор указывает на последний элемент
    deque6.assign(start, end);         //  numbers = { 8, 9, 10, 11 }

    /// Добавление элементов
    std::deque<int> numbers { 1, 2, 3, 4, 5 };
    numbers.push_back(6);   // { 1, 2, 3, 4, 5, 6 }
    numbers.push_front(0);  // { 0, 1, 2, 3, 4, 5, 6 }
    numbers.emplace_back(7);    // { 0, 1, 2, 3, 4, 5, 6, 7 }
    numbers.emplace_front(-1);  // { -1, 0, 1, 2, 3, 4, 5, 6, 7 }

// Добавление в середину списка с помощью функции emplace():
    auto iter = ++numbers.cbegin(); // итератор указывает на второй элемент
    numbers.emplace(iter, 8); // добавляем после первого элемента  numbers = { 1, 8, 2, 3, 4, 5};

    // Добавление в середину списка с помощью функции insert():
    std::deque<int> numbers1 { 1, 2, 3, 4, 5 };
    auto iter1 = numbers1.cbegin(); // итератор указывает на второй элемент
    numbers1.insert(iter1 + 2, 8); // добавляем после второго элемента
//numbers1 = { 1, 2, 8, 3, 4, 5};

    std::deque<int> numbers2 { 1, 2, 3, 4, 5 };
    auto iter2 = numbers2.cbegin(); // итератор указывает на первый элемент
    numbers2.insert(iter2, 3, 4); // добавляем вначало три четверки
//numbers2 = { 4, 4, 4, 1, 2, 3, 4, 5};

    std::deque<int> values2 { 10, 20, 30, 40, 50 };
    std::deque<int> numbers3 { 1, 2, 3, 4, 5 };
    auto iter3 = numbers3.cbegin(); // итератор указывает на первый элемент
// добавляем в начало все элементы из values
    numbers3.insert(iter3, values2.begin(), values2.end());
//numbers3 = { 10, 20, 30, 40, 50, 1, 2, 3, 4, 5};

    std::deque<int> numbers4 { 1, 2, 3, 4, 5 };
    auto iter4 = numbers4.cend();   // итератор указывает на позицию за последним элементом
// добавляем после последнего элемента список { 21, 22, 23 }
    numbers4.insert(iter4, { 21, 22, 23 });
//numbers4 = { 1, 2, 3, 4, 5, 21, 22, 23};

/// Удаление элементов
    std::deque<int> numbers5{ 1, 2, 3, 4, 5 };
    numbers5.pop_front();    // numbers = { 2, 3, 4, 5 }
    numbers5.pop_back();     // numbers = { 2, 3, 4 }
    numbers5.clear();    // numbers ={}

    numbers5 = { 1, 2, 3, 4, 5 };
    auto iter5 = numbers5.cbegin(); // указатель на первый элемент
    numbers5.erase(iter5);    // удаляем первый элемент
// numbers = { 2, 4, 5, 6 }

    numbers5 = { 1, 2, 3, 4, 5 };
    auto begin = numbers5.begin(); // указатель на первый элемент
    auto end5 = numbers5.end();       // указатель на последний элемент
    numbers5.erase(++begin, --end5);  // удаляем со второго элемента до последнего
//numbers = {1, 5}

    return 0;
}
