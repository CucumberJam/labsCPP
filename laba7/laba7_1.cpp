
#include <string>
#include <iostream>
#include "graphics.h"
#include <ctime>
#include <cmath>
#include <unistd.h>

using namespace std;
class Point{
protected:
    int x;
    int y;
    string color;

public:
    Point(){
        x = y = 0;
        color = "";
    }
    Point(int x, int y, string color){
        this->x = x;
        this->y = y;
        this->color = color;
    }
    void setPoint(int x, int y, string color){
        this->x = x;
        this->y = y;
        this->color = color;
    }

    virtual void show() = 0;
    virtual void hide() = 0;
    void locat(int x, int y){
        this->x = x;
        this->y = y;
    }
    void fly(int xx, int yy){
        cout << xx << " " << yy << endl;
        char ex;
        do {
            srand(time(0));
            locat(xx, yy);
            do{
               xx = xx + round((double)rand() /RAND_MAX * 0.5);
            }while(!(xx >0) && (xx < getmaxx()));
            do{
                yy = yy + round((double)rand() /RAND_MAX * 0.5);
            }while(!(yy >0) && (yy < getmaxx()));
            hide();
            this->x = xx;
            this->y = yy;
            cout << xx << " " << yy << endl;
            sleep(300);
            cout << "For exit press 'z': " << endl;
            cin >> ex;
        } while(!ex=='z');
    }
};
class Krug: public Point{
protected:
    string radius;
public:
    Krug(): Point(){
        radius = "";
    }
    Krug(int x, int y, string color, string radius): Point(x, y, color){
        this->radius=radius;
        printf("Krug was created. x: %d, y: %d, color: %s, radius: %s\n", x, y, color.c_str(), radius.c_str());
    }
    virtual void show(){
        setColor(color);
        setfillstyle(1, stoi(color));
        pieslice(x,y, 0, 320, stoi(radius));
    };
    virtual void hide() {
        setColor(reinterpret_cast<const char *>(getbkcolor()));
        setfillstyle(1, getbkcolor());
        pieslice(x, y, 0, 320, stoi(radius));
    }

    void setColor(string color){
        this->color = color;
    }
};
class Ring: public Krug{
private:
    string width;
public:
    Ring():Krug(){
        width = "";
    }
    Ring(int x, int y, string color, string radius, string width): Krug(x,y,color,radius){
        this->width = width;
    }
    void setRing(string width){
        this->width = width;
        Krug krug = Krug(x, y, radius, color);
    }

    virtual void show(){
        Krug::show();
        setfillstyle(10, getbkcolor());
        pieslice(x, y, 90, 320, stoi(radius) - stoi(width));
    };
};

int main(void) {
    int d, r;
    Krug testKrug = Krug();
    Ring testRing = Ring(450, 80, "90", "50", "10");
    d = initgraph(&d, &r, " ");
    setcolor(80);
    // здесь должна быть инициализация круга (150, 40, 50, 1);
    // testRing.cring

    return 0;
}


// int gd = DETECT, gm;
//    initgraph(&gd, &gm, (char*)"");