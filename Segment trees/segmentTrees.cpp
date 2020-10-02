#include<bits/stdc++.h>
#define lld long long int
#define ld long int
#define str string
#define dbl double
using namespace std;

//to update in a given range
void updateRange(int tree[],int s,int e,int index,int qs,int qe,int inc){
	if(s>qe or e<qs){
		return;
	}
	if(s==e){
		tree[index]+=inc;
		return;
	}

	int mid = (s+e)/2;
	updateRange(tree,s,mid,2*index,qs,qe,inc);
	updateRange(tree,mid+1,e,2*index+1,qs,qe,inc);
	tree[index] = min(tree[2*index],tree[2*index+1]);
	return;
}

//to update at particular index
void updateNode(int tree[],int s,int e,int index,int ind,int val){
	if(ind<s or ind>e) return;
	else if(s==e){
		tree[index] = val;
		return;
	}
	int mid = (s+e)/2;
	updateNode(tree,s,mid,2*index,ind,val);
	updateNode(tree,mid+1,e,2*index+1,ind,val);
	tree[index] = min(tree[2*index],tree[2*index+1]);
	return;
}
//building segment tree
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

		tree[index] = min(tree[2*index],tree[2*index+1]);
	}
}

//give minimum element in given range
int minElementQuery(int tree[],int index,int start,int end,int qStart,int qEnd){
	if(qStart>end or qEnd<start) return INT_MAX;
	if(qStart<=start and qEnd>=end) return tree[index];
	
	int mid = (start+end)/2;
	int left = minElementQuery(tree,2*index,start,mid,qStart,qEnd);
	int right = minElementQuery(tree,2*index+1,mid+1,end,qStart,qEnd);
	return min(left,right);
	
}

int main(){
	int values[] = {1,3,2,-2,4,5};
	int size = 6;
	int *segmentTree = new int[4*size+1];
	buildSegmentTree(segmentTree,values,1,0,size-1);
	cout<<"minimum value is : "<<segmentTree[1]<<endl;
	cout<<minElementQuery(segmentTree,1,0,size-1,0,5)<<endl;
	updateNode(segmentTree,0,5,1,5,-8);
	updateRange(segmentTree,0,5,1,0,3,-10);
	cout<<minElementQuery(segmentTree,1,0,size-1,0,5)<<endl;
	return 0;
}
