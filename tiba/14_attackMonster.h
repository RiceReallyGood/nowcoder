#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int attackMonster(int monsterLength, vector<int>& monsterPoint) {
        if(monsterPoint.size() == 0) return 0;
        if(monsterPoint.size() == 1) return monsterLength;
        
        int attackPointCount = monsterPoint.size();
        sort(monsterPoint.begin(), monsterPoint.end());
        monsterPoint.push_back(monsterLength);
        monsterPoint.resize(attackPointCount + 2);
        for(int i = attackPointCount + 1; i > 0; i--) monsterPoint[i] = monsterPoint[i - 1];
        monsterPoint[0] = 0;
        vector<vector<int>> dp(attackPointCount, vector<int>(attackPointCount, 0));
        for(int i = 0; i <attackPointCount; i++) dp[i][i] = monsterPoint[i + 2] - monsterPoint[i];

        for(int len = 2; len <= attackPointCount; len++){
            for(int i = 0; i <= attackPointCount - len; i++){
                int j = i + len - 1;
                dp[i][j] = min(dp[i + 1][j], dp[i][j - 1]);
                for(int k = i + 1; k < j; k++)
                    dp[i][j] = min(dp[i][j], dp[i][k - 1] + dp[k + 1][j]);
                dp[i][j] += monsterPoint[j + 2] - monsterPoint[i];
            }
        }
        return dp[0][attackPointCount - 1];
    }
};