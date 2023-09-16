#include "iostream"
#include "vector"
using namespace std;

/// ���������� �����-�� �������� (STL) - ����� ����������� ������� ��� ������������� � ������ �������
/// VECTOR

int main(){
    vector<int> myVector; // ������������ ������ c ����������� ��������� ���������� ������ (��������) � ��
    myVector.push_back(10);
    myVector.push_back(99);
    myVector.push_back(3);
    // emplace_back() ��������� ����������� ������ - ��������� ������� � ����� ����������:
    myVector.emplace_back(800);

    vector<int> myVector2(10); // ������ ��������������� �������� �� ��������� 10 ����������

    vector<int> myVector3(myVector);
    vector<int> myVector4 = myVector2;
    vector<int> myVector5(5, 6); // ������ v5 ������� �� 5 �����, ������ ����� ����� 6
    vector<int> myVector6{6, 6, 6, 6};
    vector<int> myVector7 = {1,2,3,4,5};

    // ���������� ��������� �� ������������ �������:
    // emplace(pos, value): ��������� ������� value �� �������, �� ������� ��������� �������� pos
    auto it7 = myVector7.begin();
    advance(it7,2);
    myVector7.emplace(it7,666);
    myVector7.insert(++it7, 777);
    myVector7.insert(++it7, 5, 33); // ��������� n ��������� value ������� � �������, �� ������� ��������� �������� pos
    myVector7.insert(it7+=5, myVector6.begin(),myVector6.end()); // ��������� ������� � �������, �� ������� ��������� �������� pos, �������� �� ������� ���������� �� ��������� ����� ����������� begin � end
    auto last7 = myVector7.end();
    // ������� ������� �� �������� ��� ������ ����������, ����������� ������� std::erase()
    myVector7.erase(it7); // ������� �������, �� ������� ��������� �������� p. ���������� �������� �� �������, ��������� ����� ����������, ��� �� ����� ����������, ���� ������ ��������� �������
    myVector7.erase(it7, last7); // ������� �������� �� ���������, �� ������ � ����� �������� ��������� ��������� begin � end.




    cout << "Array's size " << myVector.size() << endl;
    cout << "Array: " << endl;
    for(int num: myVector){
        cout << num << endl;
    }
    int first = myVector.front();
    int last = myVector.back();
    int second = myVector[2];
    cout << "myVector.front(): "<< first << endl;
    cout << "myVector.back(): " << last << endl;
    cout << "myVector[2]: " << second << endl;
    // �������� ����� ��������:
    myVector[0] = 1000;
    cout << "Array after changing first element: " << endl;
    for(int num: myVector){
        cout << num << "\t";
    }
    myVector.pop_back(); // ������� ��������� �������
    cout << "Array after pop_back(): " << endl;
    for(int num: myVector){
        cout << num << endl;
    }

    // ����� �� ������� ������� ���� �� �������� ����� �������� []:
    cout << "Array beyond means: " << endl;
    cout << myVector[10] << endl;

    // ���� �� �������� ����� .at(index) �� ��������� � �� ���� ����� �� ������� �������:
    cout << "Array at(1): " << endl;
    cout << myVector.at(1) << endl; // �� �������� ��� []
    // ��������:
    try{
        cout << myVector.at(10) << endl;
    }catch (const std::out_of_range & ex){
        cout << ex.what() << endl;
    }

    cout << "Array's capacity " <<  myVector.capacity()<< endl;
    myVector.reserve(100);
    cout << "Array's capacity after reserve(100) " <<  myVector.capacity()<< endl;
    myVector.shrink_to_fit();
    cout << "Array's shrink_to_fit() " << endl;
    cout << "Array's capacity " <<  myVector.capacity()<< endl;
    cout << "Array's size " << myVector.size() << endl;

    cout << "Array's empty? " <<     myVector.empty() << endl;
    myVector.clear();
    cout << "Array's size after clear " << myVector.size() << endl;
    cout << "Array's empty? " <<     myVector.empty() << endl;

    myVector.resize(20,555); // �������������� 20 ��������� �� 555 � ������
    cout << "Array's after resize(20,555) " <<     myVector.empty() << endl;
    for(int num: myVector){
        cout << num << endl;
    }


    return 0;
}