### Problem: [Subset Sum](https://practice.geeksforgeeks.org/problems/subset-sum-problem/0)
### Topic: Dynamic Programming

Problem Statement: Given an array of N numbers, determine if we can partition them into two subsets with the same sum.

Let the sum of the numbers be S ( S = a[0] + ... + a[N-1] ). The two subsets should have the same sum, so if S is an odd number, then there is no such partition.

If S is even ( S%2==0 ), we need to create two subsets with sum S/2. Choosing the first subset, uniquely determines the second one. So our problem is just to find a group of numbers with sum equal to S/2.

Lets define the subproblem T(n,s) = { True iff we can find a subset in a[0..n] with sum s }. The answer to our problem will be T(N-1,S/2).

We will calculate T(n,s) recursively. For every element, there are only 2 options: either we will include it to our subset, or we won't.

If a[n] is included in the subset, then T(n,s) is true if and only if we can create a subset with numbers in range [0..n-1] that  sum up to s-a[n].

Similarly, if a[n] is not included, then T(n,s) is true if and only if we can create a subset with numbers in range [0..n-1] that sum up to s.

```
T(n,s) = T(n-1,s-a[n]) || T(n-1,s)
```

Our base cases are:

```
T(0,0) = True
T(0,a[0]) =  True
T(0,k) = False for k!=0 && k!=a[0]
```
