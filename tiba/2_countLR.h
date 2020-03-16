#include <vector>
using namespace std;

class Solution {
public:
    int countLR(vector<int>& a, vector<int>& b) {
        int N = a.size();
        vector<int> sum(N + 1);
        sum[0] = 0;
        for(int i = 0; i < N; i++)
            sum[i + 1] = sum[i] + a[i];
        int count = 0;
        for(int i = 0; i < N; i++){
            for(int j = i; j < N; j++){
                if(sum[j + 1] - sum[i] == b[i] + b[j])
                    count++;
            }
        }
        return count;
    }
};