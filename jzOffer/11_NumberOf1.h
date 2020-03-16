#include <climits>

class Solution {
public:
    int NumberOf1(int n) {
        if(n == INT_MIN) return 1;
        int count = 0;
        while(n){
            count++;
            n = n & (n - 1);
        }
        return count;
    }
};