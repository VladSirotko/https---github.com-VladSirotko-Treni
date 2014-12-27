#include "PrettyConsoleList.h"

PrettyConsoleList::PrettyConsoleList() : ConsoleList()
{
}

PrettyConsoleList::~PrettyConsoleList()
{
}

void PrettyConsoleList::newShow() const
{

    Node *temp=Head;
    while (temp)
    {
        cout<<temp->x<<" <- ";
        temp=temp->Next;
    }

    cout<<endl<<endl;

}
