
#include <iostream>
using namespace std;

int main()
{
    int degree;
    int a[100];
    int x;
    long long p;

    cout << "Enter degree: ";
    cin >> degree;

    cout << "Enter coefficients (highest power first): ";

    for (int i = 0; i <= degree; i++)
    {
        cin >> a[i];
    }

    cout << "Enter value of x: ";
    cin >> x;

    p = a[0];

    cout << endl;
    cout << "Power\t a(k)\t P(k)" << endl;
    cout << "--------------------------------" << endl;

    cout << degree << "\t " << a[0] << "\t " << p << endl;

    for (int i = 1; i <= degree; i++)
    {
        p = p * x + a[i];

        cout << degree - i << "\t "
             << a[i] << "\t "
             << p << endl;
    }

    cout << endl;
    cout << "f(" << x << ") = " << p << endl;

    return 0;
}