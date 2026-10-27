
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int n;
    double x[20], y[20], dd[20][20];
    double value, result, product;

    cout << "Enter number of data points: ";
    cin >> n;

    cout << "Enter x and y values:\n";

    for (int i = 0; i < n; i++)
    {
        cin >> x[i] >> y[i];
        dd[i][0] = y[i];
    }

    // Calculate divided differences
    for (int j = 1; j < n; j++)
    {
        for (int i = j; i < n; i++)
        {
            dd[i][j] = (dd[i][j - 1] -
                        dd[i - 1][j - 1]) /
                       (x[i] - x[i - j]);
        }
    }

    // Display divided difference table
    cout << "\nDivided Difference Table:\n";
    cout << fixed << setprecision(6);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << setw(12) << dd[i][j];
        }
        cout << endl;
    }

    cout << "\nEnter the value of x to find y: ";
    cin >> value;

    // Calculate interpolated value
    result = dd[0][0];
    product = 1;

    for (int i = 1; i < n; i++)
    {
        product = product * (value - x[i - 1]);
        result = result + product * dd[i][i];
    }

    cout << "Interpolated value = " << result << endl;

    return 0;
}