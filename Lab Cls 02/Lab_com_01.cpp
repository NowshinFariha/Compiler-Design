#include <iostream>
using namespace std;

bool Numeric(string str)
{
    bool hasDigit = false;
    bool hasDot = false;
    bool hasSign = false;

    for(int i = 0; i < str.length(); i++)
    {
        if(str[i] >= '0' && str[i] <= '9')
        {
            hasDigit = true;
        }
        else if(str[i] == '.' && !hasDot)
        {
            hasDot = true;
        }
        else if((str[i] == '+' || str[i] == '-') && !hasSign && (i == 0 || str[i-1] == 'e' || str[i-1] == 'E'))
        {
            hasSign = true;
        }
        else
        {
            return false;
        }
    }

    return hasDigit;
}

int main()
{
    string str;
    cout << "Enter a string: ";
    cin >> str;

    if(Numeric(str))
    {
        cout << "This is a Number" << endl;
    }
    else
    {
        cout << "This is not a Number" << endl;
    }

    return 0;
}
