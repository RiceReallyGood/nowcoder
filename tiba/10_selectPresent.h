#include <vector>
using namespace std;

class Solution {
public:
    int selectPresent(vector<vector<int> >& presentVolumn) {
        if(presentVolumn.empty() || presentVolumn[0].empty()) return 0;
        int m = presentVolumn.size(), n = presentVolumn[0].size();
        vector<int> dp(n, 0);
        dp[0] = presentVolumn[0][0];
        for(int j = 1; j < n; j++) dp[j] = dp[j - 1] + presentVolumn[0][j];
        for(int i = 1; i < m; i++){
            vector<int> temp(n, 0);
            temp[0] = dp[0] + presentVolumn[i][0];
            for(int j = 1; j < n; j++){
                temp[j] = min(temp[j - 1], min(dp[j - 1], dp[j])) + presentVolumn[i][j];
            }
            swap(dp, temp);
        }
        return dp[n - 1];
    }
};

class Solution {
public:
    int selectPresent(vector<vector<int> >& presentVolumn) {
        if(presentVolumn.empty() || presentVolumn[0].empty()) return 0;
        int m = presentVolumn.size(), n = presentVolumn[0].size();
        vector<int> dp(n, 0);
        dp[0] = presentVolumn[0][0];
        for(int j = 1; j < n; j++) dp[j] = dp[j - 1] + presentVolumn[0][j];
        for(int i = 1; i < m; i++){
            int prevtemp = dp[0], currtemp;
            dp[0] = dp[0] + presentVolumn[i][0];
            for(int j = 1; j < n; j++){
                currtemp = dp[j];
                dp[j] = min(dp[j], min(dp[j - 1], prevtemp)) + presentVolumn[i][j];
                prevtemp = currtemp;
            }
        }
        return dp[n - 1];
    }
};