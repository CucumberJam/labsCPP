#include "iostream"
using namespace std;

template<typename T>
class Typesize{
public:
    Typesize(T value){
        this->value =value;
    }
    void DataTypeSize(){
        cout << sizeof(value) << endl;
    }
private:
    T value;
};
class Point{
private:
    int x, y, z;
public:
    Point(){
        x=y=z=0;
    }
    Point(int x, int y, int z){
        this->x = x;
        this->y = y;
        this->z = z;
    }
    ~Point(){}
};
template<class T>
class Printer{
public:
    void print(T value){
        cout << value << endl;
    }
};
/// —пециализированный шаблон под string:
template<>
class Printer<string>{
public:
    void print(string value){
        cout << "___" << value << "___" << endl;
    }
};
///  «апрет на использование шаблона под char:
template<>
class Printer<char*>{
public:
    void print(char* value){

    }
};
int main(){
    int a = 5.99;

    Typesize<double> c(a);
    c.DataTypeSize();

    Point p;
    Typesize<Point> typesize(p);
    typesize.DataTypeSize();

    Printer<string> str;
    str.print("Fuck off in string!");

    Printer<char*> ch;
    ch.print("Fuck off in char!"); // не будет выполнено!

    Printer<int> num;
    num.print(66);

    Printer<double> db;
    db.print(56.23);


    return 0;
}


