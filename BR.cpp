
#include <iostream>
#include <string>
using namespace std;

string bankersRound(string number, int places)
{
    string sign = "";

    if (number[0] == '-')
    {
        sign = "-";
        number = number.substr(1);
    }

    int dot = number.find('.');

    string whole;
    string fraction;

    if (dot != string::npos)
    {
        whole = number.substr(0, dot);
        fraction = number.substr(dot + 1);
    }
    else
    {
        whole = number;
        fraction = "";
    }

    string kept = fraction.substr(0, places);

    while (kept.length() < places)
    {
        kept = kept + '0';
    }

    int nextDigit = 0;
    string remaining = "";

    if (fraction.length() > places)
    {
        nextDigit = fraction[places] - '0';
        remaining = fraction.substr(places + 1);
    }

    string temp = whole + kept;
    long long value = stoll(temp);

    bool roundUp = false;

    if (nextDigit > 5)
    {
        roundUp = true;
    }
    else if (nextDigit == 5)
    {
        for (int i = 0; i < remaining.length(); i++)
        {
            if (remaining[i] != '0')
            {
                roundUp = true;
                break;
            }
        }

        if (!roundUp && value % 2 != 0)
        {
            roundUp = true;
        }
    }

    if (roundUp)
    {
        value++;
    }

    string result = to_string(value);

    if (places > 0)
    {
        while (result.length() <= places)
        {
            result = "0" + result;
        }

        int position = result.length() - places;
        result.insert(position, ".");
    }

    return sign + result;
}

int main()
{
    int n, places;

    cout << "How many numbers? ";
    cin >> n;

    cout << "How many decimal places? ";
    cin >> places;

    string numbers[100];

    for (int i = 0; i < n; i++)
    {
        cout << "Enter number " << i + 1 << ": ";
        cin >> numbers[i];
    }

    cout << endl;
    cout << "Number\t\tBanker's Rounding" << endl;
    cout << "------------------------------------------" << endl;

    for (int i = 0; i < n; i++)
    {
        cout << numbers[i] << "\t\t";
        cout << bankersRound(numbers[i], places) << endl;
    }

    return 0;
}