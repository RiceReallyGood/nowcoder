#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        int index = 0;
        stack<int> s;
        for(int i = 0; i < pushV.size(); i++){
            s.push(pushV[i]);
            while(!s.empty() && s.top() == popV[index]){
                s.pop();
                index++;
            }
        }
        return s.empty();
    }
};