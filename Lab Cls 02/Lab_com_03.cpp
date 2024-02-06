#include <iostream>
using namespace std;

bool SingleLineComment(const string& line)
{
    return (line.length() >= 2 && line[0] == '/' && line[1] == '/');
}

bool MultiLineCommentStart(const string& line)
{
    return (line.length() >= 2 && line[0] == '/' && line[1] == '*');
}

bool MultiLineCommentEnd(const string& line)
{
    return (line.length() >= 2 && line[line.length() - 2] == '*' && line[line.length() - 1] == '/');
}

int main()
{
    cout << "Enter input:" << endl;

    string line;
    cin>>line;

    if (SingleLineComment(line))
    {
        cout << "Single line comment" << endl;
    }
    else if (MultiLineCommentStart(line))
    {
        cout << "multi_line comment" << endl;
    }

    else
    {
        cout << "Not a comment" << endl;
    }

    return 0;
}
