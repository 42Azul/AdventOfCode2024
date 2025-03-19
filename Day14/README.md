# Day 14: Restroom Redoubt

## Part 1  
**Difficulty:** 🌗🌑🌑🌑🌑  

**Approach & Solution:**  
The problem required simulating the movement of security robots over a 2D grid with periodic boundary conditions (wrapping around at the edges). The goal was to determine the distribution of robots after 100 seconds and compute a safety factor based on quadrant counts.

<details>  
<summary>Detailed Explanation (Click to expand)</summary>  
Each robot starts at a given `(x, y)` position and moves with a given `(vx, vy)` velocity. The movement happens in discrete time steps, and when a robot reaches the edge of the space, it teleports to the other side.  

1. **Parsing Input:** The input is a list of robot positions and velocities. Each line follows the format `p=x,y v=dx,dy`, which is extracted into two pairs: `(x, y)` for position and `(dx, dy)` for velocity.  
2. **Updating Positions:** The position of each robot is updated every second based on its velocity. After 100 iterations, the final positions are used to count how many robots are in each quadrant of the grid.  
3. **Handling Wrapping:** Since the space is limited to `101x103` tiles, positions are computed using modulo operations to wrap around correctly.  
4. **Quadrant Count:** The space is divided into four quadrants based on the halfway point `(WIDTH/2, HEIGHT/2)`. Robots exactly on the middle lines are ignored. The count of robots in each quadrant is multiplied to get the final result.  

What is important here is not to simulate the robots, but just calculate for each multiplicating and doing the modulo operation!

</details>  

---

## Part 2  
**Difficulty:** 🌕🌑🌑🌑🌑  

**Approach & Solution:**  
The second part required determining the first moment in time when the robots align into a recognizable Christmas tree shape.

<details>  
<summary>Detailed Explanation (Click to expand)</summary>  
Unlike Part 1, which focused on movement at a fixed time step, this part required detecting a special pattern dynamically.  
It was quite unclear what could be done here, so I decided to try different approaches. First I went into checking the first elements and printing them so I could stop if I saw something different, and finally I guessed that if there is an object, the robots should be either all in different positions or quite different. So I tried printing only the groups of robots that were all non overlapping and I just found a cool chrismtas tree!
</details>  

---

## Conclusions and Thoughts  
This problem was a fun mix of simulation, modulo arithmetic, and pattern detection. Part 1 was straightforward once the wrapping mechanics were in place, but Part 2 required an interesting open-ended approach to pattern recognition, which was not really a full standard problem, but more of a trial and error and thinking out of the box. I liked this a bit though it did not feel fair not to know the expected shape!