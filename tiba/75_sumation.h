#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    long long solve(int n, int c, vector<int>& a) {
        priority_queue<int, vector<int>, greater<int>> pq(a.begin(), a.end());

        ll res = 0;
        while(pq.size() > 1){
            int sum = 0;
            sum += pq.top();
            pq.pop();
            sum += pq.top();
            pq.pop();
            res += sum;
            pq.push(sum);
        }
        return res * c;
    }

private:
    using ll = long long;
};