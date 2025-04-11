# Day 18: RAM Run  

## Part 1  
**Difficulty:** 🌗🌑🌑🌑🌑  

**Approach & Solution:**  
This problem throws us straight into a digital survival game: bytes are falling into a 2D grid, corrupting memory locations, and we need to find the shortest path to the exit while avoiding the corrupted areas. In reality it is just a grid with possible movements and blocked movements.

<details>  
<summary>Detailed Explanation (Click to expand)</summary>  

The solution follows a classic pathfinding approach using **Dijkstra's algorithm**, since we need to find the shortest path while new obstacles (corrupted memory) are being added dynamically.  

1. **Data Representation**:  
   - The grid is modeled as a 70x70 matrix where each coordinate can either be corrupted (`#`) or safe (`.`).  
   - We maintain an unordered map to track corrupted cells.  

2. **Processing Corruptions**:  
   - We read the first **1024 bytes** and mark them as blocked in our `isBlock` map.  

3. **Pathfinding with Dijkstra's Algorithm**:  
   - We use a **min-heap (priority queue)** where each entry consists of `(distance, position)`, allowing us to always expand the nearest unvisited node.  
   - The `distances` map tracks the shortest known distance to each cell.  
   - We iterate through the four possible movement directions (`up, down, left, right`), skipping any blocked or out-of-bounds cells.  

4. **Result Extraction**:  
   - Once the algorithm reaches the bottom-right corner `(70,70)`, the shortest path length is recorded.  
   - The final output is the minimum number of steps needed to safely reach the exit after the first **1024 corruptions**.  

</details>  

---

## Part 2  
**Difficulty:** 🌗🌑🌑🌑🌑  

**Approach & Solution:**  
This part takes things up a notch: instead of just finding the shortest path, we need to **identify the first byte that completely blocks the exit**.

<details>  
<summary>Detailed Explanation (Click to expand)</summary>  

Our goal is to find out which specific byte is responsible for cutting off the path.  

1. **Simulating More Corruptions**:  
   - This time, we keep adding bytes **until the exit becomes unreachable**.  
   - The total number of bytes considered goes up to **3035**.  

2. **Checking Reachability**:  
   - After each byte is added, we **rerun our shortest path algorithm** to check if a path to `(70,70)` still exists.  
   - If at any point no valid path is found, that last added byte is our culprit.  

3. **Output the Critical Byte**:  
   - We stop at the first byte that renders `(70,70)` inaccessible and return its coordinates.  

</details>  

---

## Conclusions and Thoughts  
This problem was another digital maze one. The first part was a straightforward application of **Dijkstra's algorithm**, but part two introduced a quite different challenge.

It has been many days with these pathfinding problems, but still cool to get used to them. For the second part I think there could be better ways to approach it and maybe for a memory/time-bound competition it would have been not enough. I thought about improving it with some connected components algorithm or similars, but ended up happy with the given approach.