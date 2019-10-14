#include<iostream>
using namespace std;
int e,v;
char *Q;
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
char Extract_Min()
{
	char min;
	int k=INT_MAX;
	int pos;
	for(int i=0;i<v;i++)
	{
		if(k>V[i].d&&Q[i]!=' ')
		{
			min=Q[i];
			pos=i;
			k=V[i].d;
		}
	}
	Q[pos]=' ';
	return min;
}
void dijkstra(char s)
{
	int qs=v;
	char u,r=Q[s-97];
	V[s-97].d=0;
	while(qs--)
	{
		u=Extract_Min();
		//cout<<u<<" ";
		for(int i=0;i<e;i++)
		{
			if(E[i].v1==u)
			{
				if((Q[(E[i].v2)-97]!=' ')&&((E[i].w+V[u-97].d)<V[(E[i].v2)-97].d))
				{
					V[(E[i].v2)-97].P=E[i].v1;
					V[(E[i].v2)-97].d=E[i].w+V[u-97].d;
				}
			}
			else if(E[i].v2==u)
			{
				if((Q[(E[i].v1)-97]!=' ')&&((E[i].w+V[u-97].d)<V[(E[i].v1)-97].d))
				{
					V[(E[i].v1)-97].P=E[i].v2;
					V[(E[i].v1)-97].d=E[i].w+V[u-97].d;
				}
			}
		}
	}
}
int main()
{
	char s;
	cout<<"Enter no. of vertices: ";
	cin>>v;
	V=new vertex[v];
	Q=new char[v];
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
		Q[i]=i+97;		
	}	
	cout<<"Enter the souce vertex: ";
	cin>>s;
	dijkstra(s);
	cout<<"Shortest Distance from "<<s<<":\n";
	for(int i=0;i<v;i++)
	cout<<V[i].v<<" = "<<" \t "<<V[i].d<<endl;
	return 0;
}
