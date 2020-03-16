#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    int solve(string s) {
        int ret = 0;
        int num = 0;
        for(int i = 0; i < s.length(); i++){
            if(s[i] >= '0' && s[i] <= '9')
                num = (num << 4) | (s[i] - '0');
            else if(s[i] >= 'A' && s[i] <= 'F')
                num = (num << 4) + (s[i] - 'A' + 10);
            else{
                ret = max(ret, num);
                num = 0;
            }
        }
        ret = max(ret, num);
        return ret;
    }
};

int main(){
    Solution s;
    vector<int> nums = {2,3,3,4,4};
    vector<int> x = {2,3,5,4,5,5};
    vector<int> y = {5,2,1,6,7,4};
    vector<int> z = {15,6,14,4,1,6};
    vector<int> ret;
    cout << s.solve("012345BZ16") << endl;
}