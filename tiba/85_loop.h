#include <vector>
#include <string>
using namespace std;

struct Point {
    int x;
    int y;
};


class Solution {
public:
    string solve(vector<int>& param, vector<Point>& edge) {
        int n = param[0], m = param[1];
        vector<bool> visited(n, false);
        vector<vector<int>> adj(n);
        for(int i = 0; i < m; i++){
            adj[edge[i].x - 1].push_back(edge[i].y - 1);
            adj[edge[i].y - 1].push_back(edge[i].x - 1);
        }

        return dfs(adj, visited, 0, -1) ? "Yes" : "No";
    }

private:
    bool dfs(vector<vector<int>>& adj, vector<bool>& visited, int node, int from){
        if(visited[node]) return node == 0;

        visited[node] = true;
        for(int neighbour : adj[node]){
            if(neighbour != from && dfs(adj, visited, neighbour, node))
                return true;
        }

        return false;
    }
};