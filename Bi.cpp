
#include <iostream>
#include <iomanip>
using namespace std;

double f(double x)
{
    return x * x * x - x - 2;
}

int main()
{
    double a = 0, b = 1, c;
    int iteration = 0;

    // Automatically find a valid interval
    while (f(a) * f(b) >= 0)
    {
        a = b;
        b = b + 1;
    }

    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    cout << fixed << setprecision(6);

    cout << "\nIteration\t a\t\t b\t\t c\t\t f(c)"
         << endl;

    // Bisection method
    while (true)
    {
        c = (a + b) / 2;
        iteration++;

        cout << iteration << "\t\t"
             << a << "\t"
             << b << "\t"
             << c << "\t"
             << f(c) << endl;

        if (f(c) == 0)
        {
            break;
        }
        else if (f(a) * f(c) < 0)
        {
            b = c;
        }
        else
        {
            a = c;
        }

        // Stop when the interval is sufficiently small
        if (b - a < 0.000001)
        {
            break;
        }
    }

    cout << "\nApproximate root = " << c << endl;

    return 0;
}