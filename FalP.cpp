
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

    // Automatically find a and b
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

    // False Position Method
    while (true)
    {
        c = (a * f(b) - b * f(a)) / (f(b) - f(a));
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

        if (b - a < 0.000001 && b - a > -0.000001)
        {
            break;
        }
    }

    cout << "\nApproximate root = " << c << endl;

    return 0;
}