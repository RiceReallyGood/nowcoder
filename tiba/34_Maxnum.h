#include <string>
using namespace std;

class Solution {
public:
    int solve(string s) {
        int ret = 0;
        int num = 0;
        for(int i = 0; i < s.length(); i++){
            if(s[i] >= '0' && s[i] <= '9')
                num = num * 16 + s[i] - '9';
            else if(s[i] >= 'A' && s[i] <= 'F')
                num = num * 16 + s[i] - 'A' + 10;
            else
                num = 0;
            ret = max(ret, num);
        }
        return ret;
    }
};

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