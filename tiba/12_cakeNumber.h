class Solution {
public:
    int cakeNumber(int n) {
        int count = 1;
        for(int i = 1; i < n; i++){
            if(count & 1) count = (count + 1) / 2 * 3;
            else count = count / 2 * 3 + 1;
        }
        return count;
    }
};