#include <vector>
#include <cstring>
using namespace std;

class Solution { //段错误
public:
    vector<int> solve(int n, int m, vector<int>& u, vector<int>& v, vector<int>& q) {
        vector<vector<int>> adj(n);
        for(int i = 0; i < n - 1; i++){
            adj[u[i] - 1].push_back(v[i] - 1);
            adj[v[i] - 1].push_back(u[i] - 1);
        }

        vector<int> res(n, 0);
        for(int i = 0; i < m; i++){
            res[q[i] - 1]++;
            for(int neighbour : adj[q[i] - 1])
                res[neighbour]++;
        }
        return res;
    }
};

class Solution {
public:
    vector<int> solve(int n, int m, vector<int>& u, vector<int>& v, vector<int>& q) {
        int a[n];
        memset(a, 0, n * sizeof(int));
        for(int i = 0; i < m; i++)
            a[q[i] - 1]++;
        
        vector<int> res(a, a + n);
        for(int i = 0; i < n - 1; i++){
            res[u[i] - 1] += a[v[i] - 1];
            res[v[i] - 1] += a[u[i] - 1];
        }
        return res;
    }
};