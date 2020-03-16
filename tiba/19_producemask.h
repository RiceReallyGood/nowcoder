#include <vector>
using namespace std;

struct Point {
    int x;
	int y;
};



class Solution {
public:
    int producemask(int n, int m, vector<vector<Point> >& strategy) {
        vector<int> dp(m + 1, 0), currdp(m + 1, 0);
        for(int line = 0; line < n; line++){
            for(int s = 0; s < strategy[line].size(); s++){
                vector<int> temp(dp);
                for(int i = m; i >= strategy[line][s].x; i--){
                    temp[i] = max(temp[i], temp[i - strategy[line][s].x] + strategy[line][s].y);
                    currdp[i] = max(currdp[i], temp[i]);
                }
            }
            for(int i = 0; i <= m; i++)
                dp[i] = currdp[i];
        }
        return dp[m];
    }
};