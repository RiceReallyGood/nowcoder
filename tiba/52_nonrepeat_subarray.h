#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int solve(int n, vector<int>& a) {
        int i = 0, j = 0;
        unordered_set<int> colors;
        int res = 0;
        while(i < n){
            if(colors.find(a[j]) == colors.end()){
                colors.insert(a[j]);
                j = (j + 1) % n;
                res = max<int>(res, colors.size());
            }
            else{
                while(i < n && a[i] != a[j])
                    colors.erase(a[i++]);
                if(i < n)
                    colors.erase(a[i++]);
            }
        }
        return res;
    }
};