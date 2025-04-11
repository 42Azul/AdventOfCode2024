
# Day 22: Monkey Market

## Part 1  
**Difficulty:** 🌗🌑🌑🌑🌑  

**Approach & Solution:**  
The first part was all about simulating a pseudorandom number generator used by banana-hungry monkeys.  For this we had to predict the 2000th value in the sequence for each monkey given an initial number and a quirky transformation process.

<details>  
<summary>Detailed Explanation (Click to expand)</summary>  

We just have to apply the transformation

1. Multiply by 64, XOR with the secret number, prune via modulo  
2. Divide by 32, XOR again, prune again  
3. Multiply by 2048, XOR again, prune again  

And by “prune”, they meant taking the result modulo `2^24` (aka 16777216).

In the code, this was compacted into a neat `calculateNewSecretNumber` function using bit shifts to handle those multiplications/divisions efficiently. For each input, the loop runs this transformation **2000 times**, and sums up the final result of each to get the answer.

</details>  

---

## Part 2  
**Difficulty:** 🌕🌕🌑🌑🌑

**Approach & Solution:**  
In Part 2, things got a bit more complex. Now those monkey numbers were used to *generate prices*, and we had to find **one** specific pattern of price changes (like -2, +1, -1, +3) that would make the monkey sell at the *best possible moment* for as many buyers as possible. 

<details>  
<summary>Detailed Explanation (Click to expand)</summary>  

This was a pattern-matching optimization challenge wrapped in a price simulation.

Each monkey outputs 2000 pseudorandom numbers. From each one, we extract the **ones digit** (modulo 10) to get the price. Then we track the differences between consecutive prices — like if prices were 3 → 5 → 4 → 6 → 3, the diffs are +2, -1, +2, -3.

We keep a sliding window of 5 prices so that we can grab 4 consecutive diffs at any point. For each 4-diff tuple (like -1, 2, 0, -2), we record how much **benefit** (aka the sale price) we get if we sold when that pattern first appeared for a given monkey (this also makes the problem faster as already present patterns can be skipped)

To manage this efficiently:
- A `Window` class helped maintain the sliding window of 5 values and calculate the current 4-diff tuple.
- A `fourTuple` struct captured the 4-diff pattern and let us hash it properly using a custom `fourTupleHash`.
- A big  `unordered_map` tracked the best score for every diff sequence.

Once we had processed all input, we just looked up which tuple gave the highest value and returned it.

</details>  

---

## Conclusions and Thoughts  
This day 22 part 1 felt almost mechanical, but part 2 turned into a more interesting pattern analysis and optimization problem, specially how it forced you to track *change trends* rather than values directly.

Also, props to the use of custom hashing and sliding windows. It was, after many days of graphs and memoization, a different challenge that stood on its own. I am sure it is not solved the quickest way but it works. It could be improved by trying to memoize more and to make the secret number generation way better (thanks to memoization probably or even finding a pattern on the digits).