#include <vector>
using namespace std;

class Solution {
public:
    int cutRope(int number) {
        vector<int> dp = {0, 0, 1, 2, 4, 6, 9};
        if(dp.size() < number + 1) dp.resize(number + 1);
        for(int i = 7; i <= number; i++)
            dp[i] = max(dp[i - 2] * 2, dp[i - 3] * 3);
        return dp[number];
    }
};