#include <string>
using namespace std;

class Solution {
public:
    int solve(string s) {
        static int mod = 1e9 + 7;
        int dp[7] {0};
        dp[0] = 1;

        for(int i = 0; i < s.length(); i++){
            if(s[i] == 'n'){
                dp[1] = (dp[1] + dp[0]) % mod;
                dp[4] = (dp[4] + dp[3]) % mod;
            }
            else if(s[i] == 'i'){
                dp[2] = (dp[2] + dp[1]) % mod;
                dp[5] = (dp[5] + dp[4]) % mod;
            }
            else if(s[i] == 'u'){
                dp[3] = (dp[3] + dp[2]) % mod;
                dp[6] = (dp[6] + dp[5]) % mod;
            }
        }

        return dp[6];
    }
};