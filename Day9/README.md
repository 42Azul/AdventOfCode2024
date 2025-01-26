# Day 9: Disk Fragmenter

## Part 1  
**Difficulty:** 🌕🌑🌑🌑🌑  

**Approach & Solution:**  
This puzzle required rearranging a sequence of numerical values to reduce gaps while maintaining the original order as much as possible. The challenge was to shift values leftward efficiently without disrupting the overall structure.

<details>  
<summary>Detailed Explanation (Click to expand)</summary>  
The approach involved:

1. **Interpreting the input**: The input was parsed as a sequence of alternating magnitudes and spacers. These represented units of value and empty slots, respectively.
2. **Shifting values efficiently**:
   - The sequence was traversed from left to right, processing each value group in turn.
   - When encountering an empty slot, an attempt was made to shift the nearest available values from the rightmost side.
   - This required decrementing the tracked rightmost index and adjusting the counts dynamically.
3. **Optimizing movements**: The shifts occurred iteratively to ensure each available position was filled before progressing, reducing unnecessary operations.
4. **Computing a final measure**: A cumulative sum was calculated based on the product of each value and its final index position, ensuring an accurate representation of the final compacted sequence.

A helper function was utilized to precompute value distributions efficiently, minimizing redundant calculations. The key complexity lay in managing positional shifts accurately.

</details>  

---

## Part 2  
**Difficulty:** 🌕🌑🌑🌑🌑  

**Approach & Solution:**  
This part altered the approach by enforcing whole-value movements instead of individual unit shifts, leading to a different optimization strategy.

<details>  
<summary>Detailed Explanation (Click to expand)</summary>  

Building on Part 1, the new logic involved:

1. **Sorting and identifying movable units**: Instead of shifting individual parts, entire segments were considered in descending order.
2. **Finding the best available placement**:
   - Each unit segment was moved to the first sufficiently large gap to its left.
   - If no appropriate space existed, the segment remained in place.
3. **Maintaining integrity of the values**: The crucial distinction was ensuring that units were only moved when an entire block could be relocated at once.
4. **Recomputing the cumulative measure**: The final sum was calculated using the same methodology as in Part 1, applied to the adjusted sequence.

This required a structured approach to determine optimal placements while preventing partial movements. The solution maintained efficiency by precomputing viable moves and reducing unnecessary scans.

</details>  

---

## Conclusions and Thoughts  
After a lot of problems related to grid and search, this day we had a simple solution (in the sense that we are not using fancy algorithms), but that required managing two pointers and in general handling edge cases where values had limited mobility.
It was a different thing to be done and typical problem were you know how to solve it, but debugging is not so simple.