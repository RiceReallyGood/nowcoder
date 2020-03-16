#include <vector>
using namespace std;

class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        if(array.empty() || array[0].empty()) return false;
        int m = array.size(), n = array[0].size();
        for(int row = 0, col = n - 1; row < m && col >= 0;){
            if(array[row][col] == target) return true;
            if(array[row][col] < target) row++;
            else col--;
        }
        return false;
    }
};