#include <vector>
using namespace std;

class Solution {
public:
    bool IsContinuous(vector<int> numbers) {
        int sz = numbers.size();
        if(sz < 5 || sz > 13) return false;
        vector<int> cards(14, 0);
        for(int num : numbers) cards[num]++;
        int s = 1, e = 13;
        while(cards[s] == 0) s++;
        while(cards[e] == 0) e--;
        for(int i = s; i <= e; i++)
            if(cards[i] > 1) return false;
        
        return e - s + 1 <= sz;
    }
};