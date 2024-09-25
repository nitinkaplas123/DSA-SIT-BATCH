
Properties ->
1)Space used -> O(V*V)


2)Check if u and v are adjacent or not. -> O(1)
3)Find all vertices adjacent to u -> O(V)
4)Degree of u -> O(V)
5)Remove edges ->O(1)  making 1 as 0
6)Add an edge -> O(1)  making 0 as 1 



adjacent List -:
Problem with adjacent matrix it stores that value of edge which is not there.

But in adjacent list we store only those value which we need.



Properties -:
1)Space used ->O(V+E) in directed graph 
             ->O(V+2*E) in undirected graph

2)Check if there is an edge bw u to v -> O(V)
3)Find all adjacent of u -> O(degree(u))
4)Add and edge ->O(1)
5)Remove an edge ->O(V)  bcz we have to search the vertex.


