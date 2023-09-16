#include <iostream>
#include <string>
#include <fstream>
#include <windows.h>
using namespace std;
/// перегрузка операторов потокового ввода вывода << >>

class Point{
public:
    Point(){
        x=y=z=0;
    }
    Point(int x, int y, int z){
        this->x = x;
        this->y = y;
        this->z = z;
    }
//    void print(){
//        cout << "X^ " << x << "\tY: " << y << "\tZ: " << z << endl;
//    }
int getX() const {
        return x;
    }
    int getX()  {
        return x;
    }
    int getY() const {
        return y;
    }
    int getY() {
        return y;
    }
    int getZ() const {
        return z;
    }
    int getZ() {
        return z;
    }
private:
    int x;
    int y;
    int z;

    friend ostream& operator<<(ostream& os, const Point& point);
    friend istream& operator>>(istream& is, Point& point);
};
ostream& operator<<(ostream& os, const Point& point){ //перегружаем метод вывода путем передачи ссылки базовому классу на проиводный и на объект
    os<< point.x << " " << point.y << " " << point.z;
    return os;
}
istream& operator>>(istream& is, Point& point){ //перегружаем метод ввода путем передачи ссылки базовому классу на проиводный и на объект
    is >> point.x >>point.y >> point.z;
    return is;
}

int main(){

    Point p(534, 46, 89);
//    cout << p;

    string path = "overloadingFileInputOutput.txt";
    fstream fs;
    fs.open(path, fstream:: in | fstream:: out | fstream:: app);

    if(!fs.is_open()){
        cout << "Error while opening." << endl;
    } else {
        cout << " File is opened!" << endl;
//        fs << p << "\n";
        while (true) {
            Point point;
            fs >> point;
            if(fs.eof()){
                break;
            }
            cout << point << endl;
        }
    }
    fs.close();
    return 0;
}