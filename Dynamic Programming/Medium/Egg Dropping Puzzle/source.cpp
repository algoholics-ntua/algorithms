#include <cstdio>
#include <climits>

#define MAX_K 10
#define MAX_N 100

using namespace std;

int DP[MAX_N+1][MAX_K+1];
int N,K,T;

inline int max(int a,int b){ return (a>b) ? a:b;}
inline int min(int a,int b){ return (a<b) ? a:b;}

void initialize(){
    for(int i=0;i<=N;i++){
        for(int j=0;j<=K;j++){
            if(j==0) DP[i][j]=0;
            else if(j==1) DP[i][j]=i;
            else if(i==0) DP[i][j]=0;
            else DP[i][j]=-1;
        }
    }
}

int dp(int n,int k){
    if(DP[n][k]!=-1) return DP[n][k];
    int ans=INT_MAX;

    for(int i=1;i<=n;i++){
        ans=min(ans,1+max(dp(i-1,k-1),dp(n-i,k)));
    }
    DP[n][k]=ans;
    return ans;
}

int main(){
    scanf("%d",&T);
    while(T--){

        scanf("%d",&K);
        scanf("%d",&N);

        initialize();

        printf("%d\n",dp(N,K));
    }
}
