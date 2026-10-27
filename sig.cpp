
#include <iostream>
#include <string>
using namespace std;

int main()
{
    string num;
    int count = 0;
    bool started = false;
    bool decimal = false;

    cout << "Enter a number: ";
    cin >> num;

    for (int i = 0; i < num.length(); i++)
    {
        if (num[i] == '.')
        {
            decimal = true;
            continue;
        }

        if (num[i] >= '1' && num[i] <= '9')
        {
            count++;
            started = true;
        }
        else if (num[i] == '0' && started)
        {
            count++;
        }
    }

    if (!decimal)
    {
        while (num.length() > 0 && num.back() == '0')
        {
            count--;
            num.pop_back();
        }
    }

    cout << "Significant digits = " << count << endl;

    return 0;
}