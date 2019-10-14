#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int **m,**s;
void MatrixChainOrder(int *P,int n)
{
	int j;
	long int q;
	m=new int*[n];
	s=new int*[n];
	for(int i=0;i<n;i++)
	{
		m[i]=new int[n];
		s[i]=new int[n];
		m[i][i]=0;
	}
	for(int l=2;l<=n;l++)
		for(int i=0;i<n-l+1;i++)
		{
			j=i+l-1;
			m[i][j]=INT_MAX;
			for(int k=i;k<j;k++)
			{
				q=m[i][k]+m[k+1][j]+(P[i]*P[k+1]*P[j+1]);
				if(q<m[i][j])
				{
					m[i][j]=q;
					s[i][j]=k;
				}
			}
		}
}
int num=1;
void disp(int a,int b)
{
	if(a==b)
	{
		cout<<"M"<<num;
		num++;
		return;	
	}
	cout<<"(";
	disp(a,s[a][b]);
	cout<<" X ";
	disp(s[a][b]+1,b);
	cout<<")";
}
int main()
{
	int n,*P;
	cout<<"Enter the no. of matrices: ";
	cin>>n;
	P=new int[n+1];
	cout<<"Enter the different orders: \n";
	for(int i=0;i<n+1;i++)
	cin>>P[i];
	MatrixChainOrder(P,n);
	cout<<"Order of Matrix Multiplication: \n";
	disp(0,n-1);
	cout<<"\nThe maximum scalar multiplications required: "<<m[0][n-1];
	return 0;
}