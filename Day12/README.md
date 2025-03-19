
# Day 12: Garden Groups  

## Part 1  
**Difficulty:** 🌗🌑🌑🌑🌑  

**Approach & Solution:**  
The task involved identifying contiguous regions of garden plots and calculating both their area and perimeter. The key challenge was ensuring the perimeter counted only external edges.

<details>  
<summary>Detailed Explanation (Click to expand)</summary>  
The solution involved traversing the garden map and applying a flood-fill algorithm to explore regions:  

1. **Parsing the Input:** The input was read into a `matrix`, and a `visited` array was initialized to track explored regions.  
2. **Flood Fill for Regions:** The function `exploreRegion(x, y, regChar)` performed a depth-first search (DFS) to identify all connected cells of the same plant type.  
3. **Area Calculation:** The area was simply the count of all connected cells in a region.  
4. **Perimeter Calculation:** The function checked the four possible directions (left, right, up, down). If a neighboring cell was outside the matrix or had a different plant type, that counted as part of the perimeter.  
5. **Multiplication for Cost Calculation:** The cost of fencing each region was computed as `area * perimeter`, and all costs were summed up to get the final answer.  

The approach efficiently handled large matrices by ensuring each cell was only visited once. Also it was simple as perimeter was considered as each direction and not just each cell that is in the border. This made it easy to compute.

</details>  

---

## Part 2  
**Difficulty:** 🌕🌗🌑🌑🌑

**Approach & Solution:**  
The second part modified the perimeter calculation to count distinct sides rather than individual exposed edges.

<details>  
<summary>Detailed Explanation (Click to expand)</summary>  
Building on Part 1, a refined approach was taken to count the sides:  

1. **Using Pairs for Positioning:** Instead of `(x, y)`, the positions were stored as `pair<long, long>` to improve readability and reduce redundancy in coordinate handling. An operator was also defined to simplify this approach.
2. **Boundary Handling with Special Cases:** Additional conditions were added to detect internal corners and adjust the side count accordingly.  
For this a not so beautiful check was crafted (thanks to some hand-written annotations and ideas) and I was able to find a formula to know if a cell was in the border and how many borders it added to the total, depending on the previous cell too.
3. **Cost Recalculation:** The final cost was computed as `area * sides`, with the new fencing rules applied.  

This approach required careful consideration of the geometry of each region, ensuring that inner and outer boundaries were counted correctly.  

</details>  

---

## Conclusions and Thoughts  
This problem was a fine exercise in region detection and boundary calculations. The first part was relatively straightforward, using DFS to explore regions, but the second part added a layer of complexity by requiring a shift in the definition of "perimeter."  

The trickiest part was handling the boundary cases correctly, especially ensuring that touching regions did not cause the boundary to overlap. I tried other approaches at the time being, but ended up with the if/else logic, which is far from straightforward and clear, but works quickly and is simple once you are able to understand the boundary cases. (This was the first time I had to write some notes in my notebook)
