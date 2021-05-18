#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string WordsMerge(vector<string>& Words) {
        string res;
        for(int i = 0; i < Words.size(); i++){
            int index = 0;
            while(!res.empty() && index < Words[i].length()){
                if(res.back() != Words[i][index])
                    break;
                
                res.pop_back();
                index++;
            }
            res += Words[i].substr(index);
        }
        return res;
    }
};