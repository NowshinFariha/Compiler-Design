#include<iostream>

using namespace std;

int main ()
{
    int num;
    cout << "Enter the amount of numbers :";
    cin >> num;
    int arr[num], sum=0, avg;
    for(int i=0;i<num;i++)
    {
        cout << "Enter the number:";
        cin >> arr[i];
        sum = sum + arr[i];
    }
    avg = sum/num;
    cout << "Average =" <<avg;
    return 0;
}
