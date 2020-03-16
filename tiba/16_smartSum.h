#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    int smartSum(int number, int* si, int siLen, int* fi, int fiLen) {
        int MinSmartSum = 0, MaxSmartSum = 0;
        for(int i = 0; i < number; i++){
            if(si[i] < 0) MinSmartSum += si[i];
            else MaxSmartSum += si[i];
        }

        int sz = MaxSmartSum - MinSmartSum + 1;
        vector<int> dp(sz, INT_MIN);
        dp[-MinSmartSum] = 0;
        for(int i = 0; i < number; i++){
            if(si[i] > 0){
                for(int j = sz - 1; j >= si[i]; j--)
                    if(dp[j - si[i]] != INT_MIN)
                        dp[j] = std::max(dp[j], dp[j - si[i]] + fi[i]);
            }
            else{
                for(int j = 0; j < sz + si[i]; j++)
                    if(dp[j - si[i]] != INT_MIN)
                        dp[j] = std::max(dp[j], dp[j - si[i]] + fi[i]);
            }
        }

        int ret = 0;
        for(int i = -MinSmartSum; i < sz; i++)
            if(dp[i] >= 0)
                ret = max(ret, dp[i] + i + MinSmartSum);
        return ret;
    }
};