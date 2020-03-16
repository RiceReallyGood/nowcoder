#include <algorithm>

class Solution {
public:
    int rectCover(int number) {
        if(number < 2) return number;
        int towbefore = 1, onebefore = 1;
        for(int i = 2; i <= number; i++){
            int curr = onebefore + towbefore;
            towbefore = onebefore;
            onebefore = curr;
        }
        return onebefore;
    }
};