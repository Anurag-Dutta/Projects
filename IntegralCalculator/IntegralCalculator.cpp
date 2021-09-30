#include <iostream>
#include <math.h>

using namespace std;

const double n = 1000000;
double f(double x);

int main()
{
    char answ;
    double t, j;
    double a, b;
    cout << "\t______________________________________________\n";
    cout << "\t***DEFINITE INTEGRAL CALCULATOR***\n";
    cout << "\t \n";
    cout << "\t______________________________________________\n";
    cout << endl;
    cout << endl;
    cout << "\t This program estimates definite integrals\n";
    cout << "\t numerically using the Riemann sum. \n";
    cout << endl;
    cout << "\t The integrand is now set to F(x)= (cos{x))^11" << endl; //here  (cos(x))^11 is a sample function.This can be changed any time in the code.
    cout << "\t You can chance the integrand in the code.\n";
    cout << endl;
    do
    {
        cout << "\t Enter LOWER LIMIT: ";
        cin >> a;
        cout << "\t Enter UPPER LIMIT: ";
        cin >> b;
        cin.ignore();
        double g = 0;
        for (j = 1; j <= n; j++)
        {
            g = g + (f(a + (b - a) / n * j) * (b - a) / n);
        }
        cout << endl;
        cout << "\a \t Integral= " << g << endl;
        cout << endl;
        cout << "Want to Check Again? (y/n): ";
        cin >> answ;
    } while (answ == 'y');
    cin.get();
    return 0;
}
double f(double x)
{
    return (pow((cos(x)), 11)); // This is the integrand.This can be changed any time  in the code.
}
