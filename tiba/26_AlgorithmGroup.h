#include <vector>
using namespace std;

class Solution { //worst O(N ^ 2) TLE
public:
    vector<int> solve(int n, vector<int>& a, vector<int>& p, vector<int>& k) {
        vector<int> count(n);
        for(int i = 0; i < n; i++){
            int solver = i;
            while(a[solver] < k[i] && solver != 0)
                solver = p[solver - 1] - 1;

            if(a[solver] >= k[i]) count[solver]++;
        }
        return count;
    }
};

class Solution { //time O(N log N) space O(N log N)
public:
    vector<int> solve(int n, vector<int>& a, vector<int>& p, vector<int>& k) {
        vector<int> depth(n, -1);
        depth[0] = 0;
        for(int i = 1; i < n; i++) FindDepth(i, p, depth);
        int maxdepth = 0;
        for(int i = 0; i < n; i++) maxdepth = max(maxdepth, depth[i]);
        int pow2 = 1, sz = 1;
        while(pow2 < maxdepth){
            pow2 *= 2;
            sz++;
        }
        vector<vector<int>> higherlevel(sz, vector<int>(n));
        for(int i = 1; i < n; i++) higherlevel[0][i] = p[i - 1] - 1;
        for(int l = 1; l < sz; l++){
            for(int i = 0; i < n; i++)
                higherlevel[l][i] = higherlevel[l - 1][higherlevel[l - 1][i]]; 
        }
        vector<int> count(n);
        for(int i = 0; i < n; i++){
            if(a[i] >= k[i]){
                count[i]++;
                continue;
            }
            int holder = i;
            for(int l = sz - 2; l >= 0; l--){
                if(a[higherlevel[l][holder]] < k[i]) holder = higherlevel[l][holder];
            }
            holder = higherlevel[0][holder];
            if(a[holder] >= k[i]) count[holder]++;
        }
        return count;
    }

private:
    int FindDepth(int i, vector<int>& p, vector<int>& depth){
        if(depth[i] != -1) return depth[i];
        return depth[i] = FindDepth(p[i - 1] - 1, p, depth) + 1;
    }
};