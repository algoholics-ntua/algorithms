Insertion in Unsorted List

#include<iostream>
using namespace std;
inserting(int arr[],int n,int x,int k)
{int i;
    for(i=n;i>=k;i--)
    {arr[i]=arr[i-1];}
    arr[k-1]=x;
}
int main()
{
int a[20],i,n;
cout<<"Enter the number of elements you want to enter";
cin>>n;

cout<<"Enter the values:\n";
for(i=0;i<n;i++)
{
cin>>a[i];
}

int x;
cout<<"Enter the element you want to insert : ";
cin>>x;

int k;
cout<<"Enter the index where you want to insert : ";
cin>>k;


inserting(a,n,x,k);
for(i=0;i<=n;i++)
{
cout<<a[i]<<" ";
}

return 0;
}
