# Day 24: Crossed Wires

## Part 1  
**Difficulty:** 🌗🌑🌑🌑🌑  

**Approach & Solution:**  
This part was about simulating a basic digital circuit composed of logic gates (AND, OR, XOR) with wire-based signal propagation. Each gate has two input wires and one output wire. We’re given initial wire values and a list of gate operations. The goal: simulate the circuit and compute the final binary value formed by all wires starting with `'z'`.

<details>  
<summary>Detailed Explanation (Click to expand)</summary>  

The input was split into two sections: initial wire values and gate definitions. These were parsed and stored respectively in a map for known wire values (`operands`) and a queue/list system for operations:

1. Each gate was stored as a `registerOperation` struct, capturing its type (`opcode`), input wires, and output wire.  
2. A queue handled operations whose inputs were immediately available (`doableOperations`), and a list tracked operations still waiting for at least one input (`missingOperations`).
3. Operations were processed in topological order. When an operation was executed, its output value was stored and any previously blocked operations depending on that output were re-evaluated and potentially unblocked.
4. Finally, all values of wires prefixed with `'z'` were collected and ordered by their numeric suffix (`z00`, `z01`, ...). These bits were then combined into a single binary number, converted to decimal, and printed.

This approach made the simulation clean and reactive to dependency resolution as each gate’s inputs became available.

</details>  

---

## Part 2  
**Difficulty:** 🌕🌕🌕🌑🌑  

**Approach & Solution:**  
This part revealed that the circuit was *intended* to perform binary addition, but had malfunctioned due to incorrect gate-to-wire assignments—specifically, eight wires (outputs from four gates) had been incorrectly swapped. The objective was to identify and correct those swaps.

<details>  
<summary>Detailed Explanation (Click to expand)</summary>  

The strategy here centered on verifying the structure of a correct binary adder circuit and identifying gates whose output assignments violated that expected pattern.

1. All gate definitions were parsed into a `registerOperation` list, and grouped by operands into an `unordered_map` for quick lookup. Each wire was mapped to the gates using it as input.
2. A function (`isValidChain`) validated whether the current wiring setup simulated a correct ripple-carry binary adder. This included validating:
   - Each bit position XORs the input bits and possibly a carry to produce a `z` wire.
   - AND and OR operations generate intermediate carry values passed along.
3. A brute-force strategy was used to identify misassigned outputs:
   - First, a set of suspicious gates was created—either due to mismatched output names or unusual operand patterns. For this I had to check the wires and I detected some of them which made sense. I used a custom script to check some proofs and took some physical notes. 
   - Candidate gates were grouped into pairs. Each pair was tested by swapping their output wires and re-checking the circuit with `isValidChain`.
   - The search terminated when a swap configuration resulted in a valid full-adder chain ending in the correct final wire (`z45`).
4. Once identified, the names of all eight output wires involved in swaps were sorted alphabetically and joined by commas for the final answer.

This solution was not mainly about the code itself, but about checking the input and understanding which wires can be wrong (once we know the expected way a binary adder works). 
The solution is by no means clean and multi purpose, though it works and returns the right result.

</details>  

---

## Conclusions and Thoughts  
This was a great exercise in building a simple circuit simulation engine and then breaking it on purpose. Part 1 was mostly procedural and tested topological execution of boolean gates. Part 2 turned the problem into a detective puzzle—reverse-engineering an intended full-adder circuit with minimal information and correcting wiring faults through brute-force swaps and structural validation. Not complex due to coding, but due to thinking and reversing the errors themselves. This problem was quite different from what I am used to do in Competitive Programming, as this was quite related to the specific input and not a generic solution that maybe could be found, but was not required at all.