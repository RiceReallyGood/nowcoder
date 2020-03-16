#include <vector>
using namespace std;

class Solution {
public:
    vector<int> multiply(const vector<int>& A) {
        if(A.empty()) return A;
        int N = A.size();
        vector<int> ret(N);
        ret[0] = 1;
        for(int i = 1; i < N; i++)
            ret[i] = ret[i - 1] * A[i - 1];
        long rl = 1;
        for(int i = N - 1; i >= 0; i--){
            ret[i] *= rl;
            rl *= A[i];
        }
        return ret;
    }
};