#include <vector>
using namespace std;

class Solution {
public:
    int solve(int n, vector<int>& a) {
        vector<int> count(n);
        if(n & 1){
            for(int i = 0; i < n; i++){
                if(a[i] % 2 == 1 || a[i] >= n)
                    return 0;
                if(++count[a[i]] > 2)
                    return 0;
            }
            if(count[0] != 1) return 0;
        }
        else{
            for(int i = 0; i < n; i++){
                if(a[i] % 2 == 0 || a[i] >= n)
                    return 0;
                if(++count[a[i]] > 2)
                    return 0;
            }
        }
        return fastpow_modP(2, n / 2);
    }

private:
    const static long long P = 1e9 + 7;
    int fastpow_modP(long long x, int n){
        if(n == 0) return 1;
        if(n & 1) return x * fastpow_modP(x * x % P, n / 2) % P;
        else return fastpow_modP(x * x % P, n / 2);
    }
};