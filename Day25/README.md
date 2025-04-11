# Day 25: Code Chronicle

## Part 1  
**Difficulty:** 🌗🌑🌑🌑🌑  

**Approach & Solution:**  
The goal for this one was to simulate key and lock compatibility based on schematic representations. Locks had "pins" protruding from the top, keys had "teeth" rising from the bottom, and a key was valid for a lock if no tooth collided with a pin—i.e., in every column, the sum of the heights was less than or equal to the total allowed vertical space.

<details>  
<summary>Detailed Explanation (Click to expand)</summary>  

Each lock or key was represented by a 5×6 grid (`MAX_WIDTH = 5`, `MAX_HEIGHT = 5`) where `'#'` indicated presence of material. The grid was parsed row by row into a single array of heights:

- For **locks**, heights were counted from the top down: a `'#'` in higher rows increased the height.
- For **keys**, the same logic applied but from the bottom up due to flipped orientation.

1. Each schematic was parsed into a vector of column heights.
2. Locks and keys were stored in separate vectors.
3. To determine if a key fits a lock, we iterated over their respective height vectors and verified that `key[i] + lock[i] <= MAX_HEIGHT` for every column.
4. All valid (key, lock) pairs were counted.

It was a classic nested loop search—simple yet effective thanks to tight constraints.

</details>  

---

## Part 2  
**Difficulty:** 🌑🌑🌑🌑🌑  

**Approach & Solution:**  
There was no second computational part for Day 25. It concluded the story and celebrated wrapping up the journey with a symbolic reference to all the places visited during the event.

<details>  
<summary>Detailed Explanation (Click to expand)</summary>  

You want a gift for looking here? I have no gifts, but I can hope the best for you (whoever you are looking for something here) :D

</details>  

---

## Conclusions and Thoughts  
This was a light puzzle to finish on, especially compared to the complexity of prior days. Part 1 was very mechanical—parse, reduce to heights, compare vectors—but it fit perfectly into the puzzle narrative and offered a tiny taste of geometry, constraint checks, and pairwise matching.

I was worried about a complicated part 2, but in the end, the last day did not need to be hard. It was a nice moment of closure: revisiting grid processing, doing some clean input parsing, and ending the whole event with a warm-hearted callback to the story of The Historians. A gentle nod to the many, many maps that dominated this year's edition—fitting that we ended with one more grid-based challenge.
