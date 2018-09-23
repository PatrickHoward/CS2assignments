/*
   COPYRIGHT (C) 2017 Student Name (UANET ID ) All rights reserved.
   CSII assignment 1
   Author.  Student Name
            zippy@zips.uakron.edu
   Version. 1.01 09.09.2017
   Purpose: This program is the test cases for the assignment
*/

#include <iostream>
#include <string>
#include <sstream> // for ostringstream class


class Complex
{
  public:

    //Pre:  Takes in two complex numbers.
    //Post: Returns a complex number that is the sum of the two inputted.
    complex add(complex, complex);

    //Pre:  Takes in two complex numbers.
    //Post: Returns a complex number that is the difference of the two inputted.
    complex subtract(complex, complex);

    //Pre:  Takes in two complex numbers.
    //Post: Returns a complex number that is the product of the two inputted.
    complex multiply(complex, complex);

    //Pre:  Takes in a singluar complex number.
    //Post: Returns a string of the complex number.
    std::string toString(complex);

    //Pre:  class Complex
    //Post:
    complex setComplex(int, int);

    Complex(int, int); //Constructor

  private:
    int realPart;
    int imaginaryPart;

}

complex Complex::add(complex compA, complex compB)
{
  //I figured its a little more efficient to just modify a single object instead of creating a brand new one.
  compA.realPart += compB.realPart; // Add the real part.
  compA.imaginaryPart += compB.imaginaryPart;// And add the imaginary.

  return compA;
}

complex Complex::subtract(complex compA, complex compB)
{
  compA.realPart -= compB.realPart;
  compA.imaginaryPart -= compB.imaginaryPart;

  return compA;
}

complex Complex::multiply(complex compA, complex compB)
{


}

std::string toString(complex num)
{
  std::ostringstream stringStream;
  stringStream << num.realPart << '+' << num.imaginaryPart << 'i'
  return stringStream;

}


int main()
{
   for (double i = 1; i < 100; ++ i)
   {
     Complex a{i * 2, i + 2};
     Complex b{i * 3, i + 3};

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

return 0;

}


