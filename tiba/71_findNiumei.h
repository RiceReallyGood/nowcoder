#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> solve(int n, int m, vector<int>& u, vector<int>& v, vector<int>& x) {
        vector<int> depth(n), count(n);
        vector<vector<int>> adj(n);
        for(int i = 0; i < n - 1; i++){
            adj[u[i] - 1].push_back(v[i] - 1);
            adj[v[i] - 1].push_back(u[i] - 1);
        }
        depth[0] = 0;
        dfs(adj, 0, -1, depth, count);

        vector<int> res(m);
        for(int i = 0; i < m; i++){
            res[i] = (n - count[x[i] - 1]) * 2 - depth[x[i] - 1];
        }
        return res;
    }

private:
    void dfs(vector<vector<int>>& adj, int node, int from, vector<int>& depth, vector<int>& count){
        count[node] = 1;
        for(int neighbour : adj[node]){
            if(neighbour != from){
                depth[neighbour] = depth[node] + 1;
                dfs(adj, neighbour, node, depth, count);
                count[node] += count[neighbour];
            }
        }
    }
};