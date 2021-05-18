#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<bool> continuousSet(vector<int>& mSet) {
        if(mSet.empty()) return {};
        int n = mSet.size();
        unordered_set<int> eles;
        vector<bool> res(n, false);
        eles.insert(mSet[0]);
        res[0] = true;
        int minval = mSet[0], maxval = mSet[0];
        for(int i = 1; i < mSet.size(); i++){
            eles.insert(mSet[i]);
            minval = min(minval, mSet[i]);
            maxval = max(maxval, mSet[i]);
            res[i] = (maxval - minval + 1 == eles.size());
        }
        return res;
    }
};