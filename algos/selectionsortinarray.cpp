#include<iostream>
using namespace std;
void selectionsort(int a[],int n)
{
	int small;
	for(int i=0;i<n;i++)
	{
		small=i;
		for(int j=i+1;j<n;j++)
		{
			if(a[small]>a[j])
			small=j;
		}
		swap(a[i],a[small]);
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
	{cout<<"enter value of"<<i+1<<" element \t";
	cin>>a[i];
	}
	cout<<"\n**************before sort****************\n";
	view(a,n);
	selectionsort(a,n);
		cout<<"\n*******************after sort****************\n";
		view(a,n);
	}
