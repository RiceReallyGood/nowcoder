#include <vector>
using namespace std;

class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> array,int sum) {
        if(array.empty()) return vector<int>();
        for(int i = 0, j = array.size() - 1; i <= j;){
            int s = array[i] + array[j];
            if(s == sum) return {array[i], array[j]};
            if(s < sum) i++;
            else j--;
        }
        return vector<int>();
    }
};