
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

    // Calculate forward differences
    for (int j = 1; j < n; j++)
    {
        for (int i = 0; i < n - j; i++)
        {
            diff[i][j] = diff[i + 1][j - 1]
                       - diff[i][j - 1];
        }
    }

    // Print the forward difference table
    cout << fixed << setprecision(4);

    cout << "\nx\t\tY";

    for (int j = 1; j < n; j++)
    {
        if (j == 1)
            cout << "\t\t1st Diff";
        else if (j == 2)
            cout << "\t\t2nd Diff";
        else if (j == 3)
            cout << "\t\t3rd Diff";
        else
            cout << "\t\t" << j << "th Diff";
    }

    cout << endl;
    cout << "------------------------------------------------------------"
         << endl;

    for (int i = 0; i < n; i++)
    {
        cout << x[i] << "\t\t" << y[i];

        for (int j = 1; j < n - i; j++)
        {
            cout << "\t\t" << diff[i][j];
        }

        cout << endl;
    }

    // Newton's forward interpolation
    h = x[1] - x[0];
    u = (value - x[0]) / h;

    result = y[0];
    term = 1;

    for (int j = 1; j < n; j++)
    {
        term = term * (u - j + 1) / j;
        result = result + term * diff[0][j];
    }

    cout << "\nf(" << value << ") = " << result << endl;

    return 0;
}