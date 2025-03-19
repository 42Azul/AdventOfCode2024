# Day 15: Warehouse Woes  

## Part 1  
**Difficulty:** 🌗🌑🌑🌑🌑  

**Approach & Solution:**  
This challenge was all about simulating a robot moving in a warehouse full of obstacles, particularly boxes that it could push around. The key challenge was handling blocked movements and cascading pushes correctly.

<details>  
<summary>Detailed Explanation (Click to expand)</summary>  
The warehouse was represented as a grid, with walls (`#`), empty spaces (`.`), a robot (`@`), and boxes (`O`). The robot attempted to follow a sequence of movement instructions (`<`, `>`, `^`, `v`), and the goal was to calculate the sum of the final positions of the boxes using a "GPS coordinate" system.

1. **Parsing the Input:**  
   - The grid was read into a `vector<vector<char>>`, storing the warehouse layout.
   - The robot’s initial position was identified.
   - The movement instructions were extracted as a sequence.

2. **Movement Mechanics:**  
   - The robot could move freely into empty spaces.
   - If it encountered a box (`O`), it tried to push it in the same direction.
   - If pushing a box would cause it to hit a wall or another box that couldn’t be pushed, the movement was invalid.

3. **Simulation Loop:**  
   - The robot processed each movement command.
   - If possible, it moved and updated the grid.
   - If a box moved, its position was updated.
   - The final position of all boxes was used to calculate the sum of their GPS coordinates.

This part required taking in account edge cases such as multiple boxes in a row, collisions with walls, and movement attempts that did nothing, but nothing too complex to handle.

</details>  

---

## Part 2  
**Difficulty:** 🌗🌑🌑🌑🌑  

**Approach & Solution:**  
Just when you thought moving a single-sized box was tricky, part 2 doubled the width of everything except the robot! This meant we had to rewrite how the grid was represented and adapt the movement mechanics accordingly.

<details>  
<summary>Detailed Explanation (Click to expand)</summary>  
The main difference in this part was that the warehouse layout was "stretched" horizontally:

1. **Doubling the Map:**  
   - Walls (`#`) became `##`, open spaces (`.`) became `..`, and boxes (`O`) turned into `[]`.
   - The robot’s `@` position remained the same but had a trailing `.` to maintain spacing.

2. **Handling Wide Boxes:**  
   - A box (`[]`) occupied two adjacent cells.
   - Pushing logic had to account for these larger boxes and check both halves before moving.
   - If a wide box was against a wall or another box that couldn't move, it stayed in place.

3. **Updated Movement Functions:**  
   - The movement simulation was adapted to track whether a box's partner half was moving.
   - Special care was needed to prevent breaking box pairs when pushing.

4. **Final Calculation:**  
   - The GPS coordinate system was updated to measure from the **leftmost** position of the wide boxes.
   - The total sum of GPS coordinates was computed similarly to Part 1.

This part added an extra layer of handling edge cases, but it was manageable.

</details>  

---

## Conclusions and Thoughts  
This problem was just a simple concept with a picky implementation of rules. It was useful to debug the movements and thus make sure that no boxes were lost or any of the rules in general, was not being followed rightly. Sadly this day problem seems a bit easier in comparison to the last days that were more insightful and with more cool content.