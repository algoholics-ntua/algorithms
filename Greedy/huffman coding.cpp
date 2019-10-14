#include<iostream>
#include<string>
#include<algorithm>

using namespace std;
sturct node{
    int freq,sysindex;
    char *binarycode;
    char *left, *right;
}*Q[50];

int m=0;
char *lstring, *rstring;
node *Extract_Min(){
    node *min=Q[m++];
    return min;
}

void insertqueue(node *root, int qs){
    int pos=qs;
    for(int i=m;i<qs;i++){
        if(Q[i]->freq > root->freq){
            pos=i;
            break;
        }
    }
    for(i=qs;i>pos;i--){
        Q[i]=Q[i-1];
    }

    Q[pos}=root;
    qs++;
}

void generatecode(node *root, char *code[50], int n){
    if(root->left==NULL){
        code[root->sysindex]=new char[n];
        strcpy(code[root->sysindex],root->binarycode);
    }
    else{
        strcpy()

    }
}
