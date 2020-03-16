#include <vector>
using namespace std;

class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        int candidate = 0, count = 0;
        for(int num : numbers){
            if(count == 0){
                candidate = num;
                count = 1;
            }
            else if(num == candidate) count++;
            else count--;
        }
        count = 0;
        for(int num : numbers)
            if(num == candidate) count++;
        if(count > numbers.size() / 2) return candidate;
        return 0;
    }
};