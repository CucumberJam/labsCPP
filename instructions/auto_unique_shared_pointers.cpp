#include "string"
#include "iostream"
#include "memory"
/* auto_ptr - устарел и похож на unique
 * unique_ptr - не дает указывать на себя, то есть либо он либо другое, вместе нельзя
 * shared_ptr - общий владение несколькими указателями одним и тем же объектом динам. памяти без вреда при деструкторе
 */
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
    auto_ptr<int> ap1(new int(5));
    auto_ptr<int> ap2(ap1);
// auto_ptr1 - затирает указатель первый при создании второго, смысл тогда7

    unique_ptr<int> up1(new int(5));
// unique_ptr - не дает указывать на себя кому либо - не компилит
    unique_ptr<int> up2;
    up2 = move(up1); // теперь первый уник указатель пустой, а во втором 5
    up1.swap(up2); // теперь они опять меняются местами

    int *up3 = up1.get(); // просто вернет указатель

    int *p = new int(5);
    unique_ptr<int> up4(p);
    up4.reset(); // затирает данные на которые указывает уник указатель

    int *p2 = new int(15);
    unique_ptr<int> up5(p2);
    up5.release(); // данные на которые указывает уник указатель остаются?, но указатель пуст

    shared_ptr<int> sp1(new int(10));
    shared_ptr<int> sp2(sp1); // деструктор вызывается только на послед указателе


    return 0;
}
