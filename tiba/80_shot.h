#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    long long solve(int n, vector<int>& a) {
        stack<int> s;
        long long res = 0;
        for(int i = 0; i < n; i++){
            while(!s.empty() && a[i] >= a[s.top()]){
                s.pop();
            }
            if(!s.empty()) res += s.top() + 1;
            s.push(i);
        }
        return res;
    }
};