#ifndef COMPLEX
#define COMPLEX

class Complex
{
  public:
    Complex add(Complex, Complex);
    Complex subtract(Complex, Complex);
    Complex multiply(Complex, Complex);
    Complex toString(Complex, Complex);
    Complex setComplex(Complex, Complex);
    
    Complex(int, int); //Constructor

  private:
    int realPart;
    int imaginaryPart;

}

#endif
