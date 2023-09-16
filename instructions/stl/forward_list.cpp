#include <list>
#include "iostream"
#include "forward_list"
using namespace std;

int main(){
    std::forward_list<int> list1;                     // пустой список
    std::forward_list<int> list2(5);                  // list2 имеет 5 элементов, каждый из которых имеет значение по умолчанию
    std::forward_list<int> list3(5, 2);               // list3 состоит из 5 чисел, каждое число равно 2
    std::forward_list<int> list4{ 1, 2, 4, 5 };       // list4 состоит из чисел 1, 2, 4, 5
    std::forward_list<int> list5 = { 1, 2, 3, 4, 5 }; // list5 состоит из чисел 1, 2, 3, 4, 5
    std::forward_list<int> list6(list4);              // list6 - копия списка list4
    std::forward_list<int> list7 = list4;             // list7 - копия списка list4
    std::forward_list<int> list8({ 1, 2, 3, 4, 5, 6 }); // list8  состоит из чисел 1, 2, 3, 4, 5, 6

    ///Получение элементов - Напрямую в списке forward_list можно получить только первый элемент
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

    // before_begin() и cbefore_begin(). Обе функции возвращают итератор
    // (вторая функция возвращает константный итератор const_iterator) на
    // несуществующий элемент непосредственно перед началом списка
    auto prev = numbers.before_begin();
    while (++prev != end)
    {
        std::cout << *prev << "\t";
    }
    std::cout << std::endl;
    numbers.resize(4);  // оставляем первые четыре элемента - numbers = {1, 2, 3, 4}
// resize(n, value): также оставляет в списке n первых элементов. Если размер списка меньше n, то добавляются недостающие элементы со значением value
    numbers.resize(6, 8);    // numbers = {1, 2, 3, 4, 8, 8}

    /// Изменение элементов списка
    // Функция assign() позволяет заменить все элементы списка определенным набором
    numbers.assign({ 21, 22, 23, 24, 25 }); // numbers = { 21, 22, 23, 24, 25 }

    numbers.assign(4, 3);       // numbers = {3, 3, 3, 3}

    std::list<int> values{ 6, 7, 8, 9, 10, 11 };
    auto start2 = ++values.begin();  // итератор указывает на второй элемент из values
    auto end2 = values.end();
    numbers.assign(start2, end2); //  numbers = { 7, 8, 9, 10, 11 }

    std::forward_list<int> list_1{ 1, 2, 3, 4, 5 };
    std::forward_list<int> list_2{ 6, 7, 8, 9};
    list_1.swap(list_2);

    /// Добавление элементов
    std::forward_list<int> numbers2{ 7, 8 };
    numbers2.push_front(6);  // добавляет объект val в начало списка - 6
    // numbers =  { 6, 7, 8 }

    numbers2.emplace_front(-3);  // добавляет объект val в начало списка - -3
    // numbers =  { -3, 6, 7, 8 }

    auto iter = numbers2.begin();
    // вставляет объект val после элемента, на который указывает итератор p.
    // Возвращает итератор на вставленный элемент.
    // Если p представляет итератор на позицию после конца списка, то результат неопределен.
    iter = numbers2.emplace_after(iter, -2); // добавляем после итератора число -2
    // numbers =  { -3, -2, 6, 7, 8 }

    // вставляет объект val после элемента, на который указывает итератор p.
    // Возвращает итератор на вставленный элемент
    iter = numbers2.insert_after(iter, -1);
    // numbers =  { -3, -2, -1, 6, 7, 8 }

    // insert_after(p, n, val): вставляет n объектов val после элемента,
    // на который указывает итератор p. Возвращает итератор на последний вставленный элемент.
    iter = numbers2.insert_after(iter, 3, 0);    // добавляем три нуля
    // numbers =  { -3, -2, -1, 0, 0, 0, 6, 7, 8 }

    // insert_after(p, begin, end): вставляет после элемента, на который указывает итератор p,
    // набор объектов из другого контейнера, начало и конец которого определяется итераторами begin и end.
    // Возвращает итератор на последний вставленный элемент.
    std::list<int> values2{ 1, 2, 3 };
    iter = numbers2.insert_after(iter, values2.begin(), values.end()); // добавляем все элементы из values
    // numbers =  { -3, -2, -1, 0, 0, 0, 1, 2, 3, 6, 7, 8 }

    // insert_after(p, il): вставляет после элемента, на который указывает итератор p,
    // список инициализации il. Возвращает итератор на последний вставленный элемент.
    numbers2.insert_after(iter, { 4, 5 }); // добавляем список { 4, 5 }
    // numbers =  { -3, -2, -1, 0, 0, 0, 1, 2, 3, 4, 5, 6, 7, 8 }

    for(int n : numbers2)
        std::cout << n << "\t";
    std::cout << std::endl;

    /// Удаление элементов
    std::forward_list<int> numbers3{ 1, 2, 3, 4, 5, 6, 7};

    numbers3.pop_front();  // удаляет первый элемент
// numbers = { 2, 3, 4, 5, 6, 7};

    //  удаляет элемент после элемента, на который указывает итератор p.
    //  Возвращает итератор на элемент после удаленного
    auto iter2 = numbers3.erase_after(numbers3.begin());
// numbers = { 2, 4, 5, 6, 7 };
// iter указывает на элемент 4

    // удаляет диапазон элементов, на начало и конец которого указывают
    // соответственно итераторы begin и end.
    // Возвращает итератор на элемент после последнего удаленного
    numbers3.erase_after(iter2, numbers3.end());
// numbers = { 2, 4 };

    return 0;
}
