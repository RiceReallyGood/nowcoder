#include <vector>
using namespace std;

class Solution {
public:
    int solve(int n, int k, vector<int>& a) {
        int sum = 0;
        for(int num : a) sum += num;
        int l = 0, r = sum + 1;
        while(l < r){
            int c = l + (r - l) / 2;
            if(check(a, c, k))
                l = c + 1;
            else
                r = c;
        }
        return l - 1;
    }

private:
    bool check(vector<int>& a, int x, int k){
        int sum = 0, count = 0;
        for(int i = 0; i < a.size(); i++){
            sum += a[i];
            if(sum >= x){
                if(++count == k) return true;
                sum = 0;
            }
        }
        return false;
    }
};