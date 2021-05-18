#include <vector>
using namespace std;

class Solution {
public:
    vector<int> solve(int n, int m, vector<int>& l, vector<int>& r, vector<int>& k) {
        vector<bool> rotated(n, false);
        for(int i = 0; i < m; i++){
            rotated[k[i] - 1] = !rotated[k[i] - 1];
        }

        vector<int> path;
        inorder(l, r, 1, rotated, path);
        return path;
    }

private:
    void inorder(vector<int>& l, vector<int>& r, int n, vector<bool>& rotated, vector<int>& path){
        if(n == 0) return;

        if(rotated[n - 1]) swap(l[n - 1], r[n - 1]);
        if(l[n - 1] != 0) rotated[l[n - 1] - 1] = rotated[n - 1] ^ rotated[l[n - 1] - 1];
        if(r[n - 1] != 0) rotated[r[n - 1] - 1] = rotated[n - 1] ^ rotated[r[n - 1] - 1];
        inorder(l, r, l[n - 1], rotated, path);
        path.push_back(n);
        inorder(l, r, r[n - 1], rotated, path);
    }
};