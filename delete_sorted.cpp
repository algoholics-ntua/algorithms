Deletion in a sorted array

#include<iostream>
#include<stdlib.h>
using namespace std;
int main()
{
int a[10],x,n,i,p;
cout<<"Enter the number of elements you want to enter";
cin>>n;

cout<<"Enter the values:\n";
for(i=0;i<n;i++)
{
cin>>a[i];
}

int j,key;
for(j=1;j<n;j++)
{
    key=a[j];
    i=j-1;
    while(i>=0&&a[i]>key)
    {
        a[i+1]=a[i];
        i-=1;
    }
a[i+1]=key;
}
cout<<"Sorted list:\n ";
for(i=0;i<n;i++)
{
    cout<<a[i]<<"\t";
}

cout<<"Enter the element you want to delete: ";
cin>>x;
int flag=0;
for(i=0;i<n;i++)
{
    if(a[i]==x)
    {
        p=i;
        flag=1;
        for(i=p;i<n-1;i++)
        {
            a[i]=a[i+1];
        }
        a[n-1]=0;
        break;
    }
}

if(flag==0)
    {cout<<"Element does not exist";
    exit(0);}
cout<<"List after deleting "<<x<<":\n";
for(i=0;i<n-1;i++)
{
    cout<<a[i]<<"\t";
}
return 0;
}
