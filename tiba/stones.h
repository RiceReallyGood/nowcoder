#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int solve(int n, long long m, vector<int>& a) {
        sort(a.begin(), a.end());
        int l = 1, r = a[0];
        while(l <= r){
            int c = l + (r - l) / 2;
            long long sites = 0;
            vector<int>::iterator it = a.begin();
            int target = c;
            while(target <= a.back()){
                it = lower_bound(it, a.end(), target);
                sites += n - (it - a.begin());
                target += c;
            }
            if(sites < m)
                r = c;
            else
                l = c + 1;
        }
        return l - 1;
    }
};

class Solution {
public:
    int solve(int n, long long m, vector<int>& a) {
        int l = 1, r = *min_element(a.begin(), a.end());
        long long count = 0;
        for(int i = 0; i < n; i++)
            count += a[i] / r;
        if(count >= m) return r;
        while(l < r){
            int c = l + (r - l) / 2;
            long long sites = 0;
            int target = c;
            for(int i = 0; i < n; i++)
                sites += a[i] / c;
            if(sites < m)
                r = c;
            else
                l = c + 1;
        }
        return l - 1;
    }
};