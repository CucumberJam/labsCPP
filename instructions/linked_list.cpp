/// Односвязный (однонаправленный список - динам. структура данных
#include "iostream"
#include "string"
using namespace std;

template<typename T>
class List{
public:
    List();
    ~List();
    void push_back(T data);
    int getSize(){return size;}
    T& operator[](const int index);
    void popFront();
    void clear();
    void push_front(T data);
    void insert(T value, int index);
    void removeAt(int index);
    void pop_back();
private:
    template<typename T1>
    class Node{
    public:
        Node *pNext;
        T data;
        Node(T data = T(), Node *pNext = nullptr){
            this->data = data;
            this->pNext = pNext;
        }
    };
    int size;
    Node<T> *head;
};
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
void List<T>::popFront() {
    Node<T> *temp = head;
    head = head->pNext;
    delete temp;
    size--;
}

template<typename T>
void List<T>::clear() {
    while (size){
        popFront();
    }
}

template<typename T>
void List<T>::push_front(T data) {
    head = new Node<T>(data, head);
    size++;

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
void List<T>::removeAt(int index) {
    if(index == 0){
        popFront();
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
    removeAt(size-1);
}

int main(){
    List<int> list;

    int numbersCount;
    cout << "Size of list: " << endl;
    cin >> numbersCount;

    for(int i = 0; i < numbersCount; i++){
        list.push_back( rand() % 10+1);
    }

    for(int i = 0 ; i < list.getSize(); i++){
        cout << "# " << i+1 << " - " << list[i] << endl;
    }

    cout << "Using the method pushFront(44):" << endl;
    list.push_front(44);
    for(int i = 0 ; i < list.getSize(); i++){
        cout << "# " << i+1 << " - " << list[i] << endl;
    }

    cout << "Using the method popFront():" << endl;
    list.popFront();
    for(int i = 0 ; i < list.getSize(); i++){
        cout << "# " << i+1 << " - " << list[i] << endl;
    }

    cout << "Using the method insert(99,1):" << endl;
    list.insert(99,1);
    for(int i = 0 ; i < list.getSize(); i++){
        cout << "# " << i+1 << " - " << list[i] << endl;
    }

    cout << "Using the method removeAt(1) - 99:" << endl;
    list.removeAt(1);
    for(int i = 0 ; i < list.getSize(); i++){
        cout << "# " << i+1 << " - " << list[i] << endl;
    }

    cout << "Using the method pop_back():" << endl;
    list.pop_back();
    for(int i = 0 ; i < list.getSize(); i++){
        cout << "# " << i+1 << " - " << list[i] << endl;
    }

    cout << "Using the method clear():" << endl;
    list.clear();
    cout << "Size of the list: " << list.getSize() << endl;



    return 0;
}
