#include <cstdio>

#define MAX_N 100
#define MAX_W 100

using namespace std;

int N,T,W;
int weight[MAX_N],value[MAX_N];
int memo[MAX_N][MAX_W+1];

int max(int x, int y){ return (x>y) ? x:y; }

void initialize(){
  for(int i=0;i<MAX_N;i++){
    for(int j=0;j<=MAX_W;j++){
      memo[i][j]=-1;
    }
  }
}

int dp(int n, int w){
  if(memo[n][w]!=-1) return memo[n][w];

  if(n==0) return (w>=weight[0]) ? value[0]:0;

  int result;

  if(w<weight[n]) result = dp(n-1,w);
  else result = max(dp(n-1,w),value[n]+dp(n-1,w-weight[n]));

  memo[n][w]=result;

  return result;

}


int main(){
  scanf("%d",&T);

  while(T--){
    scanf("%d",&N);
    scanf("%d",&W);

    for(int i=0;i<N;i++) scanf("%d",&value[i]);
    for(int i=0;i<N;i++) scanf("%d",&weight[i]);

    initialize();

    printf("%d\n",dp(N-1,W));

  }
}
