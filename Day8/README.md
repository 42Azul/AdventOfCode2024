# Day 8: Resonant Collinearity

## Part 1  
**Difficulty:** 🌗🌑🌑🌑🌑  

**Approach & Solution:**  
This puzzle was all about detecting and marking antinodes in a grid based on the placement of antennas transmitting at specific frequencies.
We can think of it abstractly as finding symmetric elements in the grid respect to each other.

<details>  
<summary>Detailed Explanation (Click to expand)</summary>  
The challenge was to determine points in the grid that act as antinodes, following a specific resonance rule.  

1. Each element in the grid was identified and stored in a map, categorized by its value (letter or digit).  
2. For each new element placed, the program checked existing ones of the same value to determine if they had a simmetry inside the map, ca.using an antinode to be created.
3. We had to be careful not to duplicate the antinodes, for this a set of the positions of them was used.

</details>  

---

## Part 2  
**Difficulty:** 🌗🌑🌑🌑🌑  

**Approach & Solution:**  
The second part introduced a different rule, making many more positions count as antinodes. In this case, more than simmetry, is just counting all values inside the map that are in the same line between to antennas.

<details>  
<summary>Detailed Explanation (Click to expand)</summary>  
This time, we do not want to find the two symmetric solutions, but the continuous propagation of values through the line.

1. The original algorithm was modified to allow a continuous propagation of antinodes along the same direction as the antennas.  
2. Each antenna became an antinode itself if there were at least two of the same frequency in line with it.  
3. The traversal logic was extended to check all possible grid alignments, adding new antinodes dynamically.  

</details>  

---

## Conclusions and Thoughts  
This problem was again a grid-based one, that took more time for reading the input than solving the problem itself. The logic for detecting aligned elements and calculating valid positions was simple to implement, though it required careful handling of distance constraints.  

The second part felt like a natural extension of the first, just enforcing to check all the positions in the line, but nothing too fancy either. 
This week I was expecting to find a complex thing but it was actually pretty simple (I would say that even simpler than days before).
But I was not wrong that things would start to be complex sooon! 