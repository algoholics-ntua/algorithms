#include<iostream>
using namespace std;
void insertionsort(int A[],int n);
int main()
{
	int a[100],k,i;
	cout<<"enter no of values in your array\n";
	cin>>k;
	for(int i=0;i<k;i++)
	{
		cout<<"enter "<<i+1<<" element of array\n";
		cin>>a[i];
	}
	insertionsort(a,k);
	cout<<"after sorting\n";
	for(i=0;i<k;i++)
	{
		cout<<a[i]<<endl;
	}
}

void insertionsort(int a[],int n)
{
	int i,j,temp;
	for(i=1;i<n;i++)
	{
		for(j=i-1;j>=0;j--)
		if(a[j+1]<a[j])
		swap(a[j+1],a[j]);
	}
}
