#include <iostream>
#include <string>

#define MAX_LENGTH 100

using namespace std;

string s1,s2;
int l1,l2;
int memo[MAX_LENGTH][MAX_LENGTH]; //memo table for dp

void initialize(){
    for(int i=0;i<l1;i++){
        for(int j=0;j<l2;j++){
            memo[i][j]=-1;
        }
    }
}

int lcs(int i,int j){ // LCS for substrings [0..i] , [0..j]
    int result=0;

    if(i<0 || j<0) return 0;
    if(memo[i][j]!=-1) return memo[i][j];

    if(s1[i]==s2[j]) result= 1 + lcs(i-1,j-1);
    else result= max(lcs(i-1,j),lcs(i,j-1));

    memo[i][j]=result;
    return memo[i][j];
}

int main() {
	int T;

	cin>>T;

	while(T--){
	    cin>>l1>>l2;
	    cin>>s1>>s2;

	    initialize();

	    cout<<lcs(l1-1,l2-1)<<"\n";

	}
}
