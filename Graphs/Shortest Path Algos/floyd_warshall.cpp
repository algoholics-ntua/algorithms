#include<iostream>
#include<climits>
#include<bits/stdc++.h>
using namespace std;
int v,e;
int **W;
struct matrix
{
	int **D;
	char **P;
}*R;
void Floyd_Warshall(int **W,int n)
{
	R=new matrix[n+1];
	for(int i=0;i<=n;i++)
	{
		R[i].D=new int*[n];
		R[i].P=new char*[n];
		for(int k=0;k<n;k++)
		{
			R[i].D[k]=new int[n];
			R[i].P[k]=new char[n];
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			R[0].D[i][j]=W[i][j];
			if(W[i][j]==INT_MAX||W[i][j]==0)
			R[0].P[i][j]='N';
			else
			R[0].P[i][j]=i+97;
		}
	}
	for(int k=1;k<=n;k++)
	{
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(R[k-1].D[i][j]>(R[k-1].D[i][k-1]+R[k-1].D[k-1][j])&&
				   R[k-1].D[i][k-1]!=INT_MAX&&R[k-1].D[k-1][j]!=INT_MAX)
				{
					R[k].D[i][j]=R[k-1].D[i][k-1]+R[k-1].D[k-1][j];
					R[k].P[i][j]=R[k-1].P[k-1][j];
				}
				else
				{
					R[k].D[i][j]=R[k-1].D[i][j];
					R[k].P[i][j]=R[k-1].P[i][j];
				}
			}
		}
	}
}
int main()
{
	char a,b;
	int w;
	cout<<"Enter the no. of vertices: ";
	cin>>v;
	W=new int*[v];
	cout<<"Enter the no. of edges: ";
	cin>>e;
	for(int i=0;i<v;i++)
	{
		W[i]=new int[v];
		for(int j=0;j<v;j++)
		{
			if(i==j)
			W[i][j]=0;
			else
			W[i][j]=INT_MAX;
		}
	}
	cout<<"Enter edges and their corresponding weights: \n";
	for(int i=0;i<e;i++)
	{
		cin>>a>>b>>w;
		W[a-97][b-97]=w;
	}
	Floyd_Warshall(W,v);
	cout<<"Distance Matrix: \n";
	for(int i=0;i<v;i++)
	{
		for(int j=0;j<v;j++)
		cout<<R[v].D[i][j]<<"\t";
		cout<<endl;
	}
	cout<<"Parent Matrix: \n";
	for(int i=0;i<v;i++)
	{
		for(int j=0;j<v;j++)
		cout<<R[v].P[i][j]<<"\t";
		cout<<endl;
	}
	return 0;
}
