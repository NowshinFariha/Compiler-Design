#include<iostream>
using namespace std;

int main()
{
    int nbr, i = 1, f = 1;

    cout << "Enter a number to calculate its factorial :";
    cin >> nbr;

    while (i <= nbr)
    {
        f = f*i;
        ++i;
    }

    cout << "Factorial :" << f;

    return 0;
}
