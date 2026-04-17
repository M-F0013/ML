#include <iostream>
using namespace std;

int main() {
   int n, a[10];
   cout << "enter the no. of elements:";
   cin >> n;
   cout << "enter the elements:";
   for (int i = 0; i < n; i++)
       cin >> a[i];
   for (int i=0; i<n-1; i++){
       int min=i;
       for(int j=i+1; j<n; j++){
           if(a[j]<a[min])
           min=j;
       }
       int temp=a[i];
       a[i]=a[min];
       a[min]=temp;
   }
       cout << "sorted array:";
   for (int i = 0; i < n; i++)
       cout << a[i] << " ";
   return 0;
}


