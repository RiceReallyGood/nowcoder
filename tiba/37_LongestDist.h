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
        long longestpath = 0;
        dfs(0, 0, adj, longestpath);
        return longestpath;
    }

private:
    long dfs(int comefrom, int root, vector<vector<pair<int, int>>>& adj, long& longestpath){
        // return the height of this tree
        // and the reference longestpath becomes the longest path in this tree
        long first = 0, second = 0;
        for(auto child : adj[root]){
            if(child.first == comefrom) continue;
            long height = child.second + dfs(root, child.first, adj, longestpath);
            if(height >= first){
                second = first;
                first = height;
            }
            else if(height > second)
                second = height;
        }
        longestpath = max(longestpath, first + second);
        return first;
    }
};