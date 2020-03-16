#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int GetMinDistance(string S1, string S2) {
        vector<vector<int>> charmap(26, vector<int>(26, 0));
        int len = S1.length();
        for(int i = 0; i < len; i++)
            charmap[S1[i] - 'a'][S2[i] -'a']++;
        int same = 0, reduction = 0;
        for(int i = 0; i < 26; i++){
            int currreduction = 0;
            for(int j = 0; j < 26; j++){
                if(j == i) continue;
                currreduction = max(currreduction, charmap[i][j]);
            }
            same += charmap[i][i];
            currreduction -= charmap[i][i];
            reduction = max(reduction, currreduction);
        }
        return len - same - reduction;
    }
};