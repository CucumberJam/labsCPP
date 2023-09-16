#include <guiddef.h>
#include <windows.h>
using namespace std;

class Point{
    int x, y;
    Point(int x, int y){
        this->x = x;
        this->y = y;
    }
    Point(): x(0), y(0) {}
};
bool operator==(Point a, Point b) {
    return a.x==b.x && a.y==b.y;
}
bool operator!=(Point a, Point b){
    return !(a==b);
}
struct Line{
    Line(Point p1, Point p2);  // создаем объект класса Line  из двух объектов класса Points
};
int main(void){
    Simple_window win1
}