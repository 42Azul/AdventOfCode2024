# Day 20: Race Condition

## Part 1  
**Difficulty:** 🌗🌑🌑🌑🌑  

**Approach & Solution:**  
We are in maze-solving territory again, but with a twist: you are allowed one short wall hack. The map was a grid full of walls and paths, and the challenge was to compute how many "cheats" would improve your route by at least 100 picoseconds.

<details>  
<summary>Detailed Explanation (Click to expand)</summary>  
The key insight was to precompute distances from both the start and end positions using BFS.  

1. First, a regular BFS from the **end** to calculate the shortest legal distances to every tile.
2. Then, another BFS from the **start**, doing the same thing in reverse.
3. After that, I tried all possible 2-cell wall jumps—checking if going from some tile A to tile B via a "cheat" (2 moves max) would reduce the overall distance by at least 100 compared to the legal route.
4. If so, I counted it.

This solution relied on clever use of precomputed distances rather than brute-forcing every cheat.
</details>  

---

## Part 2  
**Difficulty:** 🌕🌑🌑🌑🌑  

**Approach & Solution:**  
Rules changed: now you can cheat for **up to 20 moves**. That opened the gates for a lot more pathfinding variations. But the structure of the solution stayed mostly the same.

<details>  
<summary>Detailed Explanation (Click to expand)</summary>  
Instead of hardcoding the cheat directions, I generated all possible cheat vectors within a 20-step Manhattan radius. That gave me a much larger set of possible wall jumps (including long diagonals and zig-zags).

1. Again, did BFS from end and from start to get shortest paths legally.
2. Then looped over all grid cells and tried applying **all** valid cheat vectors.
3. For each potential cheat, I checked if using it gave a route 100+ picoseconds shorter than the legal one.

Because of the larger cheat space, the solution needed tighter control over bounds and efficiency, but conceptually it followed the same steps as Part 1. The difference was just scale and cheat range.
</details>  

---

## Conclusions and Thoughts  
This one was cleaner than expected. It read like a gimmick at first—“you can cheat once!”—but in the end it turned into a solid bidirectional BFS with a search over possible shortcuts. The trickiest part was figuring out how to model the cheats and keep everything fast despite the size of the map and cheat space.

Part 2 did not require rewriting the logic—just extending it. At the beginning I was manually writing the directions or even trying other things, but just doing the same concept made it work (with a little bit of carefulness on the checks).