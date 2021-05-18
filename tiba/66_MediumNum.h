#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int solve(int n, int k, vector<int>& a) {
        int l = *min_element(a.begin(), a.end());
        int r = *max_element(a.begin(), a.end()) + 1;
        while(l < r){
            int c = l + (r - l) / 2;
            if(check(a, k, c))
                l = c + 1;
            else
                r = c;
        }
        return l - 1;
    }

private:
    bool check(const vector<int>& a, int k, int x){
        int counttotal = 0, countbeforek = 0, mincountbeforek = 0;
        for(int i = 0; i < k; i++){
            if(a[i] >= x)
                counttotal++;
            else
                counttotal--;
        }
        if(counttotal >= 0) return true;

        for(int i = k; i < a.size(); i++){
            if(a[i - k] >= x)
                countbeforek++;
            else
                countbeforek--;
            
            mincountbeforek = min(mincountbeforek, countbeforek);

            if(a[i] >= x)
                counttotal++;
            else
                counttotal--;
            
            if(counttotal - mincountbeforek >= 0)
                return true;
        }
        return false;
    }
};