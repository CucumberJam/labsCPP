#include "iostream"
#include "vector"
using namespace std;

/// Библиотека станд-ых шаблонов (STL) - набор стандартных решений для использования в частых задачах
/// VECTOR

int main(){
    vector<int> myVector; // динамический массив c встроенными функциями увеличения памяти (удаления) и тд
    myVector.push_back(10);
    myVector.push_back(99);
    myVector.push_back(3);
    // emplace_back() выполняет аналогичную задачу - добавляет элемент в конец контейнера:
    myVector.emplace_back(800);

    vector<int> myVector2(10); // вектор инициализирован например по умолчанию 10 элементами

    vector<int> myVector3(myVector);
    vector<int> myVector4 = myVector2;
    vector<int> myVector5(5, 6); // вектор v5 состоит из 5 чисел, каждое число равно 6
    vector<int> myVector6{6, 6, 6, 6};
    vector<int> myVector7 = {1,2,3,4,5};

    // Добавление элементов на определенную позицию:
    // emplace(pos, value): вставляет элемент value на позицию, на которую указывает итератор pos
    auto it7 = myVector7.begin();
    advance(it7,2);
    myVector7.emplace(it7,666);
    myVector7.insert(++it7, 777);
    myVector7.insert(++it7, 5, 33); // вставляет n элементов value начиная с позиции, на которую указывает итератор pos
    myVector7.insert(it7+=5, myVector6.begin(),myVector6.end()); // вставляет начиная с позиции, на которую указывает итератор pos, элементы из другого контейнера из диапазона между итераторами begin и end
    auto last7 = myVector7.end();
    // удалить элемент из середины или начала контейнера, применяется функция std::erase()
    myVector7.erase(it7); // удаляет элемент, на который указывает итератор p. Возвращает итератор на элемент, следующий после удаленного, или на конец контейнера, если удален последний элемент
    myVector7.erase(it7, last7); // удаляет элементы из диапазона, на начало и конец которого указывают итераторы begin и end.




    cout << "Array's size " << myVector.size() << endl;
    cout << "Array: " << endl;
    for(int num: myVector){
        cout << num << endl;
    }
    int first = myVector.front();
    int last = myVector.back();
    int second = myVector[2];
    cout << "myVector.front(): "<< first << endl;
    cout << "myVector.back(): " << last << endl;
    cout << "myVector[2]: " << second << endl;
    // изменить можем значение:
    myVector[0] = 1000;
    cout << "Array after changing first element: " << endl;
    for(int num: myVector){
        cout << num << "\t";
    }
    myVector.pop_back(); // удаляет последний элемент
    cout << "Array after pop_back(): " << endl;
    for(int num: myVector){
        cout << num << endl;
    }

    // выход за границы массива если мы работаем через оператор []:
    cout << "Array beyond means: " << endl;
    cout << myVector[10] << endl;

    // если мы работаем через .at(index) то проверяет и не дает выход за границы массива:
    cout << "Array at(1): " << endl;
    cout << myVector.at(1) << endl; // он медленее чем []
    // проверка:
    try{
        cout << myVector.at(10) << endl;
    }catch (const std::out_of_range & ex){
        cout << ex.what() << endl;
    }

    cout << "Array's capacity " <<  myVector.capacity()<< endl;
    myVector.reserve(100);
    cout << "Array's capacity after reserve(100) " <<  myVector.capacity()<< endl;
    myVector.shrink_to_fit();
    cout << "Array's shrink_to_fit() " << endl;
    cout << "Array's capacity " <<  myVector.capacity()<< endl;
    cout << "Array's size " << myVector.size() << endl;

    cout << "Array's empty? " <<     myVector.empty() << endl;
    myVector.clear();
    cout << "Array's size after clear " << myVector.size() << endl;
    cout << "Array's empty? " <<     myVector.empty() << endl;

    myVector.resize(20,555); // инициализирует 20 элементов по 555 в каждом
    cout << "Array's after resize(20,555) " <<     myVector.empty() << endl;
    for(int num: myVector){
        cout << num << endl;
    }


    return 0;
}