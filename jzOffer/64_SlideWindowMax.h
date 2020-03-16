#include <vector>
#include <deque>
using namespace std;

class Solution {
public:
    vector<int> maxInWindows(const vector<int>& num, unsigned int size){
        if(num.size() < size || size == 0) return vector<int>();
        deque<int> dq;
        for(int i = 0; i < size; i++){
            while(!dq.empty() && dq.back() < num[i]) dq.pop_back();
            dq.push_back(num[i]); 
        }
        vector<int> ret;
        ret.push_back(dq.front());
        for(int i = size; i < num.size(); i++){
            if(dq.front() == num[i - size]) dq.pop_front();
            while(!dq.empty() && dq.back() < num[i]) dq.pop_back();
            dq.push_back(num[i]);
            ret.push_back(dq.front());
        }
        return ret;
    }
};