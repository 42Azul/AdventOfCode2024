
# Day 3: Mull It Over

## Part 1  
**Difficulty:** 🌗🌑🌑🌑🌑  

**Approach & Solution:**  
This task was all about reading the input in the search of `mul(X,Y)` instructions. It wasn’t about anything fancy—just careful parsing and ensuring you skip the unused characters.

<details>  
<summary>Detailed Explanation (Click to expand)</summary>  
The code scanned the input character by character, searching for patterns that matched the format `mul(X,Y)`. Here’s the breakdown:  

1. A `toCheck` string helped track whether we were mid-parsing a valid `mul` instruction.  
2. Once inside a valid `mul` block, digits for `X` and `Y` were parsed and multiplied.  
3. Any mismatched characters or sequences reset the parser to avoid errors.  
4. Finally, the results of all valid `mul` instructions were added up and printed.  

No complex algorithms here—just parsing, validating, and summing!  
</details>  

---

## Part 2  
**Difficulty:** 🌗🌑🌑🌑🌑  

**Approach & Solution:**  
The second part added some state management by introducing `do()` and `don't()` instructions, which toggled whether `mul` operations were active.  

<details>  
<summary>Detailed Explanation (Click to expand)</summary>  
Building on Part 1:  

1. Two new strings, `do()` and `don't()`, were used to track the active state of `mul` instructions.  
2. Each character of the input was checked against these state-changing commands.  
3. Only when the `enabled` state was `true` were valid `mul` instructions parsed and their results added to the sum.  
4. If a `don't()` appeared, subsequent `mul` instructions were ignored until a `do()` reset the state.  
5. For parsing the numbers, we just read them and multiply by 10 knowing they can not be more than 3 digits long.

The only challenge here was maintaining the different states of the parser.
</details>  

---

## Conclusions and Thoughts  
Honestly, this puzzle felt simpler than Day 2. It was all about input parsing and keeping track of state changes, which isn’t particularly groundbreaking.  

The first part was straightforward—just pick out the valid instructions and multiply the numbers. The second part added a bit more complexity with `do()` and `don't()`, but it was still pretty mechanical.  

While it was satisfying to do it quickly as I was late in the AoC challenge, this day problem didn’t require much creativity.