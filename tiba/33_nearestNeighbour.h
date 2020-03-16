#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> solve(int n, int m, vector<int>& a, vector<int>& x) {
        vector<int> ret(m);
        sort(a.begin(), a.end());
        for(int i = 0; i < m; i++){
            int right = GetLowerboundIndex(x[i], a);
            if(right == n) ret[i] = x[i] - a[n - 1];
            else if(right == 0) ret[i] = a[0] - x[i];
            else ret[i] = min(a[right] - x[i], x[i] - a[right - 1]);
        }
        return ret;
    }

private:
    int GetLowerboundIndex(int target, vector<int>& a){
        int l = 0, r = a.size();
        while(l < r){
            int c = l + (r - l) / 2;
            if(a[c] < target)
                l = c + 1;
            else
                r = c;
        }
        return l;
    }
};