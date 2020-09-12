#include <iostream>

using namespace std;

class StackMap
{
public:
    struct Node
    {
        const Node *next;
        int id;
        int value;    
    };

    Node head;
    int size;
    StackMap() : size(0), head({nullptr, 0}) {};
    ~StackMap() {
        const Node *cur = head.next;
        const Node *x;
        while(cur) {
            x = cur->next;
            delete cur;
            cur = x;
        }
    }
    void insert(int k, int v) 
    {
        head.next = new Node{head.next, k, v};
        size++;
    };
    int get(int id) {
        if (id < 0) return -1;
        const Node *cur = head.next;
        while (cur) {
            if (id == cur->id)
                return cur->value;
            cur = cur->next;
        }
        return -1;
    };
};

class Hashmap {
public:
    const int size;
    StackMap *elems;
    Hashmap(int s) : size(s), elems() {
        elems = new StackMap[s];
        for (int i =0; i<s; i++) {
            elems[i] = StackMap();
        }
    };
    ~Hashmap() {
        delete [] elems;
    }
    int hash(int id) {
        return id % size; 
    };
    int get(int id) {
        if (id < 0) return -1;
        int i = hash(id);
        return elems[i].get(id);
    };
    void insert(int id, int v) {
        if (id < 0) return;
        int i = hash(id);
        elems[i].insert(id, v);
    };
};

int main() {
    int n;
    Hashmap hm(20);
    cin >> n;
    int i = 0;
    int keys[n];
    while (i < n) {
        int k, v;
        cin >> k >> v;
        keys[i] = k;
        hm.insert(k, v);
        i++;
    }
    for (int i = 0; i < n; i++)
        cout << hm.get(keys[i]) << " ";
}