#include <iostream>
using namespace std;

bool ArithmeticOperator(char ch)
{
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%' || ch == '=');
}

int main()
{
    cout << "Enter a string: ";

    char input[100];
    cin >> input;

    cout << "Operators in the input:" << endl;

    for (int i = 0; input[i] != '\0'; i++)
    {
        if (ArithmeticOperator(input[i]))
        {
            cout << "Operator: " << input[i] << endl;
        }
    }

    return 0;
}
