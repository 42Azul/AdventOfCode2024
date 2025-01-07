

# Day 4: Ceres Search

## Part 1  
**Difficulty:** 🌗🌑🌑🌑🌑  

**Approach & Solution:**  
This task was about scanning a grid to find all instances of the word "XMAS" in every possible direction—horizontal, vertical, diagonal, and even reversed.

<details>  
<summary>Detailed Explanation (Click to expand)</summary>  
The code processed the grid row by row, character by character, looking for the starting letters `X` and `S`.  

1. When it encountered an `X`, it tried to form "XMAS" in all eight directions
2. A helper function validated each direction by checking if the next characters matched the sequence.  
3. For every match found, the count was incremented.

</details>  

---

## Part 2  
**Difficulty:** 🌗🌑🌑🌑🌑  

**Approach & Solution:**  
The second part required finding pairs of "MAS" in an X pattern around an `A`.


<details>  
<summary>Detailed Explanation (Click to expand)</summary>  
Building on Part 1, this part added a few extra constraints:  

1. The `A` in the grid served as the center of the X pattern.  
2. The solution checked all four arms of the X to see if they contained "MAS" in either direction (forwards or backwards).  
3. A helper function was written to validate the exact positions of `M`, `A`, and `S` relative to the center `A`.  
4. The traversal required managing four combinations (forward and backward for both diagonal directions) while ensuring overlaps were handled correctly.  

This solution was built quickly thanks to the methods in the part 1 solution.

</details>  

---

## Conclusions and Thoughts  
This was the first grid-like problem, and honestly, it felt like a warm-up. The main challenge was parsing the input and validating the grid traversal rules. It wasn’t super complex, but it introduced using vectors and iterating with direction pairs, which was satisfying.  

I’m happy I kept my main function clean by delegating tasks to helper methods—something that doesn’t always happen in competitive programming but aligns better with real-life coding practices. That said, I didn’t use pairs or more advanced abstractions yet, but those improvements will come later. Part 2 was a bit sad, as it was almost identical to part 1.