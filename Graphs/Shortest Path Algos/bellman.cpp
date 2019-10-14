#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int e,v;
struct edge
{
	char v1,v2;
	int w;
}*E;
struct vertex
{
	char v,P;
	int d;
}*V;
bool BellmanFord(char s)
{
	V[s-97].d=0;
	for(int j=1;j<v;j++)
	{
		for(int i=0;i<e;i++)
		{
			if(E[i].w+V[(E[i].v1)-97].d<V[(E[i].v2)-97].d)
			{
				V[(E[i].v2)-97].P=E[i].v1;
				V[(E[i].v2)-97].d=E[i].w+V[(E[i].v1)-97].d;
			}
		}
	}
	for(int i=0;i<e;i++)
	{
		if(E[i].w+V[(E[i].v1)-97].d<V[(E[i].v2)-97].d)
		return false;
	}
	return true;
}
int main()
{
	char s;
	cout<<"Enter no. of vertices: ";
	cin>>v;
	V=new vertex[v];
	cout<<"Enter no. of edges: ";
	cin>>e;
	E=new edge[e];
	cout<<"Enter edges and their weights: \n";
	for(int i=0;i<e;i++)
		cin>>E[i].v1>>E[i].v2>>E[i].w;
	for(int i=0;i<v;i++)
	{
		V[i].v=i+97;
		V[i].d=INT_MAX;
		V[i].P=' ';
	}
	cout<<"Enter the souce vertex: ";
	cin>>s;
	bool res=BellmanFord(s);
	if(res==false)
	{
		cout<<"Negative weight cycle exists in graph!!!\n";
		cout<<"Bellman Ford Algorithm Fails!!!";
	}
	else
	{
		cout<<"Shortest Distance from "<<s<<":\n";
		for(int i=0;i<v;i++)
		cout<<V[i].v<<" = "<<" \t "<<V[i].d<<endl;
	}
	return 0;
}