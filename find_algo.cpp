Make Empty Algo

#include<iostream.h>
#include<conio.h>
void linear_search(int arr[],int n,int x)
{
if(n==0)
cout<<"Element not found";
else
{
	if(x==arr[n])
	cout<<"Element found at index "<<n+1;
	else
	linear_search(arr,n-1,x);
}
}
void main()
{
clrscr();
int n,a[20];
cout<<"Enter the number of elements you want to enter: \n";
cin>>n;
for(int i=0;i<n;i++)
{
cin>>a[i];
}
int x;
cout<<"Enter the element you want to search:\n";
cin>>x;
linear_search(a,n,x);
getch();
}
