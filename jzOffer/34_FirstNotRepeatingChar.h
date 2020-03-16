#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int FirstNotRepeatingChar(string str) {
        int len = str.length();
        vector<int> count(128, 0);
        for(int i = 0; i < len ;i++)
            count[str[i]]++;
        for(int i = 0; i < len ;i++)
            if(count[str[i]] == 1)
                return i;
        return -1;
    }
};