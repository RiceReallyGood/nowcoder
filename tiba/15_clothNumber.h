#include <vector>
using namespace std;

class Solution {
public:
    int clothNumber(int L, int W, vector<vector<int> >& clothSize) {
        vector<vector<int>> dp(L + 1, vector<int>(W + 1, 0));
        for(auto& cs : clothSize){
            if(cs[0] <= L && cs[1] <= W){
                for(int j = cs[1]; j <= W; j++)
                    dp[cs[0]][j] = max(dp[cs[0]][j], dp[cs[0]][j - cs[1]] + 1);
                
                for(int j = cs[0] + 1; j <= L; j++){
                    for(int k = cs[1]; k <= W; k++){
                        dp[j][k] = max(dp[j][k], dp[j - cs[0]][k] + dp[cs[0]][k]);
                    }
                }
            }

            if(cs[1] <= L && cs[0] <= W){
                for(int j = cs[0]; j <= W; j++)
                    dp[cs[1]][j] = max(dp[cs[1]][j], dp[cs[1]][j - cs[0]] + 1);
                
                for(int j = cs[1] + 1; j <= L; j++){
                    for(int k = cs[0]; k <= W; k++){
                        dp[j][k] = max(dp[j][k], dp[j - cs[1]][k] + dp[cs[1]][k]);
                    }
                }
            }
        }
        return dp[L][W];
    }
};