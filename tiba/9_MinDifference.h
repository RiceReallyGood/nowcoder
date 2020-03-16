#include <vector>
using namespace std;

class Solution {
public:
    int maxPresent(vector<int>& presentVec) {
        int sum = 0;
        for(int present : presentVec) sum += present;
        if(sum == 0) return 0;
        vector<bool> dp(sum + 1, false);
        dp[0] = true;
        for(int i = 0; i < presentVec.size(); i++){
            vector<bool> temp(sum + 1, false);
            for(int diff = 0; diff <= sum; diff++){
                if(dp[diff]){
                    if(diff >= presentVec[i]) temp[diff - presentVec[i]] = true;
                    else temp[presentVec[i] - diff] = true;

                    temp[diff + presentVec[i]] = true;
                }
            }
            swap(temp, dp);
        }
        for(int i = 0; i <= sum; i++)
            if(dp[i]) return i;
        return -1;
    }
};