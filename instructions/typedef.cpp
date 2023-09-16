#include "iostream"
#include "vector"

/// typedef - для того чтобы присваивать каким то определенным типам данных опред-ый псевдоним
typedef std::vector<int> int_vector;
typedef std::vector<float> fl_vector;

int main(){
    std::vector<int> myVector;
    int_vector myVector2;
    fl_vector myVector3;
    myVector.capacity();



    return 0;
}