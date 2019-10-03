#include<iostream>
#include<algorithm>
#include"disjoint.h"
using namespace std;
struct edge
{
	char v1,v2;
	int w;
}*E,*MST;
int v,e,t,*rank;
char *P;
bool comp(edge e1,edge e2)
{
	return (e1.w<e2.w);
}
void MST_kruskal()
{
	t=0;
	MST=new edge[v-1];
	sort(E,E+e,comp);
	for(int i=0;i<e;i++)
	{
		if(find_set(E[i].v1,P,rank)!=find_set(E[i].v2,P,rank))
		{
			MST[t++]=E[i];
			union_set(E[i].v1,E[i].v2,P,rank);
		}
	}
}
int main()
{
	char a,b;
	cout<<"Enter no. of vertices: ";
	cin>>v;
	cout<<"Enter no. of edges: ";
	cin>>e;
	P=new char[v];
	rank=new int[v];
	cout<<"Enter the end vertices of the edges and their corresponding weights: \n";
	E=new edge[e];
	for(int i=0;i<v;i++)
	P[i]=' ';
	for(int i=0;i<e;i++)
	{
		cin>>E[i].v1>>E[i].v2>>E[i].w;
		makeset(E[i].v1,P,rank);
		makeset(E[i].v2,P,rank);
	}
	MST_kruskal();	
	cout<<"Resultant Minimum Spanning Tree: \n";
	cout<<"Edge \t"<<" Weight\n";
	for(int i=0;i<t;i++)
	cout<<MST[i].v1<<"---"<<MST[i].v2<<"  \t  "<<MST[i].w<<endl;
	return 0;
}
