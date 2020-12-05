#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

struct Node
{
    int x;
    Node *Next;
};

class List
{
    Node *Head;
    int size;
public:
    List() {Head = nullptr, size = 0;}
    ~List();
    void Add(int x);
    void Show();
    void Pop(int N);
    void reverse();
};

List::~List()
{
    while (Head != nullptr)
    {
        Node *temp = Head->Next;
        delete Head;
        Head = temp;
    }
}

void List::Add(int x)
{
    auto *temp = new Node;
    temp->x = x;
    temp->Next = Head;
    Head = temp;
    size++;

}

void List::Show()
{
    Node *temp=Head;

    while (temp != nullptr)
    {
        cout << temp->x << " ";
        temp = temp->Next;
    }
}

void List::Pop(const int N)
{
    Node *temp = Head;
    if ((Head != nullptr) && (N < size))
    {
        for (int i=0; i<N; i++) temp = temp->Next;
        cout << temp-> x << " " << endl;
    }
    cout << endl;
}

void List::reverse(){
    Node*headNew = nullptr;
    for(Node * pos = Head; pos;){
        Node*nextNew = pos->Next;
        pos->Next = headNew;
        headNew = pos;
        pos = nextNew;
    }
    Head = headNew;
}

int main()
{
    int N;
    int x;
    List lst;

    cout << "N = ";
    cin >> N;

    for (int i=0; i<N; i++)
    {
        cout << i+1 << ". x = ";
        cin >> x;
        lst.Add(x);
    }

    lst.Show();
    lst.reverse();
    lst.Show();
    return 0;
}
