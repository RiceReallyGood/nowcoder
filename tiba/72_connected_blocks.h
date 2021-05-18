#include <vector>
#include <queue>
using namespace std;

class Solution { //BFS
public:
    bool solve(int n, int k, int m, vector<int>& u, vector<int>& v, vector<int>& x) {
        vector<int> degree(n, 0), gold(x);
        vector<vector<int>> adj(n);

        for(int i = 0; i < n - 1; i++){
            adj[v[i] - 1].push_back(u[i] - 1);
            adj[u[i] - 1].push_back(v[i] - 1);
            degree[u[i] - 1]++;
            degree[v[i] - 1]++;
        }

        queue<int> q;
        for(int i = 0; i < n; i++){
            if(degree[i] == 1)
                q.push(i);
        }

        int count = 0;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            if(gold[node] >= m){
                count++;
                gold[node] = 0;
            }
            for(int neighbour : adj[node]){
                if(degree[neighbour] != 0){
                    gold[neighbour] +=gold[node];
                    if(--degree[neighbour] == 1)
                        q.push(neighbour);
                }
            }
            degree[node]--;
        }

        return count >= k;
    }
};

class Solution { //DFS
public:
    bool solve(int n, int k, int m, vector<int>& u, vector<int>& v, vector<int>& x) {
        vector<vector<int>> adj(n);

        for(int i = 0; i < n - 1; i++){
            adj[v[i] - 1].push_back(u[i] - 1);
            adj[u[i] - 1].push_back(v[i] - 1);
        }

        int gold = 0;
        return dfs(adj, 0, -1, m, x, gold) >= k;
    }

private:
    int dfs(vector<vector<int>>& adj, int node, int from, int m, vector<int>& x, int& gold){
        int count = 0, subtreegold;
        gold = x[node];
        for(int neighbour : adj[node]){
            if(neighbour != from){
                count += dfs(adj, neighbour, node, m, x, subtreegold);
                gold += subtreegold;
            }
        }
        if(gold >= m){
            count++;
            gold = 0;
        }
        return count;
    }
};