# Day 23: LAN Party

## Part 1  
**Difficulty:** 🌗🌑🌑🌑🌑  

**Approach & Solution:**  
The first part involved finding *all fully connected trios* of computers (usually referred as cliques of size 3), but only counting those that contained at least one node whose name starts with the letter `'t'`.

<details>  
<summary>Detailed Explanation (Click to expand)</summary>  

The input was parsed into an adjacency matrix representing the undirected graph of the network. Each node label (a two-letter string, e.g., `kh`) was mapped to an integer using a base-26 transformation based on character positions.

1. The adjacency matrix (`connectedGraph`) was constructed with 26×26 possible nodes, corresponding to all possible lowercase letter pairs.
2. For each node whose name starts with `'t'` (precomputed range from `"ta"` to `"tz"`), its neighbors were gathered.
3. For each pair of neighbors of such a node, the code checked whether those two were also connected to each other—forming a triangle.
4. If a valid triangle was found, it was counted. To avoid duplicate triangles being counted multiple times, the logic enforced that the node from the `'t'` range was the highest lexicographically.
5. The triangle was then printed (though this was not essential to the logic), and the count was incremented.

This approach ensured all qualifying cliques of size 3 involving at least one `'t'` node were identified and counted efficiently.

</details>  

---

## Part 2  
**Difficulty:** 🌕🌑🌑🌑🌑  

**Approach & Solution:**  
The second part shifted the focus from triangles to finding the *largest clique* (i.e., the largest subset of computers where every node is connected to every other node). The password to the LAN party was the alphabetical concatenation of the node names in this largest clique.

<details>  
<summary>Detailed Explanation (Click to expand)</summary>  

This solution constructed an undirected graph using an adjacency list for performance and dynamic structure.

1. The input was parsed similarly to Part 1, but connections were stored in a `map<int, list<int>>` for quick lookups and iteration.
2. For each node in the graph, a modified BFS (`getMaximalFullyConnected`) was executed to attempt building the largest clique that includes that node:
   - It started with a single node and expanded the clique only if the candidate node was connected to **every existing member** of the clique.
   - A queue was used to manage BFS traversal.
   - For each new neighbor, the code validated that it connected to all current clique members before adding it.
3. This process was repeated for each node to find the largest such maximal clique.
4. Once found, the members of the largest clique were transformed back to their two-letter names, sorted alphabetically, and printed as the final password.

This brute-force clique search works well due to the relatively small problem size and the constraints imposed.

</details>  

---

## Conclusions and Thoughts  
This problem was a good application of graph theory fundamentals—specifically, triangle detection and fully connected graph identification. The use of compact encoding (turning two-letter strings into integer indices) made it much easier to work with the graph data structures directly.

Part 1 emphasized efficient neighbor iteration and triangle checks, while Part 2 required a maximal clique search with a custom BFS strategy. While not optimal in terms of clique-finding complexity, the practical constraints made the solution viable and effective without needing fancier advanced algorithms. There was no magic in understanding what to do (in other problems you need to dig a bit in the context to get to it), but just to know the concepts and how to solve them.

Still graph problem, as quite a lot were before, but feeling way different that doing Dijkstra or just traversing it. I also liked it as it reminded me of the cliques problems I studied during university related to the NP-completeness  (even if not present here, is tied to the concept of cliques itself).