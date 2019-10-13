#include <iostream>
#include <string>
#include <cstring>

#define MAX_N 505
#define P 1000000007
#define ll long long

using namespace std;

int T,N,L;
string s;
int memo[MAX_N][MAX_N];

ll dp(int d, int n){
    if( n < 0 ) return 0;
    if(L%2==0 && d==0){
        if(s[L/2-1]==s[L/2]){
            if(n==0) return 1;
            if(n==1) return 0;
            if(n==2) return 25;
            else return 0;
        }
        else{
            if(n==0) return 0;
            if(n==1) return 2;
            if(n==2) return 24;
            else return 0;
        }
    }

    if(L%2!=0 && d==0){
        if(n==0) return 1;
        if(n==1) return 25;
        else return 0;
    }

    if(memo[d][n]!=-1) return memo[d][n];

    int i,j,ans;
    if(L%2 == 0){
        // d goes from 0 to L/2-1
        i = L/2-d-1;
        j = L/2+d;

    }
    else{
        // d goes from 0 to L/2
        i = L/2-d;
        j = L/2+d;
    }

    if(s[i]==s[j]) ans = ( (25*dp(d-1,n-2))%P + dp(d-1,n) )%P;
    else ans = ((2*dp(d-1,n-1))%P + (24*dp(d-1,n-2))%P)%P;

    memo[d][n] = ans;

    return ans;
}

int main() {
    cin>>T;
    while(T--){
        cin>>N>>s;
        memset(memo,-1,sizeof(int)*MAX_N*MAX_N);

        L = s.size();

        if(L%2==0) cout<<dp(L/2-1,N)<<endl;
        else cout<<dp(L/2,N)<<endl;
    }

}
