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
    Complex();

    //Pre:  Takes in two complex numbers.
    //Post: Returns a complex number that is the sum of the two inputted.
    complex add(complex);

    //Pre:  Takes in two complex numbers.
    //Post: Returns a complex number that is the difference of the two inputted.
    complex subtract(complex);

    //Pre:  Takes in two complex numbers.
    //Post: Returns a complex number that is the product of the two inputted.
    complex multiply(complex);

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

complex Complex::add(complex compB)
{
  realPart += compB.realPart; // Add the real part.
  imaginaryPart += compB.imaginaryPart;// And add the imaginary.
}

complex Complex::subtract(complex compB)
{
  realPart -= compB.realPart;
  imaginaryPart -= compB.imaginaryPart;
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

complex 

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


