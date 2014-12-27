#include "name.hpp"
#include <cmath>
#include <algorithm>

void Polynom::CalculateValue(double x=1.0)//TODO функцыя павінна рабіць толькі адно дзеянне, а вылічэнне і вывад на экран гэта 2 дзеянні
{ int s=Poly[n-1];

 for(int i=n-2;i>=0;i--)
    s=s+Poly[i]*pow(x,i);
return s;
}


Polynom::Polynom(int k)
{
    n=k;
    Poly = new int[n];
    for(int i = 0; i < n; i++)
    {
        Poly[i] = 0;
    }
}
Polynom::Polynom(const Polynom & rhs)
{
    n = rhs.n;
    Poly = new int[n];
    for(int i = 0; i < n; i++)
    {
        Poly[i] = rhs[i];
    }
}
Polynom::~Polynom()
{
    n = 0;
    delete [] Poly;

}

Polynom Polynom::operator*(double x) const
{
    Polynom a(n);
    for(int i = 0; i < n; i++)
    {
        a[i] = Poly[i] * x;
    }
    return a;
}

Polynom & Polynom::operator=(const Polynom & rhs)
{
    if (this != &rhs)
    {
        delete [] Poly;
        n = rhs.n;
        Poly = new int[n+1];
        for(int i = 0; i <=n; i++)
        {
            Poly[i] = rhs[i];
        }
    }
    return *this;
}
Polynom Polynom::operator+(const Polynom & rhs) const//TODO аналагічна
{   int k=std::max(n,rhs.n);
    Polynom sum(k);
    for(int i = 0; i <rhs.n; i++)
    {
        sum[i] += rhs[i];
    }
    for(int i = 0; i <n; i++)
    {
        sum[i] += Poly[i];
    }

   
 return sum;
}
Polynom Polynom::operator-(const Polynom & rhs) const//TODO аналагічна
{   int k=std::max(n,rhs.n);
    Polynom dif(k);
    for(int i = 0; i <rhs.n; i++)
    {
        dif[i] -=  rhs[i];
    }
    for(int i = 0; i <n; i++)
    {
        dif[i] += Poly[i];
    }
    

    return dif;

}

ostream & operator<<(ostream & mystream, const Polynom &rhs)
{ int k=rhs.SizeOfPoly();
    if(k)
    {
          mystream<<'('<<rhs[0]<<")x^"<<k-1;

        for(int l=k-2, i = 1; i<k; i++,l--)
        {
      mystream<<"+("<<rhs[i]<<")x^"<<l;

        }

    }
    return mystream;
}

istream & operator>>(istream & mystream, Polynom &rhs)
{
    cout<<"Put "<< rhs.SizeOfPoly() << " coefficients:"<<endl;
    for (int i = 0; i < rhs.SizeOfPoly(); i++)
    {
        mystream>>rhs[i];
    }
    return mystream;
}

Polynom operator*(double x, const Polynom & rhs)
{
    return rhs * x;
}
