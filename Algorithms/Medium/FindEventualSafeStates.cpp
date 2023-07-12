/*
802. Find Eventual Safe States

There is a directed graph of n nodes with each node labeled from 0 to n - 1. The graph is represented by a 0-indexed 2D integer array graph where graph[i] is an integer array of nodes adjacent to node i, meaning there is an edge from node i to each node in graph[i].

A node is a terminal node if there are no outgoing edges. A node is a safe node if every possible path starting from that node leads to a terminal node (or another safe node).

Return an array containing all the safe nodes of the graph. The answer should be sorted in ascending order.
*/


class Solution {
public:
    bool cycle(int i, std::unordered_set<int> &s)
    {
        if (m[i].empty()) return false;
        if (c[i] == -1) return false;
        if (c[i] == 1) return true;

        bool res = false;
        for(int v : m[i])
        {
            if (s.count(v)) return true;
            s.insert(v);
            res += cycle(v, s);
            if (res == false)
            {
                m[v].clear();
                c[v] = -1;
            }
            else
            {
                c[v] = 1;
                return true;
            }
            s.erase(v);
        }

        return res;
    }


    std::vector<int> eventualSafeNodes(std::vector<std::vector<int>>& graph)
    {
        std::vector<int> res{};
        for (int i = 0; i < graph.size(); i++)
        {
            if (graph[i].empty()) m[i] = {};
            else for (int v : graph[i]) m[i].insert(v);
        }

        for (int i = 0; i < graph.size(); i++)
        {
            auto s = std::unordered_set<int> {i};
            if (cycle(i, s) == false) res.push_back(i);
        }

        return res;
    }
    std::unordered_map<int, int> c;
    std::unordered_map<int, std::unordered_set<int>> m;
};
