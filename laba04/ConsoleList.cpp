#include "ConsoleList.h"

ConsoleList::ConsoleList() : List()
{
}


ConsoleList::~ConsoleList()
{
}

void ConsoleList::newShow()
{
  List a;
    Node *temp=a.Head;
    while (temp)
    {
        cout<<temp->x<<" <- ";
        temp=temp->Next;
    }

}
