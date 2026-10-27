
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int n;
    double x[100], y[100];
    double diff[100][100];
    double value, h, u, term, result;

    cout << "Enter number of points: ";
    cin >> n;

    cout << "Enter x values: ";
    for (int i = 0; i < n; i++)
    {
        cin >> x[i];
    }

    cout << "Enter y values: ";
    for (int i = 0; i < n; i++)
    {
        cin >> y[i];
        diff[i][0] = y[i];
    }

    cout << "Enter x to find f(x): ";
    cin >> value;

    // Calculate backward differences
    for (int j = 1; j < n; j++)
    {
        for (int i = j; i < n; i++)
        {
            diff[i][j] = diff[i][j - 1]
                       - diff[i - 1][j - 1];
        }
    }

    // Print the backward difference table
    cout << fixed << setprecision(4);

    cout << "\nx\t\tY";

    for (int j = 1; j < n; j++)
    {
        cout << "\t\t" << j << "st Diff";
    }

    cout << endl;

    cout << "------------------------------------------------------------"
         << endl;

    for (int i = 0; i < n; i++)
    {
        cout << x[i] << "\t\t" << y[i];

        for (int j = 1; j <= i; j++)
        {
            cout << "\t\t" << diff[i][j];
        }

        cout << endl;
    }

    // Newton's backward interpolation
    h = x[1] - x[0];
    u = (value - x[n - 1]) / h;

    result = y[n - 1];
    term = 1;

    for (int j = 1; j < n; j++)
    {
        term = term * (u + j - 1) / j;
        result = result + term * diff[n - 1][j];
    }

    cout << "\nf(" << value << ") = " << result << endl;

    return 0;
}