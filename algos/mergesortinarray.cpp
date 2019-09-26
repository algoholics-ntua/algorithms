#include<iostream>
using namespace std;
void merge(int a[],int p,int q,int r)
{
	int n1=q-p+1;
	int n2=r-q;
	int L[n1+1],R[n2+1];
	for(int i=1;i<=n1;i++)
		L[i]=a[p+i-1];
	for(int j=1;j<=n2;j++)
		R[j]=a[q+j];
	L[n1+1]=300;
	R[n2+1]=300;
	int i=1,j=1;
	for(int k=p;k<=r;k++)
	{
		if(L[i]<=R[j])
		{
			a[k]=L[i];
			i++;
		}
		else{
			a[k]=R[j];
			j++;
		}
	}
}
void mergesort(int a[], int p, int r)
{
	if(p<r)
	{
		int q=(p+r)/2;
		mergesort(a,p,q);
		mergesort(a,q+1,r);
		merge(a,p,q,r);
	}
}

int main()
{
	int a[10];
	for(int i=1;i<=7;i++)
	{
		cin>>a[i];
	}
	mergesort(a,1,7);
	for(int i=1;i<=7;i++)
		cout<<a[i]<<"\t";
	return 0;
}
