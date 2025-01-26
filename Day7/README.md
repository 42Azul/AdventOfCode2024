# Day 7: Bridge Repair

## Part 1  
**Difficulty:** 🌖🌑🌑🌑🌑  

**Approach & Solution:**  
Today's challenge was all about fixing a broken bridge by verifying calibration equations. Essentially, each equation was missing operators between numbers, and our task was to determine which combinations of addition and multiplication could recreate the given test values.  

<details>  
<summary>Detailed Explanation (Click to expand)</summary>  
The process involved recursively evaluating the possible sequences of operations left-to-right:  

1. Parsing the input to separate the test value from the sequence of numbers.
2. Using recursion to try all possible insertions of `+` and `*` operators between numbers.
3. If any combination resulted in the expected test value, the equation was considered valid.
4. The final answer was the sum of all valid test values.

To sum up, a depth-first search (DFS)-style recursive function was used to explore all valid expressions while ensuring left-to-right evaluation.
Also, to improve a bit the performance, as all operations are incresing, in case the actual result is greater than the expected result, we stop searching.

</details>  

---

## Part 2  
**Difficulty:** 🌖🌑🌑🌑🌑  

**Approach & Solution:**  
Part 2 introduced a sneaky third operator: concatenation (`||`). This meant that instead of just adding or multiplying, numbers could also be merged into a single value. 

<details>  
<summary>Detailed Explanation (Click to expand)</summary>  
Building on Part 1, the approach expanded to include concatenation:

1. A helper function was added to merge numbers correctly, treating them as digit strings.
2. The recursive function was updated to also test concatenation as a valid operation.
This significantly increased the number of possible expressions, but the overall logic remained the same.
However,implementation wise, no big changes were actually made.

</details>  

---

## Conclusions and Thoughts  
This problem was simple expression evaluation with a left-to-right constraint. Part 1 felt like a classic brute-force validation, and part 2 did not add a lot to the problem.

The recursion-based approach worked well, though optimizations like memoization could potentially help with larger inputs. Also the recursion could be removed and use a loop-like approach too.
