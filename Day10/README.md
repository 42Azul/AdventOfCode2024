# Day 10: Hoof It

## Part 1  
**Difficulty:** 🌕🌑🌑🌑🌑  

**Approach & Solution:**  
This problem required parsing a grid-based topographic map and identifying valid hiking trails. The trails needed to start at `0`, increase sequentially by `1` at each step, and end at `9`. The goal was to determine how many `9`s were reachable from each `0`.

<details>  
<summary>Detailed Explanation (Click to expand)</summary>  
The solution involved:  

1. **Grid Parsing:** Reading the input as a 2D matrix and identifying all positions containing `0`, which were potential trailheads.  
2. **Recursive Depth-First Search (DFS):** Implementing a recursive function to explore all valid paths, ensuring each step followed the increasing sequence rule.  
3. **Marking Visited Nodes:** Since each path had to be unique, cells were temporarily marked to prevent cycles or revisits.  
4. **Summing Results:** For each `0`, the function counted how many `9`s were reachable and accumulated the total score.  

The key challenge was ensuring efficient traversal without redundant computations while handling different grid sizes.  

</details>  

---

## Part 2  
**Difficulty:** 🌕🌑🌑🌑🌑  

**Approach & Solution:**  
The second part introduced a new measure: **trailhead rating**, which counted distinct hiking trails that ended in `9` instead of reachable `9`s.

<details>  
<summary>Detailed Explanation (Click to expand)</summary>  
To adapt the solution we just removed the check on the redundant cells, so in this case we can go through the same path many times (as long as there is a change in previous parts of the path)

This required almost no change from the original solution of Part 1.

</details>  

---

## Conclusions and Thoughts  
This was a cool problem that introduced structured pathfinding with constraints. The first part was relatively straightforward, requiring a recursive DFS with simple conditions. The second part was simply built on top of the part 1, and did not add too much complexity. It could be improved by using a better memoization approach, like dynamic programming, and storing inside the cell the number of `9`s that are reachable from then, and maybe even going in a backward way instead of starting in `0`s.