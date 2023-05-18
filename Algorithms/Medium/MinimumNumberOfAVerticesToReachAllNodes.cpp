/*
1557. Minimum Number of Vertices to Reach All Nodes

Given a directed acyclic graph, with n vertices numbered from 0 to n-1, and an array edges 
where edges[i] = [fromi, toi] represents a directed edge from node fromi to node toi.

Find the smallest set of vertices from which all nodes in the graph are reachable. It's guaranteed that a 
unique solution exists.

Notice that you can return the vertices in any order.
*/

class Solution {
public:
    std::vector<int> findSmallestSetOfVertices(int n, std::vector<std::vector<int>>& edges) 
    {
        std::vector<int> vec(n);

        for (const std::vector<int> e : edges)
            vec[e[1]] = 1;

        std::vector<int> res;

        for (int i = 0; i < n; i++)
            if (vec[i] == 0) res.push_back(i);

        return res;
    }
};
