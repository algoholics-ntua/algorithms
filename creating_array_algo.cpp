Creating an array

#include<iostream.h>
#include<conio.h>
int sum(int arr[],int n)
{
if(n==0)
return 0;
else
return(sum(arr,n-1)+arr[n-1]);
}

void main()
{
clrscr();
int n;
int a[20];
cout<<"Enter the number of elements you want:-";
cin>>n;
for(int i=0;i<n;i++)
{
cin>>a[i];
}
int result=0;
result=sum(a,n);
cout<<"On adding these elements,result is:- "<<result;
getch();
}
