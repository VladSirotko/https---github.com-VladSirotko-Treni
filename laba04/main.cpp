#include <iostream>
#include <stdlib.h>
#include "Fnames.h"
using namespace std;



int main()
{

    List a;
    List b;

    int n;
    system("CLS");
    cin>>n;
    cout<<endl;
    for (int i=0; i<n; i++)
        a.Add(rand()%14);

    for (int i=0; i<n; i++)
        b.Add(rand()%14);

    a.Show();
    b.Show();
    a.Pyanica(a,b);
    a.Show(a,b);
    return 0;
}
