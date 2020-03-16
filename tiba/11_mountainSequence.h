#include <vector>
using namespace std;

class Solution {
public:
    int mountainSequence(vector<int>& numberList) {
        if(numberList.empty()) return 0;
        int N = numberList.size();
        vector<int> increase(N, 1);
        vector<int> decrease(N, 1);
        int ret = 1;
        for(int i = 1; i < N; i++){
            for(int j = i - 1; j >= 0; j--){
                if(numberList[j] == numberList[i]){
                    increase[i] = max(increase[i], increase[j]);
                    decrease[i] = max(decrease[i], decrease[j]);
                    break;
                }

                if(numberList[j] < numberList[i])
                    increase[i] = max(increase[i], increase[j] + 1);
                else
                    decrease[i] = max(decrease[i], max(increase[j], decrease[j]) + 1);
            }
            ret = max(ret, max(decrease[i], increase[i]));
        }
        return ret;
    }
};