#include <vector>
using namespace std;

class Solution {
public:
    int GetNumberOfK(vector<int> data ,int k) {
        int N = data.size();
        int l = 0, r = N;
        //upperbound
        while(l < r){
            int c = l + (r - l) / 2;
            if(data[c] <= k)
                l = c + 1;
            else
                r = c;
        }
        int uppbound = l;
        //lowerbound
        l = 0, r = N;
        while(l < r){
            int c = l + (r - l) / 2;
            if(data[c] < k)
                l = c + 1;
            else
                r = c;
        }
        int lowerbound = l;
        return uppbound - lowerbound;
    }
};