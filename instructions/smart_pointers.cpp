#include "string"
#include "iostream"

using namespace std;

template<class T>
class SmartPointer{
public:
    SmartPointer(T *ptr){
        this->ptr = ptr;
        cout<< "Constructor" << endl;
    }
    ~SmartPointer(){
        delete ptr;
        cout<< "Destructor" << endl;
    }
    T& operator*(){
        return *ptr;
    }
private:
    T *ptr;
};

int main(){
//    int *ptr = new int(5);
//    cout<<"Address: " << ptr << ", value =  "<< *ptr << endl;
//    delete ptr;

    SmartPointer<int> pointer = new int(5);
    *pointer = 13123;
    cout<< *pointer << endl;

    return 0;
}