#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<long> solve(vector<int>& a, vector<int>& b) {
        long long prev = 0, curr;
        priority_queue<int,vector<int>,greater<int>> pq(a.begin(), a.end());
        vector<long> res(b.size());
        for(int i = 0; i < b.size(); i++){
            curr = prev + b[i];
            long long count = 0;
            while(!pq.empty() && pq.top() <= curr){
                count += pq.top() - prev;
                pq.pop();
            }
            res[i] = count + b[i] * pq.size();
            prev = curr;
        }
        return res;
    }
};