#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    double solve(vector<int>& a) {
        int N = a.size();
        sort(a.begin(), a.end());
        double maxarea = 0;
        for(int i = 0; i < N; i++){
            for(int j = i + 1; j < N; j++){
                for(int k = j + 1; k < N; k++){
                    int sum = a[i] + a[j] + a[k];
                    for(int l = k + 1; l < N; l++){
                        if(a[l] >= sum) break;
                        double s = (sum + a[l]) / 2.;
                        maxarea = max(maxarea, sqrt((s - a[i]) * (s - a[j]) * (s - a[k]) * (s - a[l])));
                    }
                }
            }
        }
        return maxarea;
    }
};