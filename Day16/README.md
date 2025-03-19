# Day 16: Reindeer Maze

## Part 1  
**Difficulty:** 🌗🌑🌑🌑🌑  

**Approach & Solution:**  
This problem was all about pathfinding, but with a twist—movement wasn’t just about distance, but also about direction changes incurring a heavy penalty. The goal was to navigate the maze efficiently while minimizing both movement and rotations.

<details>  
<summary>Detailed Explanation (Click to expand)</summary>  

1. **State Representation**: Instead of just tracking positions, I kept track of the reindeer's facing direction. This was crucial because turning 90 degrees added 1000 points to the cost.  

2. **Priority Queue (Dijkstra’s Algorithm)**: Since we were looking for the shortest weighted path, a priority queue (min-heap) was the best choice. The queue stored tuples of `(cost, position, direction)`, ensuring the lowest-cost path was explored first.  

3. **Movement Rules**:  
   - Moving forward added 1 to the score.  
   - Turning left or right added 1000.  
   - Moving into a wall (`#`) was not allowed.  

4. **Tracking Costs**:  
   - A `map<char, long>` was maintained for each grid cell to store the best-known cost for each direction.  
   - If a newly found cost was lower than a previously recorded cost, it was updated, and the new state was pushed into the priority queue.  

5. **Termination**: The algorithm stopped once all potential paths were explored, and the minimum cost for reaching `E` in any direction was recorded.  

The final answer was the minimum cost required to reach the exit using the best combination of movements and turns.

</details>  

---

## Part 2  
**Difficulty:** 🌗🌑🌑🌑🌑  

**Approach & Solution:**  
Now the problem changed—rather than just finding the optimal path, we needed to determine which tiles were part of *any* optimal path.

<details>  
<summary>Detailed Explanation (Click to expand)</summary>  

1. **Backtracking from the Exit**:  
   - Once the optimal distance to the exit was determined, I worked backwards to find which tiles contributed to *at least one* shortest path.  

2. **Reversing Movements**:  
   - Similar to Part 1, but instead of moving forward, I moved *backward* from `E`, following only the moves that preserved the optimal path cost.  

3. **Set to Track Relevant Tiles**:  
   - A `set<pair<long, long>>` stored all visited tiles that were part of at least one optimal path.  
   - If a tile had multiple optimal paths passing through it, it was counted only once.  

4. **Final Count**:  
   - After the backtracking traversal, the size of the set gave the number of tiles that were part of an optimal path.  

</details>  

---

## Conclusions and Thoughts  
This was a really cool take on shortest path problems! The penalty for turning added an extra layer of complexity that made it feel more like a real-world navigation challenge. Dijkstra’s algorithm was the obvious choice, but tracking movement direction as part of the state was the real key.  

Part 2 was fun because it forced me to think in reverse—finding not just *a* solution, but *all* optimal solutions. The best part? Seeing how the paths overlapped and how only certain tiles were truly "important" to the shortest path. Definitely a solid maze challenge!