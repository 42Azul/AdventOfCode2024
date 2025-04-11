# Day 19: Linen Layout

## Part 1  
**Difficulty:** 🌗🌑🌑🌑🌑  

**Approach & Solution:**  
This one was about constructing stripe patterns using a given set of towel patterns. Each design had to be built exactly using the available towels—no flipping, no improvising.

<details>  
<summary>Detailed Explanation (Click to expand)</summary>  
I used a recursive approach with memoization. The idea was to treat the towel patterns as a set of valid prefixes and, for each design, try splitting it at every index. If the prefix is in the set and the remaining suffix can be built recursively, the design is considered valid.  

Key steps:
1. Parse the towel patterns into a `unordered_set` for quick lookup.
2. For each design, recursively try to build it by matching known prefixes.
3. Memoize positive results to speed up future checks.

It’s pretty much a brute-force strategy but efficient enough thanks to early pruning and the hash set.
</details>  

---

## Part 2  
**Difficulty:** 🌕🌕🌕🌗🌑

**Approach & Solution:**  
Now we had to count *all* the different ways a design can be built using the towels. So not just “is it possible?”, but “how many ways can it be done?”. That escalated quickly.

<details>  
<summary>Detailed Explanation (Click to expand)</summary>  
It was required to flip the perspective: instead of checking from the start, I reversed the strings and built a trie with the towel patterns. That let me efficiently match suffixes (which are actually prefixes in the reversed string).

1. Build a reverse trie with all towel patterns.
2. For each design, run a DP where each `count[i]` counts the number of ways to build the substring `0..i` splitting or not splitting it in different subsplits (this is where DP comes in handy as smaller checks would have been made already).
3. Walk backwards through the string and look for matches in the trie. Every time we hit a towel end in the trie, we add to the count.

It’s classic DP + trie/suffix-tree combo—kind of like word segmentation problems but in reverse.
</details>  

---

## Conclusions and Thoughts  
Classic word break problem in disguise. Part 1 was a straight memoized DFS; nothing fancy. 

Part 2 needed a bit more care to count paths properly. I had to research a bit because I used some tries back in my competitive programming studies, so it sounded the match for me. After thinking and looking for other things I had done before this is where some suffix tree and DP came in. The whole thing was pretty clean once you saw it, but the most complex problem for now.