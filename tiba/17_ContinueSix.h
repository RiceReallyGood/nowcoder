#include <string>
using namespace std;


class Solution {
public:
    string calculate(int n) {
        string EndWithSix = "0", EndNotSix = "1";
        for(int i = 0; i < n; i++){
            string temp = EndNotSix;
            EndNotSix = Multi9(add(EndWithSix, EndNotSix));//9 * (EndWithSix + EndNotSix);
            EndWithSix = temp;
        }
        return add(EndWithSix, EndNotSix);
    }

private:
    string add(string s1, string s2){
        int len1 = s1.length(), len2 = s2.length();
        for(int i = 0, j = len1 - 1; i < j; i++, j--)
            swap(s1[i], s1[j]);
        for(int i = 0, j = len2 - 1; i < j; i++, j--)
            swap(s2[i], s2[j]);
        
        int carry = 0;
        string ret;
        for(int index = 0; index < len1 || index < len2; index++){
            int a = index >= len1 ? 0 : s1[index] - '0';
            int b = index >= len2 ? 0 : s2[index] - '0';
            ret.push_back((a + b + carry) % 10 + '0');
            carry = (a + b + carry) / 10;
        }
        if(carry > 0) ret.push_back(carry + '0');
        for(int i = 0, j = ret.length() - 1; i < j; i++, j--)
            swap(ret[i], ret[j]);
        return ret;
    }

    string Multi9(string s){
        string ret = "0";
        for(int i = 0, j = s.length() - 1; i < j; i++, j--)
            swap(s[i], s[j]);
        ret += s;

        int carry = 0;
        for(int i = 0; i < s.length(); i++){
            if(ret[i] >= s[i] + carry){
                ret[i] = (ret[i] - s[i] - carry) + '0';
                carry = 0;
            }
            else{
                ret[i] = (ret[i] - s[i] + 10 - carry) + '0';
                carry = 1;
            }
        }
        ret[s.length()] -= carry;
        while(ret.back() == '0') ret.pop_back();
        for(int i = 0, j = ret.size() - 1; i < j; i++, j--)
            swap(ret[i], ret[j]);
        return ret;
    }
};