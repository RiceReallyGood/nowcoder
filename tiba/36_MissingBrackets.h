#include <string>
using namespace std;

class Solution {
public:
    string MissingBrackets(string brackets) {
        int len = brackets.size();
        if(len & 1) return "Impossible";
        int left = len / 2, right = len / 2;
        for(int i = 0; i < len; i++){
            if(brackets[i] == '(') left--;
            else if(brackets[i] == ')') right--;
        }
        if(left < 0 || right < 0) return "Impossible";
        int lcount = 0, rcount = 0;
        for(int i = 0; i < len; i++){
            if(brackets[i] == '?'){
                if(left > 0){
                    brackets[i] = '(';
                    left--;
                }
                else
                    brackets[i] = ')';
            }
        }

        left = 0, right = 0;
        for(int i = 0; i < len; i++){
            if(brackets[i] == '(') left++;
            else{
                right++;
                if(left < right) return "Impossible";
            }
        }
        return brackets;
    }
};