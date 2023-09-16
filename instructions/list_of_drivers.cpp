#include "iostream"
#include "string"
using namespace std;

class BusDriver{
public:
    BusDriver(int numbBus, string fullName, int numItinerary){
        this->numbBus = numbBus;
        this->fullName = fullName;
        this->numItinerary = numItinerary;
    }
    BusDriver(int numbBus, string fullName): BusDriver(numbBus, fullName, 99){}
    BusDriver(int numbBus):BusDriver(numbBus, string("Undefined"), 99){}
    BusDriver(): BusDriver(99, string("Undefined"), 99){}

    ~BusDriver(){}
    int getNumBus(){ return numbBus;}
    int getNumItinerary(){ return numItinerary;}
    string getFullName(){ return fullName;}
private:
    int numbBus;
    string fullName;
    int numItinerary;
};
ostream& operator<<(ostream& os, BusDriver& busDriver){
    os << busDriver.getNumBus() << " " << busDriver.getFullName() << " " << busDriver.getNumItinerary();
    return os;
}
//class IdGenerator{
//    static int count;
//    int id;
//public:
//    int getId(){
//        count ++;
//        return  id = count;
//    }
//};
//int IdGenerator::count=0;

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
    void change(int id, List& listTarget);
protected:
    template<typename T1>
    class Node{
    public:
        Node *pNext;
        T1 data;

        Node(T1 data = T1(), Node *pNext = nullptr){
            this->data = data;
            this->pNext = pNext;
            id = Count;
        }
        int getId(){ return id;}
        int getCount(){ return Count;}

    private:
        int id;
    };
    int size;
    Node<T> *head;

};
template<typename T>
int List<T>::Count = 0;


int main(){
// BusDriver busDriver1 = BusDriver(45, "Ivanov I.A.", 3);
    // cout << busDriver1;

    List<BusDriver> listBusPark;
    listBusPark.push_back({45, "Ivanov I.A.", 3});
    listBusPark.push_back({84, "Petrov E.N.", 5});
    listBusPark.push_front({10, "Lazarev G.S.", 8});

    cout << "List od drivers in park: " << endl;
    listBusPark.showList();

    List<BusDriver> listBusWork;

    listBusPark.change(2, listBusWork);

    cout << "List od drivers in park after bus driver with id: " << 2 << " getting out:" << endl;
    listBusPark.showList();

    cout << "List od drivers at work: " << endl;
    listBusWork.showList();




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

template<typename T>
void List<T>::change(int id, List &listTarget) {
    Node<T> nodeTarget = getNode(id);
    listTarget.push_front(nodeTarget.data);
    this->removeAtIndex(find(id));
}

