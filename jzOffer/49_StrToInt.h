#include <string>
#include <climits>
using namespace std;

class Solution {
public:
    int StrToInt(string str) {
        if(str.empty()) return 0;
        if(str == "-2147483648") return INT_MIN;
        int start = (str[0] == '+') || (str[0] == '-') ? 1 : 0;
        int ret = 0;
        for(int i = start ; i < str.length(); i++){
            if(str[i] < '0' || str[i] > '9') return 0;
            ret *= 10;
            if(str[i] - '0' > INT_MAX - ret) return 0;
            ret += str[i] - '0';
        }
        return str[0] == '-' ? -ret : ret;
    }
};