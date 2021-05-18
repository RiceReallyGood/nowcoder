#include <vector>
using namespace std;

struct Point {
    int x;
	int y;
};

class Solution {
public:
    vector<long> solve(int n, vector<Point>& edge) {
        this->n = n;
        vector<vector<int>> adj(n);
        for(int i = 0; i < n - 1; i++){
            adj[edge[i].x - 1].push_back(edge[i].y - 1);
            adj[edge[i].y - 1].push_back(edge[i].x - 1);
        }
        vector<int> count(n);
        vector<long> dist(n);
        dfs1(adj, -1, 0, count, dist);
        dfs2(adj, -1, 0, count, dist);
        return dist;
    }

private:
    int n;
    void dfs1(vector<vector<int>>& adj, int prevnode, int currnode, vector<int>& count, vector<long>& dist){
        count[currnode] = 1;
        for(int neighbour : adj[currnode]){
            if(neighbour != prevnode){
                dfs1(adj, currnode, neighbour, count, dist);
                count[currnode] += count[neighbour];
                dist[0] += count[neighbour];
            }
        }
    }

    void dfs2(vector<vector<int>>& adj, int prevnode, int currnode, vector<int>& count, vector<long>& dist){
        for(int neighbour : adj[currnode]){
            if(neighbour != prevnode){
                dist[neighbour] = dist[currnode] + n - 2 * count[neighbour];
                dfs2(adj, currnode, neighbour, count, dist);
            }
        }
    }
};