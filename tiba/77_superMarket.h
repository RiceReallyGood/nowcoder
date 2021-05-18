#include <vector>
using namespace std;

class Solution {
public:
    int solve(int n, int x, vector<vector<int> >& a) {
        vector<int> dp(x + 1, 0);
        dp[0] = 1;

        for(int i = 0; i < n; i++){
            int coin = a[i][0], count = a[i][1];
            for(int j = x; j >= coin; j--){
                for(int k = 1; k <= count && j - k * coin >= 0; k++){
                    dp[j] += dp[j - k * coin];
                }
            }
        }

        return dp[x];
    }
};