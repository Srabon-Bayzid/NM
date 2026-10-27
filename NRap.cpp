
#include <iostream>
#include <iomanip>
using namespace std;

double f(double x)
{
    return x * x * x - x - 2;
}

double df(double x)
{
    return 3 * x * x - 1;
}

int main()
{
    double x = 0;
    int iteration = 0;

    // Automatically find a starting value
    while (df(x) == 0 || f(x) * f(x + 1) >= 0)
    {
        x = x + 1;
    }

    cout << "Starting value = " << x << endl;

    cout << fixed << setprecision(6);
    cout << "\nIteration\t x\t\t f(x)" << endl;

    while (true)
    {
        if (df(x) == 0)
        {
            cout << "Derivative is zero. Cannot continue." << endl;
            return 0;
        }

        double next = x - f(x) / df(x);
        iteration++;

        cout << iteration << "\t\t"
             << next << "\t"
             << f(next) << endl;

        if (next - x < 0.000001 &&
            next - x > -0.000001)
        {
            x = next;
            break;
        }

        x = next;

        if (iteration >= 100)
        {
            cout << "Maximum iterations reached." << endl;
            break;
        }
    }

    cout << "\nApproximate root = " << x << endl;

    return 0;
}