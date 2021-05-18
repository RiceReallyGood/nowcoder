#include <vector>
#include <cstring>
using namespace std;

class Solution {
public:
    int solve(int n) {
        static int mod = 1e9 + 7;
        int dp[15] {0};
        dp[7] = 1;
        int temp[15];

        for(int q = 0; q < n; q++){
            memcpy(temp, dp, 15 * sizeof(int));
            memset(dp, 0, 15 * sizeof(int));
            for(int a = 1; a < 16; a++){
                int AmC = ((a >> 0) & 1) - ((a >> 1) & 1);
                int BmD = ((a >> 2) & 1) - ((a >> 3) & 1);
                for(int state = 0; state < 15; state++){
                    int i = state / 5, j = state % 5;
                    if(i - AmC >= 0 && i - AmC < 3 && j - BmD >= 0 && j - BmD < 5){
                        dp[state] = (dp[state] + temp[(i - AmC) * 5 + (j - BmD)]) % mod;
                    }
                }
            }
        }

        int sum = 0;
        for(int state = 0; state < 15; state++)
            sum = (sum + dp[state]) % mod;
        return sum;
    }
};