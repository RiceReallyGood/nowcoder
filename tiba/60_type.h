#include <string>
using namespace std;

class Solution {
public:
    string Typing(string s) {
        string res;
        for(int i = 0; i < s.length(); i++){
            if(s[i] != '<')
                res.push_back(s[i]);
            else if(!res.empty())
                res.pop_back();
        }
        return res;
    }
};