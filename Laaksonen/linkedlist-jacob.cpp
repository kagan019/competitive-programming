#include <iostream>
#include <limits>

using namespace std;
struct Node
{
    Node *next;
	int value;
//    Node(int m): value(m)
//	{
//	}
};
class MyLinkedList
{
	private:
		Node *head, *tail;
		int tsize;
	public:
		MyLinkedList()
		{
			head = NULL;
			tail = NULL;
			tsize = 0;
		}

		// added to the head part
		void addtolist(int m)
		{
			Node *temp = new Node;
			temp-> value = m;
			temp-> next = NULL;
			if (head ==NULL)
			{
				head = temp;
				tail = temp;
				temp = NULL;
				tsize = 1;
			}
			else
			{
				tail-> next = temp;
				tail=temp;
				tsize = tsize +1;
			}
		}

		int get(int m)
		{
			if(m > tsize)
			{
				return -1;
			}
			else
			{
				Node *temp = head;
				for(int i = 0; i< m; i++)
				{
					temp= temp-> next;
				}
				return temp->value;
			}
		}
		int size()
		{
			return tsize;
		}
};



int main() {
    int n;
    MyLinkedList mll;
    cin >> n;
    int i = 0;
    while (i < n) {
        int k;
        cin >> k;
        mll.addtolist(k);
        i++;
    }
    for (int i = 0; i < mll.size(); i++)
        cout << mll.get(i);
}
