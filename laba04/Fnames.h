#ifndef FNAMES_H_INCLUDED
#define FNAMES_H_INCLUDED



class ListIntInt
{
private:
    ListInt *pimpl;

public:

    ListIntInt(): Head(nullptr), Tail(nullptr) {};
    ~ListIntInt();
    ListIntInt(const ListIntInt & rhs );

    ListIntInt & operator=(const ListIntInt & rhs);
    void Add(int x);
    void Show();
    void Show(ListIntInt &ob1, ListIntInt &ob2);
    void del();
    void Pyanica(ListIntInt &ob1, ListIntInt &ob2);


};

#endif // FNAMES_H_INCLUDED

ListInt::ListInt():pimpl(nullptr)
{
    pimpl = new List();
}

ListInt::~ListInt()
{
    delete pimpl;
}

void ListInt::Add(int x)
{
    pimpl->Add(x.pimpl);
}
void ListInt::del()
{
    pimpl->del();
}
void ListInt::Show()
{
    pimpl-> Show();
}

void ListInt::Show(ListInt& obj1,ListInt& obj2)
{
    pimpl->Show(obj1.pimple,obj2.pimple);
}
void ListInt::Pyanica(ListInt& ob1,ListInt& ob2)
{
    pimpl->Pyanica(ob1.pimple,ob2.pimple);
}
