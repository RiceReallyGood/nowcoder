#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    long long solve(int n, int d, vector<int>& a, vector<int>& b, vector<int>& c) {
        ll target = ll(n) * ll(d);

        for(int i = 0; i < n; i++)
            target -= b[i];
        
        if(target <= 0) return 0;

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int, int>>> pq;
        for(int i = 0; i < n; i++){
            pq.push({c[i], a[i] - b[i]});
        }

        ll res = 0;
        while(target > 0){
            pair<int, int> v = pq.top();
            pq.pop();

            if(target > v.second){
                target -= v.second;
                res += v.first * v.second;
            }
            else{
                res += target * v.first;
                target = 0;
            }
        }
        return res;
    }

private:
    using ll = long long;
};