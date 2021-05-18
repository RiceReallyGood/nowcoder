#include <vector>
using namespace std;

class Solution {
public:
    int solve(int n, vector<int>& a1, vector<int>& a2, vector<int>& a3, vector<int>& m) {
        vector<int> dp1(n), dp2(n), dp3(n);
        dp1[0] = a1[0], dp2[0] = a2[0], dp3[0] = a3[0];
        for(int i = 1; i < n; i++){
            dp1[i] = a1[i] + max(dp1[i - 1], dp2[i - 1] - m[i - 1]);
            dp2[i] = a2[i] + max(dp2[i - 1], max(dp1[i - 1], dp3[i - 1]) - m[i - 1]);
            dp3[i] = a3[i] + max(dp3[i - 1], dp2[i - 1] - m[i - 1]);
        }
        return max(dp1[n - 1], max(dp2[n - 1], dp3[n - 1]));
    }
};

class Solution {
public:
    int solve(int n, vector<int>& a1, vector<int>& a2, vector<int>& a3, vector<int>& m) {
        int dp1 = a1[0], dp2= a2[0], dp3 = a3[0];
        for(int i = 1; i < n; i++){
            int temp1 = dp1, temp2 = dp2, temp3 = dp3;
            dp1 = a1[i] + max(temp1, temp2 - m[i - 1]);
            dp2 = a2[i] + max(temp2, max(temp1, temp3) - m[i - 1]);
            dp3 = a3[i] + max(temp3, temp2- m[i - 1]);
        }
        return max(dp1, max(dp2, dp3));
    }
};