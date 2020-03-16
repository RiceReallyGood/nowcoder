#include <string>
using namespace std;

class Solution {
public:
    string ReverseSentence(string str) {
        if(str.empty()) return str;
        int len = str.length();
        reverse(str, 0, len - 1);
        for(int i = 0; i < len; i++){
            if(str[i] != ' '){
                int j = i + 1;
                while(j < len && str[j] != ' ') j++;
                reverse(str, i, j - 1);
                i = j;
            }
        }
        return str;
    }

private:
    void reverse(string& str, int l, int r){
        while(l < r){
            swap(str[l], str[r]);
            l++, r--;
        }
    }
};