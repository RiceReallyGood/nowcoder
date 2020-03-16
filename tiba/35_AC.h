#include <string>
using namespace std;

class Solution {
public:
    int Solve(int k, string s) {
        if(k >= s.length()) return s.length();
        int Acount = 0, Ccount = 0;
        int i = 0, j = 0;
        int maxlen = 0; 
        while(j < s.length()){
            while(Acount > k && Ccount > k){
                if(s[i] == 'A') Acount--;
                else Ccount--;
                i++;
            }
            while(j < s.length() && (Acount <= k || Ccount <= k)){
                if(s[j] == 'A') Acount++;
                else Ccount++;
                j++;
            }
            if(Acount <= k || Ccount <= k)
                maxlen = max(maxlen, j - i);
            else
                maxlen = max(maxlen, j - i - 1);
        }
        return maxlen;
    }
};