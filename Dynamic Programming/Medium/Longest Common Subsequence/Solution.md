### Problem: [Longest Common Subsequence](https://practice.geeksforgeeks.org/problems/longest-common-subsequence/0)
### Topic: Dynamic Programming

__Problem Statement:__ Given two strings (s1 and s2), we have to find the longest subsequence present in both of them.
Note that the subsequences are not necessarily continuous substrings. For example, "ABC" is a subsequence of "ADDBDC".

We can work with the subproblem of finding LCS in prefixes of the given strings. In that case, let __LCS(i,j)__ be the Longest Common Subsequence of the strings __s1[0..i]__  ,  __s2[0..j].__ The answer to our problem will be LCS( |s1|-1 , |s2|-1 ). Also, LCS has the optimal substructure property.

We notice that

```
if s1[i] == s2[j] then LCS(i,j) = 1 + LCS(i-1,j-1)

else LCS(i,j) = max{ LCS(i-1,j), LCS(i,j-1) }

```
Our base case is LCS(0,0) = ( s1[0]==s2[0] ) ? 1:0
