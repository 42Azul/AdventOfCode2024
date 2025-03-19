# Day 13: Claw Contraption

## Part 1  
**Difficulty:** 🌗🌑🌑🌑🌑  

**Approach & Solution:**  
This challenge was all about figuring out the minimum number of tokens needed to win as many prizes as possible in a claw machine with an unusual control system.

Each machine had two buttons (A and B) that moved the claw in specific increments along the X and Y axes. The objective was to find out how many times each button had to be pressed to align the claw exactly over the prize position. Given the cost of pressing each button, the goal was to find the optimal way to minimize the number of tokens spent.

<details>  
<summary>Detailed Explanation (Click to expand)</summary>  
The problem essentially boils down to solving a system of linear equations:

$$m \cdot A_x + n \cdot B_x = P_x$$
$$m \cdot A_y + n \cdot B_y = P_y$$

Where:
- $( A_x, A_y )$ are the increments for button A.
- $( B_x, B_y )$ are the increments for button B.
- $( P_x, P_y )$ are the target prize coordinates.
- $m$ and $n$ are the number of times each button is pressed.

The solution follows these steps:

1. Parse the input to extract the button increments and prize position.
2. Solve the system using determinant-based calculations:
   - Compute the determinant $( D = A_x \cdot B_y - B_x \cdot A_y )$.
   - Check if the system has integer solutions by verifying divisibility.
   - If valid, compute $m$ and $n$.
3. If a solution exists, calculate the token cost: $3m + n$.
4. Accumulate the total minimum token count across all valid machines.

This approach efficiently determines which machines can be won and the minimum cost to win them.

</details>  

---

## Part 2  
**Difficulty:** 🌗🌑🌑🌑🌑  

**Approach & Solution:**  
Part 2 introduced a small but crucial modification: the prize coordinates were actually **10 trillion** units higher than initially thought. This drastically changed which machines could be solved.

<details>  
<summary>Detailed Explanation (Click to expand)</summary>  
The only change in Part 2 was modifying the prize coordinates by adding a lot of additional zeros. This affected the specifics of the system of equations, but the approach remained the same.

</details>  

---

## Conclusions and Thoughts  
This problem was basically a number theory puzzle disguised as an arcade game. The main difficulty was recognizing that we were solving a system of linear equations and not trying a brute force solution. As a matematician myself, this was actually one of the simplest problems with not a lot to do, more than managing the input and output parameters.