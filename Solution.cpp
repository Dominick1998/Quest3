/*
Quest-3 for Prof Alex Jaeger
Dominick Ferro
Programming ll
4/21/2020
*/

/*
Reduces fractions through 
multiplication, division, 
addition, and subtraction.
*/

//header file
#include <iostream>
using namespace std;

//class named fraction
class Fraction
{

//private fields numerator and denominator
private:
   int numerator;
   int denominator;
   
//public classes for rational fractions(num and den)
public:
   Fraction();
   Fraction(int n,int d);
   int getNumerator();
   void setNumerator(int n);
   void setDenominator(int d);
   int getDenominator();
   friend istream& operator>>(istream &input,Fraction &fract);
   friend ostream& operator<< (ostream& output, const Fraction& fract);
   Fraction operator+(const Fraction & other);
   Fraction operator-(const Fraction & other);
   Fraction operator*(const Fraction & other);
   Fraction operator/(const Fraction & other);
   bool operator==(const Fraction & other);
};

//default constructor
Fraction::Fraction()
{

}

//constructor setting numerator and denominator.
Fraction::Fraction(int n,int d)
{
   numerator=n;
   denominator=d;
}

//mutators and accessor(return value and set priority).
int Fraction::getNumerator()
{
   return numerator;
}
void Fraction::setNumerator(int n)
{
   numerator=n;
}
int Fraction::getDenominator()
{
   return denominator;
}
void Fraction::setDenominator(int d)
{
   denominator=d;
}

//operator class used for input
istream& operator>>(istream &input,Fraction &fract)
{
   cout<<"Enter Numerator :";
   input>>fract.numerator;
   cout<<"Enter Denominator :";
   input>>fract.denominator;

}

//operator class used for output
ostream& operator<< (ostream& output, const Fraction& fract)
{
   output<<fract.numerator;
   output<<"/";
   output<<fract.denominator;
}

//fraction addition
Fraction Fraction::operator+(const Fraction & other)
{
   Fraction add((numerator * other.denominator + other.numerator * denominator)
           ,(denominator * other.denominator));
   return add;
}

//fraction subtraction
Fraction Fraction::operator-(const Fraction & other)
{
   Fraction sub((numerator * other.denominator - other.numerator * denominator)
           ,(denominator * other.denominator));
   return sub;
}

//fraction multiplication
Fraction Fraction::operator*(const Fraction & other)
{
   Fraction mul((numerator * other.numerator)
           ,(denominator * other.denominator));
   return mul;
}

//fraction division 
Fraction Fraction::operator/(const Fraction & other)
{
   Fraction div((numerator * other.denominator)
           ,(denominator * other.numerator));
   return div;
}

//if n = opposite n, d = opposite d return bool value
bool Fraction::operator==(const Fraction & other)
{
   if(numerator == other.numerator && denominator == other.denominator)
   return true;
   else
   return false;
}

//fractions are asked for
int main() {

   Fraction f1, f2;
   cout << "Enter Left Fraction\n";
   cin >> f1;
   cout << "\nEnter Right Fraction\n";
   cin >> f2;

   //result is calculated
   Fraction addResult = f1 + f2;
   cout << "\nAddition Result: " << addResult << endl;

   Fraction subResult = f1 - f2;
   cout << "\nSubstraction Result: " << subResult << endl;

   Fraction mulResult = f1 * f2;
   cout << "\nMultiplication Result: " << mulResult << endl;

   Fraction divResult = f1 / f2;
   cout << "\nDivistion Result: " << divResult << endl;

   //end of code
   return 0;
}
