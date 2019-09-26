#include<bits/stdc++.h>
#define lld long long int
#define ld long int
#define str string
#define dbl double
using namespace std;


void buildSegmentTree(int tree[],int values[],int index,int start,int end){
	if(start>end) return;
	if(start==end){
		tree[index]=values[start];
	}
	else{
		int mid = (start+end)/2;

		//left subTree
		buildSegmentTree(tree,values,2*index,start,mid);
		//right subTree
		buildSegmentTree(tree,values,2*index+1,mid+1,end);

		tree[index] = tree[2*index]+tree[2*index+1];
	}
}

void updateNode(int tree[],int s,int e,int index,int ind,int val){
	if(ind<s or ind>e) return;
	else if(s==e){
		tree[index] = val;
		return;
	}
	//left subtree call
	int mid = (s+e)/2;
	updateNode(tree,s,mid,2*index,ind,val);
	updateNode(tree,mid+1,e,2*index+1,ind,val);
	tree[index] = tree[2*index]+tree[2*index+1];
	return;
}

int rangeSumQuery(int tree[],int index,int start,int end,int qStart,int qEnd){
	if(qStart>end or qEnd<start) return 0;
	if(qStart<=start and qEnd>=end) return tree[index];
	
	int mid = (start+end)/2;
	int left = rangeSumQuery(tree,2*index,start,mid,qStart,qEnd);
	int right = rangeSumQuery(tree,2*index+1,mid+1,end,qStart,qEnd);
	return left+right;
	
}

int main(){
	int values[] = {1,3,2,-2,4,5,8,12,10,40};
	int size = sizeof(values)/sizeof(values[0]);
	int *segmentTree = new int[4*size+1];
	buildSegmentTree(segmentTree,values,1,0,size-1);
	updateNode(segmentTree,0,size-1,1,4,5);
	cout<<rangeSumQuery(segmentTree,1,0,size-1,0,4);
	return 0;
}