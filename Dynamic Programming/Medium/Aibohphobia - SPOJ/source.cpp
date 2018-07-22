#include <iostream>
#include <string>

#define MAX_S 6100

using namespace std;

int T;
string s;
int memo[MAX_S][MAX_S]; //memo table for the dp function makePalindrome
void initialize(){
    int length=s.length();
    for(int i=0;i<length;i++){
        for(int j=0;j<length;j++){
            memo[i][j]=-1;
        }
    }
}

int makePalindrome(int i,int j){
    int answer;
    if(i==j) return 0;
    if(memo[i][j]!=-1) return memo[i][j];

    if(s[i]==s[j]) answer=makePalindrome(i+1,j-1);
    else answer = min(makePalindrome(i+1,j),makePalindrome(i,j-1)) + 1;

    memo[i][j]=answer;
    return answer;
}

int main(){
    cin>>T;
    while(T--){
        cin>>s;
        initialize();
        printf("%d\n",makePalindrome(0,s.length()-1));
    }
}
