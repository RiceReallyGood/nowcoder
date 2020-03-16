#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
        if(array.empty()) return 0;
        int maxsum = INT_MIN, prevsum = 0;
        for(int i = 0; i < array.size(); i++){
            if(prevsum <= 0){
                prevsum = array[i];
                maxsum = max(maxsum, prevsum);
            }
            else{
                prevsum += array[i];
                maxsum = max(maxsum, prevsum);
            }
        }
        return maxsum;
    }
};