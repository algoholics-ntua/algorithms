#include <cstdio>
#include <cstring>

#define MAX_N 50

using namespace std;

int T,N;
int a[MAX_N+1];

int hops(int n){

  if(n<0) return 0;

  if(n==0) return 1;

  if(a[n]!=0) return a[n];

  int result = hops(n-1) + hops(n-2) + hops(n-3);

  a[n] = result;

  return result;
}

int main(){
  scanf("%d",&T);

  memset(a,0,sizeof(a[0])*(MAX_N+1)); //initialization

  while(T--){
    scanf("%d",&N);
    //no need for initialization of the a array
    //some answers will have been computed in previous testcases
    //and we are solving the same problem with different size
    printf("%d\n",hops(N));
  }
}
