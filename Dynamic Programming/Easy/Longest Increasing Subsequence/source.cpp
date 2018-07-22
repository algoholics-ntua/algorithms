#include <iostream>
#include <string>
#include <cstring>

#define MAX_N 1000

using namespace std;

int N,T;
int a[MAX_N],memo[MAX_N];

int LIS(int k){
// Longest Increasing Subsequence that ends at index k
  if(memo[k]!=0) return memo[k];

  int result = 1;

  for(int i=0;i<k;i++){
    if(a[i]<a[k]){
      result = max(result, 1 + LIS(i));
    }
  }

  memo[k] = result;
  return result;
}

void initialize(int n){
  memset(memo,0,sizeof(memo[0])*n);
  // we initialize to 0, because 0 is not a valid answer
  //each lis(i) is at least 1.
}

int main(){
  ios_base::sync_with_stdio(false);

  cin>>T;

  while(T--){
    cin>>N;

    for(int i=0;i<N;i++) cin>>a[i];

    if(N==0){
      cout<<"0\n"; //geeksforgeeks have test cases with N=0...
      continue;
    }

    initialize(N);

    int result = 1;

    for(int i=0;i<N;i++) result = max(result,LIS(i));

    cout<<result<<"\n";
  }
}
