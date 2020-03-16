#include <cstring>
#include <vector>
using namespace std;

class Solution {
public:
    bool match(char* str, char* pattern){
        int slen = strlen(str);
        int plen = strlen(pattern);
        if(!validpattern(pattern, plen)) return false;
        std::vector<std::vector<bool>> dp(slen + 1, std::vector<bool>(plen + 1, false));
        dp[0][0] = true;
        for(int j = 1; j <= plen; j++)
            dp[0][j] = (pattern[j - 1] == '*') && dp[0][j - 2];
        for(int i = 1; i <= slen; i++){
            for(int j = 1; j <= plen; j++){
                if(pattern[j - 1] == '.') dp[i][j] = dp[i - 1][j - 1];
                else if(pattern[j - 1] == '*'){
                    dp[i][j] = dp[i][j - 2];
                    if(!dp[i][j] &&(pattern[j - 2] == '.' || pattern[j - 2] == str[i - 1]))
                        dp[i][j] = dp[i - 1][j];
                }
                else
                    dp[i][j] = (pattern[j - 1] == str[i - 1]) && dp[i - 1][j - 1];
            }
        }
        return dp[slen][plen];
    }

private:
    bool validpattern(char* pattern, int plen){
        if(plen == 0) return true;
        if(pattern[0] == '*') return false;
        for(int i = 1; i < plen; i++)
            if(pattern[i] == '*' && pattern[i - 1] == '*') return false;
        return true;
    }
};