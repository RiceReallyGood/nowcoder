#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        if(k <= 0) return vector<int>();
        if(input.size() < k) return input;
        priority_queue<int, vector<int>, std::less<int>> pq;
        for(int i = 0; i < k; i++)
            pq.push(input[i]);
        
        for(int i = k; i < input.size(); i++){
            if(input[i] < pq.top()){
                pq.pop();
                pq.push(input[i]);
            }
        }
        vector<int> ret(k);
        for(int i = k - 1; i >= 0; i--){
            ret[i] = pq.top();
            pq.pop();
        }
        return ret;
    }
};