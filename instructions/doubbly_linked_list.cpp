/// Программа добавляет число в список, удаляет число из списка, и выводит список на экран
#include "iostream"
#include "string"
using namespace std;

struct Node{
    int d;
    Node *next;
    Node *prev;
};
Node *first(int d, int i);
void add(Node **pend, int d);
Node *find(Node * const pbeg, int d);
int remove(Node **pbeg, Node **pend, int key);
Node *insert(Node* const pbeg, Node **pend, int key, int d);
void add_sort(Node **pbeg, Node **pend, int d);

int main(){
    Node *pbeg = first(1, 0); // формирование первого элемента списка
    Node *pend = pbeg;   // список заканчиваетс едва начавшись

    for(int i = 2; i < 6; i++) add(&pend, i); // добавление в конец списка четырех элементов

    insert(pbeg, &pend, 2, 200);

    if(!remove(&pbeg, &pend, 5)) cout << "Element 5 wasn't found" << endl;

    Node *pv = pbeg;                // вывод списка на экран
    while(pv){
        cout << pv->d << " ";
        pv = pv->next;
    }
    return 0;
}
// Формирование первого элемента:
Node *first(int d, int i) {
    Node *pv = new Node;
    pv->d = d;
    pv->next = 0;
    pv->prev = 0;
    return pv;
}
// добавление элемента в конец списка:
void add(Node **pend, int d){
    Node *pv = new Node;
    pv->d = d;
    pv->next = 0;
    pv->prev = *pend;
    (*pend)->next = pv;
    *pend = pv;
}
// Поиск элемента по ключу:
Node *find(Node * const pbeg, int d){
    Node *pv = pbeg;
    while (pv){
        if(pv->d == d) break;
        pv = pv->next;
    }
    return pv;
}
// Удаление элемента:
int remove(Node **pbeg, Node **pend, int key){
    Node *pkey = find(*pbeg, key);
    if (pkey){
        if(pkey == *pbeg){
            *pbeg = (*pbeg)->next;
            (*pbeg)->prev = 0;
        } else{
            if (pkey == *pend){
                *pend = (*pend)->prev;
                (*pend)->next = 0;
            } else{
                (pkey->prev)->next = pkey->next;
                (pkey->next)->prev = pkey->prev;
            }
        }
        delete pkey;
        return 1;
    }
}
// Вставка элемента d после индекса key
Node *insert(Node* const pbeg, Node **pend, int key, int d){
    Node *pkey = find(pbeg, key);
    if(pkey){
        Node *pv = new Node;
        pv->d = d;
        pv->next = pkey->next;  // установление связи нового узла с последующим
        pv->prev = pkey;        // установление связи нового узла с предыдущим
        pkey->next = pv;        // установление связи предыдущего узла с новым
        if(pkey != *pend){
            (pv->next)->prev = pv;// установление связи последующего узла с новым
        } else{
            *pend = pv; // обновление указателя на конец списка если узел вставляется в конец
        }
        return pv;
    }
    return 0;
}
void add_sort(Node **pbeg, Node **pend, int d){
    Node *pv = new Node;
    pv->d = d;
    Node * pt = *pbeg;
    while (pt){
        if (d<pt->d){  // занести перед текущим элементом (pt)
            pv->next = pt;
            if(pt == *pbeg){  //  в начало списка
                pv->prev = 0;
                *pbeg = pv;
            } else{       // в середину списка
                (pt->prev)->next = pv;
                pv->prev = pt->prev;
            }
            pt->prev = pv;
            return;
        }
        pt = pt->next;
    }
    pv->next = 0;   // в конец списка
    pv->prev = *pend;
    (*pend)->next = pv;
    *pend = pv;
}