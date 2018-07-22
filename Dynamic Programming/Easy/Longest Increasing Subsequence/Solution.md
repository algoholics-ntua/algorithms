### Problem: [Longest Increasing Subsequence](https://practice.geeksforgeeks.org/problems/longest-increasing-subsequence/0)
### Topic: Dynamic Programming

Problem Statement: Given an array of N numbers, we need to calculate the Longest Increasing Subsequence, meaning the longest subsequence ( not necessarily continuous ) that its elements are in sorted order with no duplicates allowed.

The problem has the optimal substructure property, so we can approach it with DP. The subsequence we are looking for, will end in one of the N elements of the array. Let's define the subproblem LIS(i) = { longest increasing subsequence that ends at index i }. The answer we are looking for will be the maximum LIS(i) for i -> [0..N-1].

The LIS ending at index i, can either be just a[i], or a sequence that its previous value is any number in a[0..i-1] which is less than a[i].

In the first case the answer is LIS(i) = 1.
In the second case, if the previous value is a[k], then the answer will be 1 plus the LIS ending at index k : 1 + LIS(k). To obtain the answer, we must find the maximum for all possible values of k:

```
LIS(i):
  result = 1
  for(int k=0; k<i; k++ ){
    if(a[k]<a[i]) {
      result = max(result, 1+LIS(k) );
    }
  }
```

The time complexity is O(n^2) which passes the given time limit.
