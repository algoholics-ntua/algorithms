### Problem: [Count Number Of Hops](https://practice.geeksforgeeks.org/problems/count-number-of-hops/0)
### Topic: Dynamic Programming


__Problem Statement:__ Given a number N, calculate all the possible ways we can go to step N, starting from 0, if we can move 1, 2 or 3 steps at a time.

To arrive at the step N, our previous one was N-1, N-2 or N-3, because we can only move 1, 2 or 3 steps in one move.
So, the number of ways we can get to N, is equal to the sum of ways we can go to N-1, N-2 and N-3.

```
T(n):
  if(n==0) return 1;
  if(n<0) return 0;

  return T(n-1) + T(n-2) + T(n-3)
```

The above solution has a time complexity of Θ(3^n)!!! But we notice that there are many overlapping subproblems:


```
                   T(3)
               /    |    \
             /      |      \
           T(0)    T(1)    T(2)
                    |     /   \
                   T(0) T(0)  T(1)
                               |
                              T(0)
```

We can use the method of memoization to make sure we only compute each task once. The memoized solution has Θ(n) complexity.
