#include "iostream"
#include "string"

using namespace std;

/// по умолчанию поля в классе приватные
/// по умолчанию при наследовании все поля нааследуются как приватрные
class Myclass{
public:
    int a = 10;
    void print(){
        cout << a << endl;
    }
};
class Myclass2: public Myclass{  // если явно не указать публ то все поля будут приватными и не доступными

};
/// по умолчанию поля в структуре публичные
/// по умолчанию при наследовании все поля нааследуются как публичные
struct Mystruct{
    Mystruct(){
        a = 22;
    }
    ~Mystruct(){};
    int a = 22;
    void print(){
        cout << a << endl;
    }
};
struct Mystruct2: Mystruct{

};

int main(){
    Myclass m;
    Mystruct ms;

    ms.print();
    ms.a = 10;
    ms.print();

    m.print();

    Myclass2 m2;
    m2.print();

    Mystruct2 ms2;
    ms2.print();

    return 0;
}