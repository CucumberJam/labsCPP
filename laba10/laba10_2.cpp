#include "iostream"
#include "string"
using namespace std;

template<typename T>
class List {
public:
    List();
    ~List();
    static int Count;
    int getSize(){return size;}
    void push_back(T data);
    void push_front(T data);
    void pop_front();
    void pop_back();
    void insert(T data, int index);
    void removeAtIndex(int index);
    int find(int id);
    T& operator[](const int index);
    T& getNode(int id);
    void clear();
    void showList();
protected:
    template<typename T1>
    class Node{
    public:
        Node *pNext;
        T1 data;

        Node(T1 data = T1(), Node *pNext = nullptr){
            this->data = data;
            this->pNext = pNext;
            Count ++;
            id = Count;
        }
        int getId(){ return id;}
        int getConst(){ return Count;}

    private:
        int id;
    };
    int size;
    Node<T> *head;

};
template<typename T>
int List<T>::Count = 0;


int main(){
    int size;
    List<int> testList;
    cout << "What size of list you want? " << endl;
    cin >> size;

    for(int i = 0; i<size; i++){
        int x;
        cout << "number: " << endl;
        cin >> x;
        testList.push_back(x);
    }
    testList.push_front(100);
    testList.push_back(100);
    cout << "After push_front(100) and push_back(100): " << endl;
    testList.showList();
    cout << "Size of list: " << testList.getSize() << endl;
    testList.pop_front();
    testList.pop_back();
    cout << "After pop_front() and pop_back(): " << endl;
    testList.showList();
    testList.insert(999, 2);
    cout << "After insert(999,2): " << endl;
    testList.showList();

    int findId;
    cout << "What id Node you want? " << endl;
    cin >> findId;
    cout << "Node with id: " << findId<< " is " << testList[testList.find(findId)] << endl;
    cout << "Node with id: " << findId<< " is " << testList.getNode(findId) << endl;




    return 0;
}
template<class T>
List<T>::List() {
    size = 0;
    head = nullptr;
}
template<class T>
List<T>::~List() {
    clear();
}
template<class T>
void List<T>:: push_back(T data){
    if (head == nullptr){
        head = new Node<T>(data);
    } else{
        Node<T> *current = this->head;
        while (current->pNext != nullptr){
            current = current->pNext;
        }
        current->pNext = new Node<T>(data);
    }
    size++;
}
template<typename T>
void List<T>::push_front(T data) {
    head = new Node<T>(data, head);
    size++;
}
template<typename T>
void List<T>::pop_front() {
    Node<T> *temp = head;
    head = head->pNext;
    delete temp;
    size--;
}
template<class T>
T& List<T>:: operator[](const int index){
    int counter = 0;
    Node<T> *current = this->head;
    while (current!= nullptr){
        if(counter== index){
            return current->data;
        }
        current = current->pNext;
        counter++;
    }
}
template<typename T>
void List<T>::insert(T data, int index) {
    if (index == 0){
        push_front(data);
    }
    Node<T> *previous = this->head;
    for(int i = 0; i < index-1; i++){
        previous = previous->pNext;
    }
    Node<T> *newNode = new Node<T>(data, previous->pNext);
    previous->pNext = newNode;
    size++;
}
template<typename T>
void List<T>::removeAtIndex(int index) {
    if(index == 0){
        pop_front();
    } else{
        Node<T> *previous = this->head;
        for(int i = 0; i < index-1; i++){
            previous = previous->pNext;
        }
        Node<T> *toDelete = previous->pNext;
        previous->pNext = toDelete->pNext;
        delete toDelete;
        size--;
    }
}
template<typename T>
void List<T>::pop_back() {
    removeAtIndex(size-1);
}
template<typename T>
int List<T>::find(int id){  // Поиск элемента по его id возвращает индекс элемента в списке:
    int index = 0;
    Node<T> *current = this->head;
    while (current){
        if(current->getId() == id) break;
        current = current->pNext;
        index++;
    }
    return index;
}
template<typename T>
T& List<T>::getNode(int id) {
    int index = 0;
    Node<T> *current = this->head;
    while (current){
        if(current->getId() == id) break;
        current = current->pNext;
    }
    return current->data;
}
template<typename T>
void List<T>::clear(){
    while (size){
        pop_front();
    }
}
template<typename T>
void List<T>::showList(){
    Node<T> * current = this->head;
    cout << "List of elements: " << endl;
    int count = 0;
    while (current){
        cout << "# " << ++count << ": " << current->data << ", id: " << current->getId() << endl;
        current = current->pNext;
    }
}
// Создать шаблон класса "односвязный линейный список"