#include "Complex.hpp"
#include<string>
#include<sstream>

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
