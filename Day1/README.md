# Day 1 : Historian Hysteria

## Part 1 
**Difficulty:** :🌗🌑🌑🌑🌑

**Approach & Solution:**
The problem involved calculating the sum of absolute differences between two sets of numbers once they were sorted in descending order.

<details>
<summary>Detailed Explanation (Click to expand)</summary>
Priority queues were ideal for efficiently managing and comparing the largest elements first. The input was read and inserted into two separate max-heaps. The main loop compared the largest elements from each queue, added their absolute difference to the total sum, and then removed them. This approach ensured O(n log n) complexity.
</details>

---

## Part 2
**Difficulty:** 🌗🌑🌑🌑🌑

**Approach & Solution:**
The second part required counting how many times an element in the left column appeared in the right column, and summing the product of the number and its count of appearances.

<details>
<summary>Detailed Explanation (Click to expand)</summary>
Priority queues once again simplified the process. Building on Part 1, this part added logic to track repeated values. If the top of the left queue was greater, repeated values were processed by calculating their weighted sum using their frequency. For matching values, only the top of the right queue was removed, and a counter incremented appropriately. The ordered structure of the queues streamlined this process.
</details>

---

## Conclusions and Thoughts

This first day served as a quick warm-up, with basic logic and the efficient use of priority queues. When I solved it in some minutes, I thought that even if it was already mid-December I surely had time for the whole challenge (but I was way far from reality).
