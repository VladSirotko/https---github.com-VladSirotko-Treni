#include <iostream>
#include "Fnames.h"

using namespace std;
class List
{
private:

    struct Node
    {
        int x;
        Node *Next;
    };
 Node *Head, *Tail;
public:

    List(): Head(nullptr), Tail(nullptr) {};
    ~List();
    List(const List & rhs );

    List & operator=(const List & rhs);
    void Add(int x);
    void Show(List &ob1, List &ob2);
    void del();
    void Pyanica(List &ob1, List &ob2);


};

List & List::operator=(const List & rhs)
{
    del();
    Node *p=rhs.Head;
    while(p)
    {
        Add(p->x);
        p=p->Next;
    }
    return *this;
}
List::List(const List & rhs )
{
    Node *p=rhs.Head;
    while(p)
    {
        Add(p->x);
        p=p->Next;
    }
}

List::~List()
{
    while(Head)
    {
        del();
    }
}

void List::Pyanica(List &ob1, List &ob2)
{
    int k = 0;
    int l = 0;
    List ob3;
    while(ob1.Head && ob2.Head)
    {
        k=ob1.Head->x;
        l=ob2.Head->x;
        if  (k>l)
        {
            ob1.Add(l);
            ob1.Add(k);
            ob1.del();
            ob2.del();


            while(ob3.Head)
            {
                Node *card = ob3.Head;
                ob1.Add(card->x);
                card = card->Next;
                ob3.del();
            }
        }
        else if(k<l)
        {
            ob2.Add(k);
            ob2.Add(l);
            ob2.del();
            ob1.del();


            while(ob3.Head)
            {
                Node *card = ob3.Head;
                ob2.Add(card->x);
                card = card->Next;
                ob3.del();
            }
        }
        else
        {
            ob3.Add(k);
            ob3.Add(l);
            ob1.del();
            ob2.del();
        }
    }
};


void List::Add(int x)
{
    Node *temp=new Node;
    temp->x=x;
    temp->Next=nullptr;

    if (Head)
    {
        Tail->Next=temp;
        Tail=temp;
    }
    else Head=Tail=temp;
}


void List::Show()
{
    Node *temp=Head;
    while (temp)
    {
        cout<<temp->x<<" ";
        temp=temp->Next;
    }

    cout<<endl<<endl;

}
void List::Show(List &ob1, List &ob2)

{
    if (ob1.Head) ob1.Show();
    else ob2.Show();

}

void List::del()
{
    if (Head)
    {
        Node *temp=Head;

        Head=Head->Next;
        delete temp;
    }
}




