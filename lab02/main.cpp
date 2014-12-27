#include <iostream>
#include "name.h"
using namespace std;


int main()
{   double u;
    cout<<"Put size of Polynoms:  "<<endl;
    cin>>u;
    Polynom x(u);
    Polynom y(u);
    cin>>x;
    cin>>y;
    cout<<x<<endl;
    cout<<y<<endl;
    cout<<"Sum of Polynoms:"<<endl;
    cout<<x+y<<endl;
    cout<<"Difference of Polynoms:"<<endl;
    cout<<x-y<<endl;
    cout<<"Multiplication number on Polynom"<<endl;
    cout<<2.0*x<<endl;
    cout<<"Multiplication Polynom on number"<<endl;
    cout<<y*2.0<<endl;
    cout<<"Value of Poly: "<<endl;
    x.CalculateValue();
    return 0;
}
