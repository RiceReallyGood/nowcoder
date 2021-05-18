#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<long> MaxArea(int n, vector<int>& Stick) {
        int maxlen = *max_element(Stick.begin(), Stick.end());
        vector<int> count(maxlen + 1);
        for(int i = 0; i < n; i++)
            count[Stick[i]]++;
        
        vector<long> res(2);
        for(int i = 1; i <= maxlen; i++){
            if(count[i] >= 3){
                long square = long(i) * long(i);
                if(count[i] % 4 == 3)
                    res[0] += square;
                
                res[1] += (count[i] / 4) * square;
            }
        }
        return res;
    }
};