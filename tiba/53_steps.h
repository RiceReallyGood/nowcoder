#include <vector>
using namespace std;

class Solution {
public:
    int solve(int n, int m, vector<int>& a) {
        static int mod = 1e9 + 7;
        if(a.back() == n) return 0;
        int odd = 0, even = 1;
        int index = 0;
        for(int i = 1; i < n; i++){
            if(i == a[index]){
                index++;
                continue;
            }

            if(i & 1){
                odd = (odd + even) % mod;
            }
            else{
                even = (even + odd) % mod;
            }
        }
        return (n % 2 == 1) ? even : odd;
    }
};