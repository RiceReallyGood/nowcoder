#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int> > FindContinuousSequence(int sum) {
        int l = 1, r = sum + 1;
        while(l < r){
            int c = l + (r - l) / 2;
            if(c * (c + 1) / 2  <= sum)
                l = c + 1;
            else
                r = c;
        }
        vector<vector<int>> ret;
        for(int len = l - 1; len >= 2; len--){
            if((sum - len * (len - 1) / 2) % len == 0){
                int startpoint = (sum - len * (len - 1) / 2) / len;
                vector<int> temp;
                for(int i = 0; i < len; i++)
                    temp.push_back(startpoint + i);
                ret.push_back(temp);
            }
        }
        return ret;
    }
};