### Problem: [0-1 Knapsack](https://practice.geeksforgeeks.org/problems/0-1-knapsack-problem/0)
### Topic: Dynamic Programming

__Problem Statement:__ Given N items with certain values and weights, and a knapsack with capacity W, calculate the maximum total value we can put in our knapsack. Note that we can either take an item or not, we can not take a portion of it.

Let's define the subproblem T(n,w) = {maximum value we can fit in a knapsack of capacity w, using items [0..n]}. The answer to our problem will be T(N-1,W).

We will try to calculate T(n,w) recursively. There are 2 options for the n-th item, we can either put it in the knapsack or not.

If we put it in the knapsack, we now have W-weight[n] remaining capacity to fill with [0..(n-1)] items, but we have increased the value of the knapsack by value[n].

If we don't take the n-th item, then we just have W capacity to fill with [0..(n-1)] items.

Of course, if the weight of an item is bigger than the remaining capacity then we can not take it and we fall to case 2.

```
T(n,w) = max( T(n-1,w) , value[n] + T(n-1,w-weight[n]) )
```

Our base case is for n==0:

```
if(w<weight[0]) result = 0;
else result = value[0];
```

0-1 Knapsack is a classic DP problem, you can find many tutorials on the web, like [this](https://www.youtube.com/watch?v=8LusJS5-AGo) one.
