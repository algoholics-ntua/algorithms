Insertion in Sorted Array

#include<iostream>
using namespace std;
int main()
{
int a[20],i,n;
cout<<"Enter the number of elements you want to enter : ";
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
    cout<<a[i]<<" ";
}

int x,p;
cout<<"\nEnter the element you want to insert: ";
cin>>x;
int flag=0;
for(i=0;i<n;i++)
{
    if(a[i]==x)
        {
            cout<<"Element already exists\n";
            for(i=0;i<n;i++)
            {
            cout<<a[i]<<"\t";
            }
        }

    else if(a[i]>x)
    {
        p=i;
        flag=1;
        for(i=n;i>p;i--)
        {
            a[i]=a[i-1];
        }
        a[p]=x;
        break; ////IMPORTANT
    }
}
if(i==n)
{
    flag=1;
    a[n] = x;
}
cout<<endl;
if(flag==1)
{
for(i=0;i<=n;i++)
{
    cout<<a[i]<<"\t";
}
}
return 0;
}
