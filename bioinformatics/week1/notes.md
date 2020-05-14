## Multiple String Matching

Why lmin (smallest pattern) ? Slide Windows can be at most lmin size because we can't jump longer that the length of the smallest pattern

### Set Horspool algorithm

1. Construct trie of the inverse of the patterns
2. Determine lmin
3. Determine the sift table
4. Find the patterns

### Wu-Manber algorithm

Instead of taking into account 1 character, we take into account 2 characters.
