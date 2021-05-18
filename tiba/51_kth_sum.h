#include <vector>
using namespace std;

class Solution {
public:
    long long solve(int n, int k, vector<int>& a) {
        long long sumk1 = 0, sumk = 0;
        for(int i = 0; i < k ; i++){
            sumk += a[i];
        }
        sumk1 = sumk - a[0];

        long long res = sumk;
        for(int i = k; i < n; i++){
            sumk = max(sumk, sumk1) + a[i];
            sumk1 = sumk1 + a[i] - a[i - k + 1];
            res = max(res, sumk);
        }
        return res;
    }
};