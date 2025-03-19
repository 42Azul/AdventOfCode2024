# Day 10: Plutonian Pebbles

## Part 1  
**Difficulty:** 🌗🌑🌑🌑🌑  

**Approach & Solution:**  
This challenge was all about tracking the transformation of numbers following a set of recursive rules. Each number on a "stone" evolved through a series of well-defined steps over multiple iterations, creating more numbers and making more stones for the next iteration of the rules. The goal was to determine how many stones would exist after 25 transformations.

<details>  
<summary>Detailed Explanation (Click to expand)</summary>  

The approach involved using a linked list (`std::list<long>`) to store and manipulate the numbers efficiently, as elements needed to be inserted dynamically. The key transformation rules were:  

1. If a number was `0`, it turned into `1`.  
2. If a number had an even number of digits, it was split into two parts.  
3. Otherwise, the number was multiplied by `2024`.  

To implement this, not to overcomplexify, we just had a brute force approach using:

- A helper function `getDigits` determined the number of digits in a given number.  
- Another function `getSplit` split a number into two halves when needed.  
- The `iterateStones` function iterated over the list, applying transformations according to the rules.  

The process was repeated 25 times, as required by the problem statement, and the final count of stones was printed as the result.

</details>  

---

## Part 2  
**Difficulty:** 🌕🌕🌑🌑🌑

**Approach & Solution:**  
This part scaled up the problem to 75 transformations, which made a brute-force approach infeasible due to exponential growth. A more structured way of handling the transformations was needed.

<details>  
<summary>Detailed Explanation (Click to expand)</summary>  

Instead of using a list, a more optimized approach using a tree-like structure was implemented:  

1. A `Node` structure was introduced to represent each stone in a tree.  
2. Each node stored its value and its children (`left` and `right`), allowing us to track the recursive expansion more efficiently.  
3. A `depthMap` was used to cache results and avoid recomputation.  

Key optimizations included:  
- Using `std::set<Node*>` to store and retrieve nodes efficiently.  
- Recursively developing the tree while keeping track of transformations at each depth.  
- Storing previously computed results to avoid redundant calculations, i.e using the depth map of a node with same value that was generated before.

This optimized approach allowed for an efficient solution to the problem, even with 75 iterations, leading to the final answer.
The key here was to know that the different numbers were independent, so you do not worry about their order or relation and can treat each node in input as a different root, but with possible similar or equal numbers in their road to the leaves.

</details>  

---

## Conclusions and Thoughts  
This challenge was deceptively simple at first, but the exponential growth of numbers made an optimized approach necessary. While Part 1 could be handled with a brute-force list traversal, Part 2 required a shift to a more structured tree-based solution to manage the vast number of operations efficiently.  

It was satisfying to find a scalable way to track transformations, and finally having a problem that was not as simple as the others (not so straightforward) as well as a great way to explain that apparent small changes (25 to 75 iterations), may lead to quite different situations!
