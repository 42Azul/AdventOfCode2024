

# Day 5: Print Queue

## Part 1  
**Difficulty:** 🌖🌑🌑🌑🌑  

**Approach & Solution:**  
The first part involved validating the order of list of sequence. For that we had rules specifying that one value must appear before another if both are present in the update.

<details>  
<summary>Detailed Explanation (Click to expand)</summary>  

1. **Input Parsing:** The rules and page orders were read and split into two groups. Each rule was stored as a pair, indicating a precedence constraint

2. **Validation Function:** A helper function was created to check if all rules were followed within a given sequence of values. This function iterated through the list to ensure no rule was violated, using the `all_of` function of C++.

3. **Middle Page Calculation:** For updates where all rules were satisfied, the middle value of the sequence was identified and added to a running sum.  
   
4. **Output:** The program output the sum of the middle values for correctly-ordered updates.  

</details>  

---

## Part 2  
**Difficulty:** 🌖🌑🌑🌑🌑  

**Approach & Solution:**  
The second part introduced the challenge of fixing elements that were not following the ordering rules by reordering them. After correcting the order, the middle value of each corrected sequence was computed and summed.

<details>  
<summary>Detailed Explanation (Click to expand)</summary>  

1. **Reordering Functionality:** A helper function iterated through the sequence to detect violations of the rules. When a rule was broken, the function moved the out-of-order page to its correct position by erasing and reinserting it into the sequence.

2. **Iterative Fixing:** For each incorrectly-ordered update, the reordering function was applied iteratively until all rules were satisfied.

3. **Output:** The program output the sum of the middle values after fixing all updates.  

This part built on the validation logic from Part 1 and added a layer of complexity by requiring dynamic reordering.

</details>  

---

## Conclusions and Thoughts  
This problem was still simple and could be solved without fancy or overcomplex ideas, or even requiring concrete data structures. Part 1 was straightforward and laid a solid foundation for a bit more interesting second part.

However, as with Day 2, I recognize opportunities to improve the efficiency of my solution. Specifically:

1. **Validation Optimization:** In Part 1, instead of validating all rules for every sequence, a single traversal might suffice to detect and confirm compliance with the rules. This could further streamline the solution.

2. **Vector Operations:** In Part 2, I used a vector for reordering, which involved `erase` and `insert` operations. These are more efficient in data structures like lists, where such operations have O(1) complexity.

Writing these summaries makes me rethink the problems with an outsider view (and without any hurry). It’s been a useful exercise to reflect and improve! 😄
