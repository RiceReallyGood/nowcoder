#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> solve(int n, int q, vector<int>& a, vector<int>& p) {
        sort(a.begin(), a.end());
        int maxsamebucket = 1, samebucket = 1;
        for(int i = 1; i < n; i++){
            if(a[i] == a[i - 1]){
                samebucket++;
            }
            else{
                maxsamebucket = max(maxsamebucket, samebucket);
                samebucket = 1;
            }
        }
        maxsamebucket = max(maxsamebucket, samebucket);

        vector<int> ret(q, 0);
        for(int i = 0; i < q; i++){
            if(p[i] > maxsamebucket){
                int sum = 0;
                for(int j = 0; j < p[i]; j++) sum += a[j];
                int mintime = a[p[i] - 1] * p[i] - sum, minindex = p[i] - 1;
                for(int j = p[i]; j < n; j++){
                    sum = sum - a[j - p[i]] + a[j];
                    if(mintime > a[j] * p[i] - sum){
                        mintime = a[j] * p[i] - sum;
                        minindex = j;
                    }
                }
                ret[i] = mintime;
                for(int j = minindex - p[i] + 1; j <= minindex; j++)
                    a[j] = a[minindex];
                maxsamebucket = p[i];
            }
        }
        return ret;
    }
};