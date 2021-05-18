#include <vector>
using namespace std;

class Solution {
public:
    vector<int> solve(int n, vector<int>& a) {
        vector<vector<int>> dp0(n, vector<int>(201, -1));
        vector<vector<int>> dp1(n, vector<int>(201, -1));
        for(int i = 0; i < n; i++){
            dp0[i][a[i]] = 0;
        }

        int sum = 0;
        for(int num : a) sum += num;

        vector<int> ret;
        for(int act = 1; act <= n; act++){
            vector<vector<int>> temp0(n, vector<int>(201, -1));
            vector<vector<int>> temp1(n, vector<int>(201, -1));
            for(int i = act - 1; i < n; i++){
                if(i == 0){
                    temp1[i][a[i]] = 0;
                    continue;
                }
                for(int x = a[i - 1]; x <= 200; x++){
                    if(dp0[i - 1][x] != -1){
                        if(x < a[i]){
                            temp1[i][a[i]] = max(temp1[i][a[i]], dp0[i - 1][x] + a[i] - x);
                        }
                        else{
                            temp1[i][x] = max(temp1[i][x], dp0[i - 1][x] + x - a[i]);
                        }
                    }

                    if(dp1[i - 1][x] != -1){
                        if(x < a[i]){
                            temp1[i][a[i]] = max(temp1[i][a[i]], dp1[i - 1][x] + (2 - (i == 1)) * (a[i] - x));
                        }
                        else{
                            temp1[i][x] = max(temp1[i][x], dp1[i - 1][x] + x - a[i]);
                        }
                    }

                    if(temp0[i - 1][x] != -1){
                        temp0[i][a[i]] = max(temp0[i][a[i]], temp0[i - 1][x]);
                    }

                    if(temp1[i - 1][x] != -1){
                        if(x < a[i]){
                            temp0[i][a[i]] = max(temp0[i][a[i]], temp1[i - 1][x] + (2 - (i == 1)) * (a[i] - x));
                        }
                        else{
                            temp0[i][x] = max(temp0[i][x], temp1[i - 1][x] + x - a[i]);
                        }
                    }
                }
            }
            dp0.swap(temp0);
            dp1.swap(temp1);

            int maxdiff = 0;
            for(int i = a[n - 1]; i <= 200; i++){
                maxdiff = max(maxdiff, dp0[n - 1][i]);
                maxdiff = max(maxdiff, dp1[n - 1][i]);
            }
            ret.push_back(sum + maxdiff);
        }
        return ret;
    }
};