/*
Nathan Taylor
12/26/18
xe^(-x^3) - not integratable
Use a Taylor polynomial to model and integrate over interval [0,.3]
Compare with Riemann Sum - Simpsons Rule
*/
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <iomanip>

using namespace std;

double factorial(double number);
double taylorseries(double init, int iter);
double riemann(double init, int iter);

int main()
{
  cout << setprecision(43) << taylorseries(.3, 4) << endl;
  cout << riemann(.3, 4) << endl;
  cout << taylorseries(.3, 4) - riemann(.3, 4);
  return 0;
}

//simpsons rule
double riemann(double init, int iter)
{
  //cout << exp(1) << endl;
  
  double delta;
  double num;
  for (int i = 0; i < iter + 1; i++)
    {
      delta = i*(init/iter);
      if (i == 0 || i == iter)//1
	{
	  num += (delta) / exp (pow(delta, 3));
	}
      else if (i % 2 == 0)//2
	{
	  num += 2 * (delta) / exp (pow(delta, 3));
	}
      else//4
	{
	  num += 4 * (delta) / exp (pow(delta, 3));
	}
    }
  num *= (init/iter)/3;
  //cout << setprecision(43) << num << endl;
  return num;
}

double taylorseries(double init, int iter)
{
  double num = 0;
  for (int i = 0; i < iter; i++)
    {
      num += pow(-1, i) * pow(init, 3*i+2)/((3*i+2)*factorial(double(i)));
      //cout << setprecision(43) << num << endl;
    }
  //cout << setprecision(43) << num << endl;
  return num;
}

double factorial(double number)
{
  double fact = 1;
  while (number > 0)
    {
      fact *= number--;
    }
  return fact;
}
