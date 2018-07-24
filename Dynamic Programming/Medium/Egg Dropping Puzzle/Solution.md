### Problem: [Egg Dropping Puzzle](https://practice.geeksforgeeks.org/problems/egg-dropping-puzzle/0)
### Topic: Dynamic Programming

Let's define the subproblem T(n,k) = { minimum number of drops to determine the critical floor, when searching n floors with k eggs }.

When we are trying to solve T(n,k), we can drop the first egg from any floor in range [1..n]. If we drop it from floor i, there are two cases:

Case 1: If the egg breaks, we know that it would break in all floors above i. So we now have to search the first i-1 floors with k-1 remaining eggs

```
Case 1: T(n,k) = 1 + T(i-1,k-1)
```

Case 2: If the egg doesn't break, it would not break in all floors bellow i. So we now have to search the last n-i floors with k eggs, because we can reuse the egg that didn't break.

```
Case 2: T(n,k) = 1 + T(n-i,k)
```

So if we drop an egg from floor i, the answer is the maximum of the above (because we are looking the optimal number in the worst case scenario ):

```
T(n,k) = 1 + max( T(n-i,k), T(i-1,k-1) )
```

We now just have to take the minimum for all possible first-floors:

```
T(n,k) = 1 +  for i->[1..n] : min{ max{ T(n-i,k), T(i-1,k-1) } }
```

Base cases:

```
T(n,1) = n
T(1,k) = 1
```
