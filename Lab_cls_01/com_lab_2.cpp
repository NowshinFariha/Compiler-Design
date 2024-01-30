#include<iostream>
using namespace std;

int main ()


{
   int n;
   cout << "Enter the size of array :";
   cin >> n;

   int arr[n],max,min,i;

   cout << "Enter element of array :";
   for(i=0;i<n;i++)
   cin >> arr[i];

   max = arr[0];
   min = arr[0];

   for(i=0;i<n;i++)
   {
       if(max < arr[i])
          max = arr[i];
       else if (min > arr[i])
          min = arr[i];
   }

    cout << "\nMaximum element of array :"<<max;
    cout << "\nMinimum element of array :"<<min;

    return 0;
}

