#include "iostream"
#include "vector"
#include "list"
using namespace std;
/// for_each - алгоритм
/// range based - перебирать коллекцию циклов
template<typename T>
void PrintList(const list<T> &list){
    for(auto i = list.cbegin(); i != list.end(); ++i){
        cout << *i << endl;
    }
}
int main(){
    int arr[] = {5,11,94,44};

    for(auto number: arr){
        number++;
        cout << number << endl;
    }

    for(const auto &number: arr){    // не сможем менять значения элементов
        cout << number << endl;
    }

    list<int> myList = {1, 75,4,56,23,88};
    for(const auto &num: myList){
        cout << num << endl;
    }

    return 0;
}
