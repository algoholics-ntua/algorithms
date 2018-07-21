#include <iostream>
#include <string>

#define MAX_LENGTH 100

using namespace std;

string s1,s2;
int memo[MAX_LENGTH][MAX_LENGTH];
int T,length1,length2;

int min(int x, int y, int z){ return min(x,min(y,z)); }

void initialize(int l1, int l2){

    for(int i=0;i<l1;i++){
        for(int j=0;j<l2;j++){
            memo[i][j]=-1;
        }
    }
}


int dp(int i, int j){
// edit distance of strings s1[0..i], s2[0..j]

    if(i==-1){ //if s1 is empty
        return j+1; //edit distance is |s2|
    }

    if(j==-1){
        return i+1;
    }

    if(memo[i][j]!=-1){
        return memo[i][j];
    }

    int result;
    if(s1[i]==s2[j]){
        result = dp(i-1,j-1);
    }

    else{
        result = 1 + min( dp(i-1,j-1) , dp(i,j-1), dp(i-1,j) );
                        // replace, insert, remove on s1
    }

    memo[i][j]=result;

    return result;
}


int main(){

    ios_base::sync_with_stdio(false);

    cin>>T;

    while(T--){
        cin>>length1>>length2>>s1>>s2;

        initialize(length1,length2);

        cout<<dp(length1-1,length2-1)<<"\n";
    }

}
