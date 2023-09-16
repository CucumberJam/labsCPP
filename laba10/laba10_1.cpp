#include "iostream"
#include "string"
using namespace std;

struct Node{
    int d;
    Node *next;
    Node(int d=(0), Node *pNext = nullptr){
        this->d = d;
        this->next = pNext;
    }
};
Node *first(int d);
void add(Node **pend, int d);
Node *find(Node * const pbeg, int d);
int remove(Node **pbeg, Node **pend, int key);
Node *insert(Node* const pbeg, Node **pend, int key, int d);
void add_sort(Node **pbeg, Node **pend, int d);
void showList(Node **pbeg, Node **pend);
void showNode(Node **pbeg);

int main(){
    Node *pbeg = first(1); // ������������ ������� �������� ������
    Node *pend = pbeg;   // ������ ������������ ���� ���������

    for(int i = 2; i < 6; i++) { // ���������� � ����� ������ ������� ���������
        add(&pend, i);
    }
    showList(&pbeg, &pend);

    Node *findNode = find(pbeg, 3);
    showNode(&findNode);

    remove(&pbeg, &pend, 4);
    showList(&pbeg, &pend);

    Node *insertNode = insert(pbeg, &pend, 1, 111);
    cout << endl;
    cout << "After insert(1, 111): ";
    showList(&pbeg,&pend);
    insertNode = insert(pbeg, &pend, 5, 222);
    cout << endl;
    cout << "After insert(5, 222): ";
    showList(&pbeg,&pend);
    insertNode = insert(pbeg, &pend, 2, 333);
    cout << endl;
    cout << "After insert(2, 333): ";
    showList(&pbeg,&pend);

    add_sort(&pbeg, &pend, 198);
    cout << endl;
    cout << "After add_sort(198): ";
    showList(&pbeg,&pend);

    return 0;
}
Node *first(int d) { // ������������ ������� ��������:
    Node *pv = new Node;
    pv->d = d;
    pv->next = 0;
    return pv;
}
void add(Node **pend, int d){  // ���������� �������� � ����� ������:
    Node *pv = new Node;
    pv->d = d;
    (*pend)->next = pv;
    *pend = pv;
    pv->next = 0;
}
Node *find(Node * const pbeg, int d){  // ����� �������� �� �����:
    Node *pv = pbeg;
    while (pv){
        if(pv->d == d) break;
        pv = pv->next;
    }
    return pv;
}
int remove(Node **pbeg, Node **pend, int key){  // �������� ��������:
    Node *pkey = find(*pbeg, key);
    if (pkey){
        if(pkey == *pbeg){
            *pbeg = (*pbeg)->next;
           // (*pbeg)->prev = 0;
        } else{
            if (pkey == *pend){
                *pend = find(*pbeg, key-1);
                (*pend)->next = 0;
            } else{
                (find(*pbeg, key-1))->next = pkey->next;
               // (pkey->next)->prev = pkey->prev;
            }
        }
        delete pkey;
        return 1;
    }
}
Node *insert(Node* const pbeg, Node **pend, int key, int d){// ������� �������� d ����� ������� key
    Node *pkey = find(pbeg, key);
    if(pkey){
        Node *pv = new Node;
        pv->d = d;
        pv->next = pkey->next;  // ������������ ����� ������ ���� � �����������
        pkey->next = pv;        // ������������ ����� ����������� ���� � �����
        if(pkey == *pend){
            *pend = pv; // ���������� ��������� �� ����� ������ ���� ���� ����������� � �����
        }
        return pv;
    }
    return 0;
}
void add_sort(Node **pbeg, Node **pend, int d){
    Node *pv = new Node;
    pv->d = d;
    Node * pt = *pbeg;
    Node * pr = *pbeg;
    while (pt){
        if (d<pt->d){  // ������� ����� ������� ��������� (pt)
            pv->next = pt;
            if(pt == *pbeg){  //  � ������ ������
               // pv->prev = 0;
                *pbeg = pv;
            } else{       // � �������� ������
                pr->next = pv;
            }
            return;
        }
        pr = pt;
        pt = pt->next;
    }
    pv->next = 0;   // � ����� ������
    (*pend)->next = pv;
    *pend = pv;
}
void showList(Node **pbeg, Node **pend){    //    Node *pv = pbeg;                // ����� ������ �� �����
    Node * pb = *pbeg;                  //    while(pv){
    Node * pe = *pend;                  //        cout << pv->d << " ";
    cout << endl;
    cout << "List: " << endl;           //        pv = pv->next;
    do{                                 //    }
        cout << pb->d << " ";
        pb = pb->next;
    }while(pb!=pe);
    cout << pb->d << " ";
}
void showNode(Node **pbeg){
    Node * pb = *pbeg;
    cout << endl;
    cout << "Node's key is: " << pb->d;
}
// �� ��������� ����������� ��������� ��� ����������� ������ �������� ����������� �� �����������
// ��������� ��������� ��� ������������ �����