#include <vector>
using namespace std;

class Solution {
public:
    int solve(int n, int k, vector<int>& x, vector<int>& y, vector<int>& a) {
        int R = 0, C = 0;
        for(int i = 0; i < n; i++){
            R = max(R, x[i]);
            C = max(C, y[i]);
        }

        vector<vector<int>> board(R + 1, vector<int>(C + 1, 0));
        vector<vector<int>> dp(R + 1, vector<int>(C + 1, 0)), temp = dp;

        for(int i = 0; i < n; i++)
            board[x[i]][y[i]] = max(board[x[i]][y[i]], a[i]);
        
        for(int key = 1; key <= k; key++){
            dp.swap(temp);
            for(int i = 1; i <= R; i++){
                for(int j = 1; j <= C; j++){
                    dp[i][j] = max(temp[i - 1][j - 1] + board[i][j], max(dp[i - 1][j], dp[i][j - 1]));
                }
            }
        }
        return dp[R][C];
    }
};