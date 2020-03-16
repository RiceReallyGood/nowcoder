#include <vector>
using namespace std;

class Solution {
public:
    int GetUglyNumber_Solution(int index) {
        vector<int> dp = {1};
        vector<int> p(3, 0);
        vector<int> prod = {2, 3, 5};
        vector<int> next = {2, 3, 5};
        while(dp.size() < index){
            int minindex = 0;
            if(next[1] < next[minindex]) minindex = 1;
            if(next[2] < next[minindex]) minindex = 2;
            if(next[minindex] > dp.back()) dp.push_back(next[minindex]);
            p[minindex]++;
            next[minindex] = dp[p[minindex]] * prod[minindex];
        }
        return dp[index - 1];
    }
};