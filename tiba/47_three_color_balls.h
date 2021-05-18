#include <algorithm>
using namespace std;

class Solution {
public:
    int solve(int a, int b, int c) {
        int res = min(a , min(b, c));
        a -= res, b-= res, c -= res;
        if(a == 0) res += min(b / 3, c / 2);
        else if(b == 0) res += min(c / 3, a / 2);
        else res += min(a / 3, b / 2);
        return res;
    }
};