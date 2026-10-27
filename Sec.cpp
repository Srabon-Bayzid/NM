
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

double f(double x)
{
    return x * x * x - x - 2;
}

int main()
{
    double x0 = 0, x1 = 1, x2;
    int iteration = 0;

    // Automatically find two starting values
    while (f(x0) * f(x1) >= 0)
    {
        x0 = x1;
        x1 = x1 + 1;

        if (x1 > 1000)
        {
            cout << "Starting values not found.";
            return 0;
        }
    }

    cout << "x0 = " << x0 << endl;
    cout << "x1 = " << x1 << endl;

    cout << fixed << setprecision(6);
    cout << "\nIteration\t x0\t\t x1\t\t x2\t\t f(x2)"
         << endl;

    while (iteration < 100)
    {
        double denominator = f(x1) - f(x0);

        if (fabs(denominator) < 0.000000000001)
        {
            cout << "Denominator is too small." << endl;
            return 0;
        }

        x2 = x1 - f(x1) * (x1 - x0) / denominator;
        iteration++;

        cout << iteration << "\t\t"
             << x0 << "\t"
             << x1 << "\t"
             << x2 << "\t"
             << f(x2) << endl;

        if (fabs(x2 - x1) < 0.000001)
        {
            break;
        }

        x0 = x1;
        x1 = x2;
    }

    cout << "\nApproximate root = " << x2 << endl;

    return 0;
}