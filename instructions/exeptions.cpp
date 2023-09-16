#include "iostream"
#include "string"
#include "fstream"

using namespace std;

/// Создание исключений
class Myexception: public exception{
public:
    Myexception(char &msg, int datastate){
        this->dataState = datastate;
    }
    int getDataState(){
        return dataState;
    }
private:
    int dataState;
};
void foo(int value){
    if(value<0){
        Myexception myex((char &) "Number is less than 0", -1);
        throw exception(myex);
    }
    if(value == 1){
        throw Myexception((char &)"The number is 1", 1);
    }
    cout << "Value is: " << value << endl;
}
int main(){
    setlocale(LC_ALL, "ru");

    try {
        foo(1);
    }catch (Myexception &ex){
        cout << "We catched Myexception exception: " << ex.what() << endl;
        cout << "State of data: " << ex.getDataState() << endl;
    }
    catch (const char &ex){
        cout << "We catched char exception:" << ex << endl;
    }
    catch (exception &ex){
    cout << "We catched general exception: " << ex.what() << endl;
    }
    catch (...) {
    }

    string path = "exception_file.txt";
    ifstream fin;
    fin.exceptions(ifstream::badbit | ifstream::failbit);

    try{
        cout << "Attempt to open the file." << endl;
        fin.open(path);
        cout << "File was opened!" << endl;
    }
    catch(const ifstream::failure &ex) {
        cout << ex.what() << endl;
        cout << ex.code() << endl;
        cout << "Error while opening file!" << endl;
    }


    return 0;
}