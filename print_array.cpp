Printing Array
#include<iostream>
#include<conio.h>
using namespace std;
int main()
{
int a[10];
int i,n;
cout<<"Enter the number of elements you want : ";
cin>>n;
cout<<"Enter the values \n";
for(i=0;i<n;i++)
{
cin>>a[i];
}

cout<<"Your array is:\n";

for(i=0;i<n;i++)
{
cout<<a[i]<<" ";
}

return 0;
}
