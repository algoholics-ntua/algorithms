### Problem: [The Painter's Partition Problem](https://practice.geeksforgeeks.org/problems/the-painters-partition-problem/0)
### Topic: Dynamic Programming

We notice that our problem has the __optimal substructure property__ and we can approach it with Dynamic Programming.
Consider the subproblem T(n,k) = {minimum time to paint boards 0..n with k painters}, the answer we are looking for will be __T(N-1,K)__.

In such problems, it is helpful to build the solution as a sequence of steps _( e.g. how many boards will the 1st painter paint, how many will the second one paint, etc. )_
and try to build a recursive formula while making all the possible selections for the first (or last) step.

In this particular problem, T(n,k) , the k-th painter can paint _from 1 up to n boards_. Let's assume that he paints i boards, the time needed for the whole wall to be painted will be the maximum between the working time of the k-th painter and the minimum time needed to paint the first n-i boards with k-1 painters. So if k-th painter paints i boards, T(n,k) can be computed as:

```
 max{ A[n] + A[n-1] ... + A[n-i+1] , T(n-i,k-1) }
```

So, the total answer will be the minimum over all possible values for i:

```
T(n,k) = min{ for all i: max{ A[n] + A[n-1] ... + A[n-i+1] , T(n-i,k-1) } }
```

Base cases :

* If we want to paint the first board, the answer will be A[0] : T(0,k) = A[0]
* If only one painter is available, the cost will be the summation of lengths : T(n,1) = A[0]+...+A[n]

The time complexity is O(K*N^2) which passes the time limit.
