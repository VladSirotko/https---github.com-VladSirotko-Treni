
#include <iostream>
class Polynom
{
    int *Poly;
    int n;
public:
    Polynom() : Poly(), n(0) {}

    Polynom(int n);

    Polynom(const Polynom & rhs);

    ~Polynom();

    Polynom & operator=(const Polynom & rhs);

    Polynom operator+(const Polynom & rhs) const;

    Polynom operator-(const Polynom & rhs) const;


    Polynom operator*(double x) const;

    Polynom operator*(const Polynom & rhs) const;

    int & operator[](int i) const {return Poly[i];}

    int SizeOfPoly() const {return n;}

    void CalculateValue(double x);

    friend std::ostream & operator<<(std::ostream & mystream, const Polynom &rhs);

    friend std::istream & operator>>(std::istream & mystream, Polynom &rhs);
    friend Polynom operator*(double x, const Polynom & rhs);




};