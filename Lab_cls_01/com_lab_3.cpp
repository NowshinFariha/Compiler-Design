#include <iostream>
#include <cstring>
#include <stack>

using namespace std;

int main()
{
    const int max_size = 100;
    char firstName[max_size];
    char lastName[max_size];

    cout << "Enter your first name: ";
    cin >> firstName;

    cout << "Enter your last name: ";
    cin >> lastName;

    stack<char> fullName;

    int len = strlen(lastName);
    for (int i = len; i>=0; --i)
    {
        fullName.push(lastName[i]);
    }

    fullName.push(' ');

    len = strlen(firstName);
    for (int i = len; i >=0; --i)
    {
        fullName.push(firstName[i]);
    }

    cout << "Full name: ";
    while (!fullName.empty())
    {
        cout << fullName.top();
            fullName.pop();
    }

    return 0;
}

