#include<iostream>
using namespace std;
void bubblesort(int a[],int n)
{
	int small;
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(a[i]>a[j])
			swap(a[i],a[j]);
		}
	}
}
void view(int a[],int n)
{
	for(int i=0;i<n;i++)
	{
		cout<<a[i]<<"\t";
	}
}
int main()
{
	int a[100],i,n;
	cout<<"enter number of elements \n";
	cin>>n;
	for(i=0;i<n;i++)
	{cout<<"enter value of "<<i+1<<" element \t";
	cin>>a[i];
	}
	cout<<"\n**************before sort****************\n";
	view(a,n);
	bubblesort(a,n);
		cout<<"\n*******************after sort****************\n";
		view(a,n);
	}
