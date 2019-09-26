Delete Unsorted List

#include<iostream>
using namespace std;

void deleting(int arr[],int n,int x)
{int i,flag=0;
    for(i=0;i<n;i++)
    {
        if(arr[i]==x)
        {
            flag=1;
            int p=i;
            for(i=p;i<n-1;i++)
            {
                arr[i]=arr[i+1];
            }
        }
    }
    if(flag==0)
        cout<<"Element doesnot exist";
}
int main()
{
int a[10],i,n,x;
cout<<"Enter the number of elements you want to enter";
cin>>n;

cout<<"Enter the values:\n";
for(i=0;i<n;i++)
{
cin>>a[i];
}

cout<<"Enter the number to be deleted : ";
cin>>x;

deleting(a,n,x);


for(i=0;i<n-1;i++)
{cout<<a[i]<<" ";}

return 0;
}
