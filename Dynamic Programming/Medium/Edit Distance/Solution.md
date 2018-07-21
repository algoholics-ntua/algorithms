### Problem: [Edit Distance](https://practice.geeksforgeeks.org/problems/edit-distance/0)
### Topic: Dynamic Programming

Problem statement : Given two strings (s1, s2) calculate the minimum number of operations (insert, remove, replace) required to convert s1 into s2.

This is a classical DP problem with optimal substructure property. We will use the prefixes of the strings to define the subproblem  T(n,m) = { min cost to convert s1[0..n] to s2[0..m] }. Obviously, the answer we are looking for is T(|s1|-1, |s2|-1).

We will compute T(n,m) by using smaller subproblems while performing all the possible operations.
Start by looking at the end of the strings:

* If the last characters are the same, we just have to make the rest of the strings identical:

```
if( s1[n] == s2[m] ) then T(n,m) = T(n-1,m-1)
```

* If the last characters are not the same, then we have to make an operation to fix them and then recursively make the rest of the strings identical:

For example, let s1 = 'ABCC' and s2 = 'ABCDE'. The last characters are not the same ( 'C' != 'E' ).

Possible moves to fix the last chars:

1) Insert 'E' at the end of s1 which is the same as the last char of s2 and we recursively solve for s1 = 'ABCC' and s2 = 'ABCD'
In the general case that will cost: T(n,m) = 1 + T(n,m-1)

2)  Replace the letter 'C' at the end of s1 with an 'E' and solve recursively for s1 = 'ABC' and s2 = 'ABCD'
In the general case that will cost: T(n,m) = 1 + T(n-1,m-1)

3) Remove the last letter of s1 and try to recursively solve for s1 = 'ABC' and s2 = 'ABCD'
In the general case that will cost: T(n,m) = 1 + T(n-1,m)

So,

```
if( s1[n] != s2[m] ) then T(n,m) = 1 + min( T(n-1,m), T(n-1,m-1), T(n,m-1) )
```

Base case:

If either of the strings are empty, the conversion cost will be the length of the other string.
