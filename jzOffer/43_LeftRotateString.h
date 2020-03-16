#include <string>
using namespace std;

class Solution {
public:
    string LeftRotateString(string str, int n) {
        if(str.empty()) return str;
        int len = str.length();
        n %= len;
        for(int i = 0, j = len - 1; i < j; i++, j--)
            swap(str[i], str[j]);
        for(int i = 0, j = len - n - 1; i < j; i++, j--)
            swap(str[i], str[j]);
        for(int i = len - n, j = len - 1; i < j; i++, j--)
            swap(str[i], str[j]);
        return str;
    }
};