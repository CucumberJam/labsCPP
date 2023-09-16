#include "iostream"
#include "string"
#include "fstream"
using namespace std;
/// enum

enum PCState{
    OFF,
    ON,
    SLEEP
};

class PC{
public:
    void setState(PCState state){
        this->state = state;
    }
    PCState getState(){
        return state;
    }
private:
    PCState state;
};

int main(){
    setlocale(LC_ALL, "ru");

    PC pc;
    pc.setState(PCState::SLEEP);

    if (pc.getState() == PCState::ON){
        cout << "PC is working!" << endl;
    }
    switch (pc.getState()) {
        case PCState::OFF:
            cout << "PC is turned off." << endl;
            break;
        case PCState::ON:
            cout << "PC is working!" << endl;
            break;
        case PCState::SLEEP:
            cout << "PC is sleeping!" << endl;
            break;
    }


    return 0;
}