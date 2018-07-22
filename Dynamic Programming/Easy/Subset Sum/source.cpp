#include <cstdio>

#define MAX_N 100
#define MAX_Ai 1000

using namespace std;

int T,N,a[MAX_N];
int sum;
int memo[MAX_N][MAX_N*MAX_Ai];
// -1 => not calculated, 0 => false, 1 => true

bool dp(int n, int s){

    if(memo[n][s]!=-1) return (memo[n][s]==1);

    if(n==0) return (s==0 || s==a[0]);

    bool result = dp(n-1,s-a[n]) || dp(n-1,s);

    memo[n][s] = (result) ? 1:0;

    return result;

}

void initialize(int n, int s){
    for(int i=0;i<n;i++){
        for(int j=0;j<=s;j++){
            memo[i][j]=-1;
        }
    }
}

int main(){

    bool result;

    scanf("%d",&T);

    while(T--){
        scanf("%d",&N);

        sum = 0;

        for(int i=0;i<N;i++){
            scanf("%d",&a[i]);
            sum+=a[i];
        }

        if( sum%2!=0 ) {
            printf("NO\n");
        }

        else{
            initialize(N,sum/2);
            result = dp(N-1,sum/2);
            if(!result) printf("NO\n");
            else printf("YES\n");
        }
    }

}
