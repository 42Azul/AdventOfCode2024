# Day 6: Maze Navigation

## Part 1  
**Difficulty:** 🌖🌑🌑🌑🌑  

**Approach & Solution:**  
This problem revolved around navigating a maze-like grid while following specific movement rules. The main goal was to count how many positions were visited before exiting the grid based on predefined movement logic.

<details>  
<summary>Detailed Explanation (Click to expand)</summary>  

1. **Grid Parsing:** The input was read into a 2D vector, where `#` represented walls, `^` marked the starting position, and open spaces were free to move into.
2. **Movement Handling:** The algorithm started at the `^` position and moved according to a defined initial direction (upward). 
3. **Rotation Rule:** When encountering a wall, the movement direction rotated 90 degrees clockwise. Otherwise, the position was marked as visited.
4. **Exit Condition:** The loop terminated when movement led outside the grid, and the total number of visited positions was printed.


In the end it was just going through the matrix and managing the position. Easy peasy this one.
</details>  

---

## Part 2  
**Difficulty:** 🌖🌑🌑🌑🌑  

**Approach & Solution:**  
Part 2 extended Part 1 by introducing loop detection: instead of merely counting visited positions, it was necessary to determine how many steps resulted in being trapped in a cycle.

<details>  
<summary>Detailed Explanation (Click to expand)</summary>  

1. **Tracking Visited States:** Each movement step was stored with both position and direction.
2. **Loop Detection:** If a state was encountered again (same position, same direction), a loop was detected.
3. **Backtracking & Fixing Loops:** The algorithm modified the grid temporarily to test whether adding a blocking point eliminated loops, counting successful cases. It is important to note that for each try, we start in the exactly previous state to the blocking point (as nothing that happens before really matters).
4. **Final Output:** The program printed the count of looped paths that could be avoided by removing a single movement step.

Because the grid was not big enough, this simple approach, which is quite brute-force worked fine. However, further optimizations could be applied, maybe dynamic programming ones or some branch and bound techniques. 

</details>  

---

## Conclusions and Thoughts  
This challenge was an engaging exercise in grid traversal and cycle detection. It was not particularly complex but required careful tracking of visited states and movement logic.

Key takeaways:

1. **Efficient Movement Representation:** Using a structured state (position + direction) made tracking and detecting loops much easier.
2. **Alternative Data Structures:** The use of `unordered_set` for visited states was effective, but other structures like a linked list could optimize specific operations.
3. **Debugging:** At the beginning I tried to do it blindly, but visualizing the grid and step-by-step movement was a good way to find some small errors while coding it.

Overall, a satisfying problem that was, once again, grid oriented. As previous days, this was not solved  in the most optimized way, but it worked perfectly, which was more than enough.
