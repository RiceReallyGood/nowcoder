#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    int solve(int N, vector<int>& A) {
        stack<int> s1, s2;
        int res = 0;
        for(int i = N - 1; i >= 0; i--){
            int count = 0;
            while(!s1.empty() && s1.top() < A[i]){
                count = max(count + 1, s2.top());
                s1.pop();
                s2.pop();
            }
            res = max(res, count);
            s1.push(A[i]);
            s2.push(count);
        }
        return res;
    }
};