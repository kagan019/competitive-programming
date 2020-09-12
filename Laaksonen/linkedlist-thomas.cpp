#include <iostream>

using namespace std;



// Satisfy this:
class Indexable {
    virtual void insert(int)=0;
    virtual int get(int)=0; 
};

class MyLinkedList : Indexable // technically a stack
{
public:
    struct Node
    {
        const Node *next;
        int num;    
    };

    Node head;
    int size;
    MyLinkedList() : size(0), head({nullptr, 0}) {};
    void insert(int m) 
    {
        head.next = new Node{head.next, m};
        size++;
    };
    int get(int i) {
        if (i >= size || i < 0) return -1;
        const Node *cur = head.next;
        for (int i_=0; i_<i;i_++) {
            cur = cur->next;
        }
        return cur->num;
    };
};

int main() {
    int n;
    MyLinkedList mll;
    cin >> n;
    int i = 0;
    while (i < n) {
        int k;
        cin >> k;
        mll.insert(k);
        i++;
    }
    for (int i = 0; i < mll.size; i++)
        cout << mll.get(i) << " ";
}