### Problem: [N-Palindromes](https://csacademy.com/ieeextreme-practice/task/n-palindromes/)
### Topic: Dynamic Programming

We are given a string of length L and a number N ( 0 <= N <= L <= 500 ). We want to
compute the number of palindromes that can be produced by changing exactly N characters from
the given string. All the letters are lowercase english characters. Since the output may be
too big, we will compute it modulo 10^9 + 7.

#### Finding a good state for our DP

We have to, somehow, define a subproblem that will allow us to easily associate it with smaller subproblems. In string problems it is common to use string prefixes, suffixes, or substrings from a point i to a point j. Since we are working with palindromes, it might be convenient to work with substrings from i to j (_that are also centered around the center of the original string_).

Let's use the state `dp[i][j][k]` which will denote the number of palindromes we can create by changing exactly k characters of the substring s[i..j] (inclusive). The answer to our problem will be `dp[0][L-1][N]`.

One base case will be the strings of length 1 `(i==j)`. In
that case all strings of length 1 are palindromes, therefore
we can change the character to any one of the other 25 in the alphabet, or leave it as it is:

```
dp(i,j,k):
  if ( i == j ):
    if ( k == 0 ) return 1;
    else if ( k == 2 ) return 25;
```

The above can only happen if L is odd `( L % 2 == 1 )`. If the length of the original string is even `( L % 2 == 0 )`, the smallest subproblem will be the strings of length 2. If s[i]==s[j] we can change both characters to any one from the 25 others and if s[i]!=s[j] we have to change either s[i] or s[j]:

```
dp(i,j,k):
  if ( i == j-1 ):
    if ( s[i] == s[j] ):
      if ( k == 0 ) return 1;
      if ( k == 1 ) return 0;
      if ( k == 2 ) return 25;
    else:
      if ( k == 0 ) return 0;
      if ( k == 1 ) return 2;
      if ( k == 2 ) return 24;
```

Let's try to solve the general case `dp[i][j][k]` using smaller subproblems.

There are two cases:
* `s[i] == s[j]`: In this case we can either change nothing or __change both__ characters to
any character from the remaining 25. The palindromes obtained by changing no characters at this
step is the answer to the subproblem `dp(i+1,j-1,k)`, while the answer to the other case will
be `25 * dp(i+1,j-1,k-2)`.

* `s[i] != s[j]`: In this case, we have to make s[i] the same with s[j] before proceeding to
smaller substrings. We can either change s[i] to be s[j] or change s[j] to be s[i]. The answer
will be `2 * dp(i+1,j-1,k-1)`. If we have more changes available `k >= 2`, we can also change both
characters to any of the 24 others `24 * dp(i+1,j-1,k-2)`.

Summarizing, for the general case:

```
dp(i,j,k):
  if ( s[i] == s[j] ):
    return 25 * dp(i+1,j-1,k-2) + dp(i+1,j-1,k);

  else:
    return 2 * dp(i+1,j-1,k-1) + 24 * dp(i+1,j-1,k-2);
```

#### State Space Reduction

We can observe that we are not visiting all substrings s[i..j] but only a small subset of them,
those that are centered around our original string's center! From a substring `(i,j)` we will only
go to a substring `(i+1,j-1)` and then to `(i+2,j-2)` etc. Notice that for every point (x,y) we visit, it holds that `x+y` is constant (and in fact `x+y = N-1`) and we can uniquely identify both coordinates by knowing one of them.
As a result, only one of them is needed in the state!

If you try to think intuitively about it, imagine that the pairs (x,y) of the states we visit,
when connected, form a geometric shape in R^2. In our case, this shape is a line (`x+y=c`)
which is 1d!

All in all, we can reduce our state to `(i,k)`, `(j,k)`, or generally `(d,k)`, with `d` being something
that encapsulates the information of `i` and `j`. We have noticed that the 2 indices are equally far from the
center of our original string. A good choice for `d` could be the distance from the center:

```
if ( L % 2 == 0 ):
  // d goes from 0 to L/2-1
  i = L/2-d-1;
  j = L/2+d;
else:
  // d goes from
  i = L/2-d;
  j = L/2+d;
```  
