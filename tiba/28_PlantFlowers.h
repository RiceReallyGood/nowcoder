#include <algorithm>
class Solution {
public:
    int solve(int n) {
        long dp[] = {1, 1, 1, 1, 1};
        long temp[5];

        for(int i = 2; i <= n; i++){
            temp[0] = (dp[0] + dp[1] + dp[2] + dp[3] + dp[4]) % 1000000007;
            temp[1] = (dp[0] + dp[2] + dp[3]) % 1000000007;
            temp[2] = (dp[0] + dp[1] + dp[3] + dp[4]) % 1000000007;
            temp[3] = (dp[0] + dp[1] + dp[2]) % 1000000007;
            temp[4] = (dp[0] + dp[2]) % 1000000007;
            std::swap(temp, dp);
        }
        return (dp[0] + dp[1] + dp[2] + dp[3] + dp[4] - 1) % 1000000007;
    }
};