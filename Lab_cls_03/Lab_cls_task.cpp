#include <iostream>
#include <string>
#include<fstream>
using namespace std;
bool isValidIdentifier(string variable)
{
    ifstream keywords("C:\\New folder\\keywords.txt");
    if(!keywords.is_open())
    {
        cout<<"cant open file"<<endl;
        return false;
    }
    string keys;
    while(getline(keywords,keys,','))
    {
        if(variable==keys)
        {
            cout<<"invalid identifier: same as keywords"<<endl;
            return false;
        }
    }
    if (!((variable[0] >= 'a' && variable[0] <= 'z') ||
          (variable[0] >= 'A' && variable[0] <= 'Z') ||
           variable[0] == '_'))
            {
                cout << "Invalid identifier: It must start with a letter or underscore." << endl;
                return false;
            }

    for (int i = 1; variable[i] != '\0'; ++i)
    {
        if (!((variable[i] >= 'a' && variable[i] <= 'z') ||
              (variable[i] >= 'A' && variable[i] <= 'Z') ||
              (variable[i] >= '0' && variable[i] <= '9') ||
               variable[i] == '_'))
              {
                    cout << "Invalid identifier: It contains an invalid character." << endl;
                    return false;
              }
    }
    return true;
    keywords.close();

}
int main()
{

    string variable;
    cout << "Enter an identifier:";
    cin >> variable;
    if (isValidIdentifier(variable))
    {
        cout << "Valid identifier." << endl;
    }
    return 0;
}
