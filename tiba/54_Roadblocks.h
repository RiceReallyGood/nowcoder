#include <vector>
using namespace std;

class Solution {
public:
    int solve(int n, int m, vector<int>& x, vector<int>& y) {
        static int mod = 1e9 + 7;
        vector<vector<int>> dp(3, vector<int>(n, 0));
        for(int i = 0; i < m; i++)
            dp[x[i] - 1][y[i] - 1] = -1;
        dp[0][0] = 1; dp[1][0] = 0, dp[2][0] = 0;

        for(int i = 1; i < n; i++){
            if(dp[0][i] == -1){
                dp[0][i] = 0;
            }
            else{
                dp[0][i] = (dp[0][i - 1] + dp[1][i - 1]) % mod;
            }

            if(dp[1][i] == -1){
                dp[1][i] = 0;
            }
            else{
                dp[1][i] = (long(dp[0][i - 1]) + dp[1][i - 1] + dp[2][i - 1]) % mod;
            }

            if(dp[2][i] == -1){
                dp[2][i] = 0;
            }
            else{
                dp[2][i] = (dp[1][i - 1] + dp[2][i - 1]) % mod;
            }
        }

        return dp[2][n - 1];
    }
};