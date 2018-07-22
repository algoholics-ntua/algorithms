### Problem: [Aibohphobia - SPOJ](https://www.spoj.com/problems/AIBOHP/)
### Topic: Dynamic Programming

__Problem Statement:__ Given a string s, insert the minimum number of characters to make it a palindrome.

Let's define the subproblem P(i,j) = { minimum number of insertions to make s[i..j] a palindrome }.
The desired answer can be calculated by P(0,s.length()-1).

As always, we will calculate P(i,j) recursively:

Case 1: If s[i]==s[j], then we only have to make s[(i+1)...(j-1)] a palindrome.

Case 2: If s[i]!=s[j], lets suppose s[i...j] = 'ABCCBCD'. i=0 / s[0]='A' , j=6, s[j]='D'

We can insert the character s[j] before index i, and then make s[i...(j-1)] a palindrome: '__D__ _ABCCBC_ __D__'

Or we can insert the character s[i] after index j, and then make s[(i+1)...j] a palindrome: '__A__ _BCCBCD_ __A__'

Summarizing,

```
P(i,j):

  if(s[i]==s[j]) return P(i+1,j-1);

  else
    return 1 + min(P(i,j-1), P(i+1,j));

```

The base case is P[k][k] = 0.
