# A*

Compute the shortest path between two vertices of a graph.

- At each step picks the node according to the lowest f(x) = g(x) + h(x)
- g(x) = the movement cost to move from the starting point to a given square
- h(x) = estimated movement cost from that given square to the final destination. Heuristic

## Time Complexity

- O(|E|) worst-case (traverse all edges)
- O(|V|) wors-case (all vertices in OPEN list)

## DFS vs A* vs Dijkstra

1. One source and one destination
  - Use A*       (for unweighted and weighted graphs)
2. One source, all destination
  - BFS          (for unweighted graphs)
  - Dijkstra     (for weighted graphs without negative weights)
  - Bellman Ford (for weighted graphs with negative weights)
3. Between every pair of nodes
  - Floyd-Warshall
  - Johnson's

## Algorithm

1. Initialize the open list
2. Initialize the closed list.
3. Put the starting node on the open list (you can leave its f at zero).
4. While the open list is not empty:
  - Find the node with the least f on the open list, call it 'q'
  - Pop 'q' off the open list
  - Generate q's successors and set their parents to 'q'
  - For each succ:
    - If succ. is the goal, stop the search.
       Else succ.g = q.g + distance between successor and 'q'
            succ.h = distance from goal to the successor
            succ.f = succ.g + succ.h
    - If     succ. is in the OPEN list which has a lower f than succ., then skip.
      ElseIf succ. is in the CLOSED list which has a lower f than succ., then skip succ.
      Else   add succ. to the OPEN list end.
  - Push 'q' on the closed list

## Heuristics

Approaches:

1. Exact Heuristics
  - Pre-compute the distance between each pair of cells.

2. Approximation heuristics
  - Manhattan distance
  - Diagonal distance
  - Euclidean distance

## Implementation

Similar to Dijstra'ls algorithm.

We can use a Fibonacci heap to implement the open list instead of a binary heap/self-balancing tree. Fibonnaci heap takes O(1) average time to insert/decrease-key).

Dynamic programming is also useful to calculate g.

## Limitations

It does not always produce the shortest path, as it relies heavily on heuristics/approximations.
