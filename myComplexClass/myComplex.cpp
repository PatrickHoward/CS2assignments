/*
   COPYRIGHT (C) 2018 Patrick M. Howard (pmh41) All rights reserved.
   CSII assignment 1
   Author.  Patrick M. Howard
            pmh41@zips.uakron.edu
   Version. 1.01 09.22.2018
   Purpose: This program is the test cases for the assignment
*/

#include <iostream>
#include <string>
#include <sstream> // for ostringstream class


class Complex
{
  public:

    //Default constructor.
    Complex();
    
    //Constructor used for setting up exact values/
    Complex(int, int);

    //Pre:  Takes in two complex numbers.
    //Post: Returns a complex number that is the sum of the two inputted.
    Complex add(Complex);

    //Pre:  Takes in two complex numbers.
    //Post: Returns a complex number that is the difference of the two inputted.
    Complex subtract(Complex);

    //Pre:  Takes in two complex numbers.
    //Post: Returns a complex number that is the product of the two inputted.
    Complex multiply(Complex);

    //Pre:  Modifies the current complex object. 
    //Post: Returns a string of the complex number.
    std::string toString();

    //Pre:  class Complex
    //Post:
    void setComplexNumber(int, int);

  private:
    int realPart;
    int imaginaryPart;

};

Complex::Complex(int a, int b)
{
  realPart = a;
  imaginaryPart = b;
}

Complex::Complex()
{
  realPart = 0;
  imaginaryPart = 0;
}

Complex Complex::add(Complex compB)
{
  Complex obj(int a, int b);
  a = realPart + compB.realPart; // Add the real part.
  b = imaginaryPart + compB.imaginaryPart;// And add the imaginary.
  
  return obj;
}

Complex Complex::subtract(Complex compB)
{
  Complex obj(int a,int b);
  a = realPart - compB.realPart; // Subtract the real part.
  b = imaginaryPart - compB.imaginaryPart; // And subtract the imaginary.
  
  return obj;
}

Complex Complex::multiply(Complex compB)
{
  Complex obj(int real,int imagine);
  int a = realPart * compB.realPart;
  int b = (realPart * compB.imaginaryPart) + (imaginaryPart * compB.realPart);
  int c = imaginaryPart * compB.imaginaryPart;

  real = a - c;
  imagine = b; 
  
  return obj;
}

std::string Complex::toString()
{
  std::ostringstream stringStream;
  stringStream << realPart << "+" << imaginaryPart << "i";
  return stringStream.str();

}

void Complex::setComplexNumber(int a, int b)
{
  realPart = a;
  imaginaryPart = b;

}


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
/*
   for (double i = 1; i < 10; ++ i)
   {
     Complex y{i * 2.7, i + 3.2};
     Complex z{i * 6, i + 8.3};

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
*/
return 0;

}


