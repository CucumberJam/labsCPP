/// Двусвязный список из библиотеки STL - динамическая струтура данных, которая очень
/// быстро удаляет и вставляет элемент в любом месте контейнера (итерация происходит быстрее)
/// в Листе нельзя обращаться через квадратные скобки, только через итераторы
/// возможности обратиться сразу к элементу нет (только последовательно через каждый элемент)
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
    std::list<int> list1;             // пустой список
    std::list<int> list2(5);          // список list2 состоит из 5 чисел, каждый элемент имеет значение по умолчанию
    std::list<int> list3(5, 2);           // список list3 состоит из 5 чисел, каждое число равно 2
    std::list<int> list4{ 1, 2, 4, 5 };   // список list4 состоит из чисел 1, 2, 4, 5
    std::list<int> list5 = { 1, 2, 3, 5 }; // список list5 состоит из чисел 1, 2, 4, 5
    list4.swap(list5);
    std::list<int> list6(list4);          // список list6 - копия списка list4
    std::list<int> list7 = list4;         // список list7 - копия списка list4


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

    myList.unique(); // удаляет дубль числа которые идут последовательно
    myList.reverse(); // меняет элементы в обратном порядке
    myList.clear();   // удаляет все элементы

    ++it;  // не обладает произвольным назначением значения итератору
    advance(it, 1); // сдвинуть итератор  на произвольное назначение
    myList.insert(it, 45);

    myList.remove(15); // удаляет конкретный элемент (значение если оно естьв  списке)
    myList.assign(3, 44);  // заполнять лист какими то элементами, причем предыдущие (3) он удаляет
    auto begin = ++it;
    auto end = ++it;
    myList.assign(begin, end); // заменяет содержимое контейнера элементами из диапазона, на начало и конец которого указывают итераторы begin и end


    printList(myList);
/// assign используется для того чтобы скопировать значения одного листа в другой лист
    list<int> myList2 = {150,160,170};
    list<int> myList3 = {250,260,270};
    list<int> myList4;
    myList4.assign(myList2.begin(), myList2.end()); // скопировали значения и элементы 2 листа в 4
    printList(myList4);





    return 0;
}
