#include <vector>
#include "iostream"
using namespace std;
///auto - разрешает компилятору самому догадаться какой тип данных будет

int main(){

    auto a = 4;
    auto b = 2.45;
    auto c = "string"; // будет массив типа char
    auto d = true;

    vector<int> myVector = {11,46,9};
    auto it = myVector.begin();

    return 0;
}
