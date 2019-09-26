Next Algorithm

#include<iostream>
using namespace std;
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
cout<<"Enter the number whose next element you want to know:";
cin>>x;
int flag=0;
for(i=0;i<n;i++)
{
    if(x==a[i])
    {
        if(i==(n-1))
        {
        cout<<"No element exists after this";
        flag=1;
        break;
        }
        else
        {
        cout<<"Next element is :"<<a[i+1];
        flag=1;
        break;
        }
    }


}
if(flag==0)
{cout<<"Element doesnot exist";}
return 0;
}
