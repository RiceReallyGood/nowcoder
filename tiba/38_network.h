#include <vector>
using namespace std;

class Solution {
public:
    long long solve(int n, vector<int>& u, vector<int>& v, vector<int>& w) {
        vector<vector<pair<int, int>>> adj(n);
        for(int i = 0; i < n - 1; i++){
            adj[u[i] - 1].push_back(make_pair(v[i] - 1, w[i]));
            adj[v[i] - 1].push_back(make_pair(u[i] - 1, w[i]));
        }
        long mostimportantedge = 0;
        dfs(0, 0, adj, mostimportantedge);
        return mostimportantedge;
    }

private:
    int dfs(int comefrom, int root, vector<vector<pair<int, int>>>& adj, long& mostimportantedge){
        int nodes = 0;
        for(auto child : adj[root]){
            if(child.first == comefrom) continue;
            int subtreenodes = dfs(root, child.first, adj, mostimportantedge);
            nodes += subtreenodes;
            mostimportantedge = max(mostimportantedge, long(subtreenodes) * long(adj.size() - subtreenodes) * long(child.second));
        }
        return nodes + 1;
    }
};