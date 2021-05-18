#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    int solve(int n, vector<int>& a) {
        stack<int> s;
        int res= 0;
        for(int i = 0; i < n; i++){
            while(!s.empty() && s.top() < a[i]){
                res = max(res, s.top() ^ a[i]);
                s.pop();
            }
            if(!s.empty())
                res = max(res, s.top() ^ a[i]);
            s.push(a[i]);
        }
        return res;
    }
};