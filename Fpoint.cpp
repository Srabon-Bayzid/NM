
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

double g(double x)
{
    return cbrt(x + 2);
}

int main()
{
    double x = 0;
    int iteration = 0;

    // Automatically find a starting value
    while (fabs(g(x + 1) - (x + 1)) >=
           fabs(g(x) - x))
    {
        x = x + 1;

        if (x > 100)
        {
            cout << "Suitable starting value not found.";
            return 0;
        }
    }

    cout << "Starting value = " << x << endl;

    cout << fixed << setprecision(6);
    cout << "\nIteration\t x\t\t g(x)" << endl;

    while (true)
    {
        double next = g(x);
        iteration++;

        cout << iteration << "\t\t"
             << x << "\t"
             << next << endl;

        if (fabs(next - x) < 0.000001)
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