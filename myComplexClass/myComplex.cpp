/*
   COPYRIGHT (C) 2018 Patrick M. Howard (pmh41) All rights reserved.
   CSII assignment B
   Author.  Patrick M. Howard
            pmh41@zips.uakron.edu
   Version. 1.12 09.24.2018
   Purpose: This program is the test cases for the assignment
*/

#include <iostream>
#include <string>
#include <sstream> // for ostringstream class


class Complex
{
  public:

    //Default constructor. Sets the object to zero.
    Complex();

    //Constructor used for setting up exact values
    Complex(double&, double&);

    //Pre:  Takes in a single complex object.
    //Post: Returns a complex number that is the sum of the two inputted.
    Complex add(Complex&);

    //Pre:  Takes in a single complex object.
    //Post: Returns a complex number that is the difference of the two inputted.
    Complex subtract(Complex&);

    //Pre:  Takes in a single complex object
    //Post: Returns a complex number that is the product of the two inputted.
    Complex multiply(Complex&);

    //Pre:  Modifies the current complex object.
    //Post: Returns a string of the complex number.
    std::string toString();

    //Pre:  Takes two integers
    //Post: Does not return anything, but modifies the current object.
    void setComplexNumber(double&, double&);

    //Pre:  Takes in a single Complex object
    //Post: Returns a complex number that is the sum of the two added.
    Complex operator+ (Complex&);

    //Pre:  Takes in a single Complex object
    //Post: Returns a complex number that is the difference of the two subtracted.
    Complex operator- (Complex&);

    //Pre:  Takes in a single Complex object
    //Post: Returns a complex number that is the product of the two multiplied.
    Complex operator* (Complex&);

    //Pre:  Takes in a single Complex object
    //Post: Returns a boolean based on the inequality of the two complex objects compared
    bool operator!=   (Complex&);

    //Pre:  Takes in a single Complex object
    //Post: Returns a boolean based on the equality of the two complex objects compared
    bool operator==   (Complex&);

    friend std::istream& operator>> (std::istream& is, Complex& compB)
    {
      std::string strRealPart, strImaginaryPart;
      std::stringstream stringStream;
      is >> strRealPart;
      is >> strImaginaryPart;
      stringStream << strRealPart.substr(1, strRealPart.length()-2);
      stringStream >> compB.realPart;

      stringStream << strImaginaryPart.substr(0, strImaginaryPart.length()-1);
      stringStream >> compB.imaginaryPart;

      return is;
    }

    friend std::ostream& operator<< (std::ostream& os, Complex& compB)
    {
      os << compB.realPart << " + " << compB.imaginaryPart << "i";

      return os;
    }

  private:
    double realPart; //Real half of a complex number.
    double imaginaryPart; //Imaginary half multiplied by i.

};

Complex::Complex() //Default constructor
{
  realPart = 0;
  imaginaryPart = 0;
}

Complex::Complex(double& a, double& b) //Specific constructor
{
  realPart = a;
  imaginaryPart = b;
}

Complex Complex::add(Complex& compB)
{
  Complex obj;
  obj.realPart = realPart + compB.realPart; // Add the real part.
  obj.imaginaryPart = imaginaryPart + compB.imaginaryPart;// And add the imaginary.

  return obj;
}

Complex Complex::subtract(Complex& compB)
{
  Complex obj;
  obj.realPart = realPart - compB.realPart; // Subtract the real part.
  obj.imaginaryPart = imaginaryPart - compB.imaginaryPart; // And subtract the imaginary.

  return obj;
}

Complex Complex::multiply(Complex& compB) //This uses FOIL and then assigns the appropriate values.
{
  Complex obj;

  double a = realPart * compB.realPart; //First
  double b = (realPart * compB.imaginaryPart) + (imaginaryPart * compB.realPart);//Inner & Outer
  double c = imaginaryPart * compB.imaginaryPart;//Last

  obj.realPart = a - c; //This is subtracted since i squared is (-1)
  obj.imaginaryPart = b; //Assigned the imaginary part.

  return obj;
}

std::string Complex::toString()
{

  std::ostringstream stringStream;
  stringStream << realPart << "+" << imaginaryPart << "i";
  return stringStream.str();

}



void Complex::setComplexNumber(double& a, double& b)
{
  realPart = a; //Assign the real.
  imaginaryPart = b;//Assign the imaginary.

}

Complex Complex::operator+(Complex& compB)
{
  return this->add(compB);//Basically pas
}

Complex Complex::operator-(Complex& compB)
{
  return this->subtract(compB);
}

Complex Complex::operator*(Complex& compB)
{
  return this->multiply(compB);
}

bool Complex::operator!=(Complex& compB)
{
  return ((realPart != compB.realPart || imaginaryPart != compB.imaginaryPart) ? true:false);
}

bool Complex::operator==(Complex& compB)
{
   return ((realPart == compB.realPart && imaginaryPart == compB.imaginaryPart) ? true:false);
}


// std::ostream& Complex::operator<<(std::ostream& os, Complex& compB)
// {
//   os << compB.realPart << " + " << compB.imaginaryPart << "i";
//
//   return os;
// }

int main()
{
   for (double i = 1; i < 100; ++ i)
   {
     Complex a(i * 2, i + 2);
     Complex b(i * 3, i + 3);

     Complex c = a.add(b); // invoke add function and assign to object c
     std::cout << "Test case for Complex: add " << std::endl;
     std::cout << a.toString() << " + " << b.toString() << " = " << c.toString() << std::endl;

     a.setComplexNumber(i * 2, i + 2); // reset realPart and
     b.setComplexNumber(i * 3, i + 3); // and imaginaryPart

     std::cout << "Test case for Complex: subtract " << std::endl;
     c = a.subtract(b); // invoke subtract function and assign to object c
     std::cout << a.toString() << " - " << b.toString() << " = " << c.toString() << std::endl;
     std::cout << std::endl;

     a.setComplexNumber(i * 2, i + 2); // reset realPart and
     b.setComplexNumber(i * 3, i + 3); // and imaginaryPart

     std::cout << "Test case for Complex: multiply " << std::endl;
     c = a.multiply(b); // invoke multiply function and assign to object c
     std::cout << a.toString() << " * " << b.toString() << " = " << c.toString() << std::endl;
     std::cout << std::endl;
   }

//  THE FOLLOWING CODE FOR TESTING YOUR OVERLOADING ...

   for (double i = 1; i < 10; ++ i)
   {
     Complex y(i * 2.7, i + 3.2);
     Complex z(i * 6, i + 8.3);

     Complex x;
     Complex k;

     std::cout << "Enter a complex number in the form: (a, b)\n? ";
     std::cin >> k; // demonstrating overloaded >>
     std::cout << "x: " << x << "\ny: " << y << "\nz: " << z << "\nk: "
               << k << '\n'; // demonstrating overloaded <<
     x = y + z; // demonstrating overloaded + and =
     std::cout << "\nx = y + z:\n" << x << " = " << y << " + " << z << '\n';
     x = y - z; // demonstrating overloaded - and =
     std::cout << "\nx = y - z:\n" << x << " = " << y << " - " << z << '\n';
     x = y * z; // demonstrating overloaded * and =
     std::cout << "\nx = y * z:\n" << x << " = " << y << " * " << z << "\n\n";

     if (x != k) { // demonstrating overloaded !=
        std::cout << x << " != " << k << '\n';
     }

     std::cout << '\n';
     x = k;

     if (x == k) { // demonstrating overloaded ==
        std::cout << x << " == " << k << '\n';
     }
       std::cout << std::endl;
     }
return 0;

}
