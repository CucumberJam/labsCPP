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
class IdGenerator{
    static int count;
    int id;
public:
    int getId(){
        count ++;
        return  id = count;
    }
};
int IdGenerator::count=0;

template<typename T>
class List {
public:
    List();
    ~List();
    int getSize(){return size;}
    void push_back(T data, int id);
    void push_front(T data, int id);
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

        Node(T1 data = T1(), int id=(0), Node *pNext = nullptr){
            this->data = data;
            this->pNext = pNext;
            this->id = id;
        }
        int getId(){ return id;}

    private:
        int id;
    };
    int size;
    Node<T> *head;

};

int main(){
    IdGenerator idGenerator;
    List<BusDriver> listBusPark;

    int tempId = idGenerator.getId();
    BusDriver busDriver1 = BusDriver(45, "Ivanov I.A.", 3);
    listBusPark.push_back(busDriver1, tempId);

    tempId = idGenerator.getId();
    BusDriver busDriver2 = BusDriver(84, "Petrov E.N.", 5);
    listBusPark.push_back(busDriver2, tempId);

    tempId = idGenerator.getId();
    BusDriver busDriver3 = BusDriver(10, "Lazarev G.S.", 8);
    listBusPark.push_front(busDriver3, tempId);

    tempId = idGenerator.getId();
    BusDriver busDriver4 = BusDriver(10, "Volkov D.P.", 8);
    listBusPark.push_front(busDriver4, tempId);

    tempId = idGenerator.getId();
    BusDriver busDriver5 = BusDriver(12, "Belov S.A.", 5);
    listBusPark.push_front(busDriver5, tempId);

    tempId = idGenerator.getId();
    BusDriver busDriver6 = BusDriver(32, "Doronon V.E.", 3);
    listBusPark.push_front(busDriver5, tempId);

    cout << "List of drivers in park: " << endl;
    listBusPark.showList();

    List<BusDriver> listBusWork;

    int temp;
    cout << "What id number of driver is going out?" << endl;
    cin >> temp;


    listBusPark.change(temp, listBusWork);

    cout << "List of drivers in park after bus driver with id: " << temp << " getting out:" << endl;
    listBusPark.showList();

    cout << "List of drivers at work: " << endl;
    listBusWork.showList();

    listBusWork.change(temp, listBusPark);
    cout << "List of drivers in park after bus driver with id: " << temp << " coming back:" << endl;
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
void List<T>:: push_back(T data, int id){
    if (head == nullptr){
        head = new Node<T>(data, id);
    } else{
        Node<T> *current = this->head;
        while (current->pNext != nullptr){
            current = current->pNext;
        }
        current->pNext = new Node<T>(data, id);
    }
    size++;
}
template<typename T>
void List<T>::push_front(T data, int id) {
    head = new Node<T>(data, id, head);
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
    listTarget.push_front(nodeTarget.data, id);
    this->removeAtIndex(find(id));
}
// Составить программу которая содержит динамическую информацию о наличии автобусов в автобусном парке
// СВедения о каждом автобусе содержат:
// номер автобуса, фамилию и инициалы водителя, номер маршрута.
// Программа должна обеспечивать:
// - начальное формирование данных обо всех автобусах в парке в виде списка;
// - При выезде каждого автобуса из парка вводится номер автобуса и программа удаляет данные
// об этом автобусе из списка автобусов, находящихся в парке и записывает эти данные
// в список автобусов, находящихся на маршруте.
// - при въезде автобуса в парк, программа удаляет данные о нем из списка автобусов,
// находящихся на маршруте и записывает в список автобусов в парке.
// - по запросу выдаются сведения об автобусах, находящихся в парке или на маршруте.