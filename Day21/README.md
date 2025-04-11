# Day 21: Keypad Conundrum

## Part 1  
**Difficulty:** 🌗🌑🌑🌑🌑  

**Approach & Solution:**  
We have multiple layers of keypads controlling each other, ultimately causing a final robot to type numeric codes on a door keypad. The puzzle demands the *shortest* sequence of directional presses on the top-level keypad (the one you personally type on) that triggers all the layers of robots to type out specific codes. The idea is to calculate the required steps and use them to offer a password.

<details>  
<summary>Detailed Explanation (Click to expand)</summary>  
1. **Keypad Layouts:** There’s a numeric keypad (with digits and a letter `A`), plus a “directional” keypad that can move an arm around. Both keypads have “gaps” you can’t point the arm at—if you do, the robot panics.  
2. **Controlling Chain:** The code simulates how each instruction on your keypad corresponds to movements on the robot’s keypad, which in turn moves another robot’s arm, and so on, until eventually the numeric keypad is pressed.  
3. **Shortest Moves:** We compute a “move string” that is as short as possible. For each digit in the final code (e.g., `029A`), the code carefully generates a minimal path from the current button to the desired button, ensuring we never aim at empty space.  
4. **Complexity Calculation:** Once the final code is typed, we multiply the numeric part by the length and we just have it.
</details>  

---

## Part 2  
**Difficulty:** 🌕🌑🌑🌑🌑  

**Approach & Solution:**  
Now the puzzle escalates by adding *many* more robots—25 extra directional keypads. The logic stays the same, but the recursion depth is higher. We have to handle an enormous chain of “keypads that control keypads,” all working together to press the numeric keypad at the end so it can not be solved in a brute force way. For this a memoized approach is used to avoid re-calculating the same transitions over and over.

<details>  
<summary>Detailed Explanation (Click to expand)</summary>  

1. **Deep Chains:** Instead of a single layer, we have 25 layers of robots, each needing minimal instructions to move from one button to another.  
   
2. **Memoization:** Because we repeatedly ask “How many moves from button A to button B at depth D?” we store those results to avoid recalculating them for every step.  
3. **Final Computations:** As before, each code’s complexity is (length of the final press sequence) × (numeric part of the code). The difference is that the pressing sequence is far more involved.  
4. **Summation:** When all codes are typed, we sum their complexities to get the final monstrous number.
</details>  

---

## Conclusions and Thoughts  
At first glance, it looks like an over-the-top puzzle about nested keypads and weird constraints. But it was basically a layered pathfinding problem: minimal moves on each keypad, times a lot of keypads in a chain, repeated for multiple codes. The important part was for the second part to use a nice memoization approach to avoid useless recalculation, but nothing too fancy.