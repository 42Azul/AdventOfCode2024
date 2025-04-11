# Day 17: Chronospatial Computer

## Part 1  
**Difficulty:** 🌗🌑🌑🌑🌑  

**Approach & Solution:**  
This problem introduced a quirky 3-bit computer with a set of eight instructions, operating on three registers (A, B, and C). The task was to execute a given program and collect its output.

<details>  
<summary>Detailed Explanation (Click to expand)</summary>  
The core of the solution involved simulating this 3-bit computer by correctly interpreting its opcodes and operands. Here’s how it was done:

1. **Parsing the Input:**  
   - The registers A, B, and C were initialized from the provided input.
   - The program was stored as a list of 3-bit instructions.

2. **Executing the Instructions:**  
   - The program execution looped through each instruction, updating registers and the instruction pointer accordingly.
   - Operations included bitwise manipulations (`XOR`), modular arithmetic, and conditional jumps.

3. **Handling Output:**  
   - The `out` instruction collected values which were then joined with commas to form the final result.

The main challenge was ensuring that operands were interpreted correctly, as some referred to literal values while others pointed to register contents. Debugging was crucial to match the expected outputs.

</details>  

---

## Part 2  
**Difficulty:** 🌕🌕🌗🌑🌑  

**Approach & Solution:**  
This part took things up a notch: instead of just running a program, we had to reverse-engineer the correct initial value for register A so that the output was an exact copy of the program itself.

<details>  
<summary>Detailed Explanation (Click to expand)</summary>  
To solve this, a brute-force approach would have been infeasible, so a more structured method was used:

1. **Understanding the Pattern:**  
   - The program was expected to output itself, meaning that the value of A needed to be carefully tuned so that the sequence of instructions produced the correct result. First I did some manual checks and made the problem not to have input, but to handle the specific case.

2. **Incremental Search for A:**  
   - Instead of testing all possible values, a structured approach was used to find patterns in how A evolved during execution.
   - As the value is operated modulo 8, this means that we only care about 3-bits for each expected output on the code.
   - We will go 3-bits per 3-bits creating a vector of increments that are the only ones that enable outputting up to the current digit. This way we limit a lot the possibilities so bounding the brute force approach.


This part was much trickier conceptually, as it required understanding the deeper structure of how the program interacted with A’s initialization.

</details>  

---

## Conclusions and Thoughts  
Part 1 was all about careful implementation of a custom instruction set, which was quite straightforware. However, Part 2 turned into a puzzle about reverse-engineering initial conditions to produce a perfect match.  

It felt like a mix of assembly programming and pattern finding. It had a very "meta" feel to it, making it one of the most satisfying problems so far. I had to do a bit of notes and think about more than simply implementing an algorithm :D