#include<iostream>
#include<climits>
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
	int key;
}*V;
char Extract_Min()
{
	char min;
	int k=INT_MAX;
	int pos;
	for(int i=0;i<v;i++)
	{
		if(k>V[i].key&&Q[i]!=' ')
		{
			min=Q[i];
			pos=i;
			k=V[i].key;
		}
	}
	Q[pos]=' ';
	return min;
}
void MST_Prim()
{
	int qs=v;
	char u;
	V[0].key=0;
	while(qs--)
	{
		u=Extract_Min();
		//cout<<u<<" ";
		for(int i=0;i<e;i++)
		{
			if(E[i].v1==u)
			{
				if((Q[(E[i].v2)-97]!=' ')&&(E[i].w<V[(E[i].v2)-97].key))
				{
					V[(E[i].v2)-97].P=E[i].v1;
					V[(E[i].v2)-97].key=E[i].w;
				}
			}
			else if(E[i].v2==u)
			{
				if((Q[(E[i].v1)-97]!=' ')&&(E[i].w<V[(E[i].v1)-97].key))
				{
					V[(E[i].v1)-97].P=E[i].v2;
					V[(E[i].v1)-97].key=E[i].w;
				}
			}
		}
	}
}
int main()
{
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
		V[i].key=INT_MAX;
		V[i].P=' ';
		Q[i]=i+97;		
	}	
	MST_Prim();
	cout<<"Resultant Minimum Spanning Tree: \n";
	cout<<"Edge \t"<<" Weight\n";
	for(int i=1;i<v;i++)
	cout<<V[i].v<<"---"<<V[i].P<<" \t "<<V[i].key<<endl;
	return 0;
}
