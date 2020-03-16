#include <vector>
using namespace std;

class Solution {
public:
    int InversePairs(vector<int> data) {
        if(data.empty()) return 0;
        int N = data.size();
        vector<int> temp(N);
        return CountInverseCountAndSort(data, 0, N - 1, temp);
    }

private:
    long CountInverseCountAndSort(vector<int>& data, int l, int r, vector<int>& temp){
        if(l == r) return 0;
        int c = l + (r - l) / 2;
        long leftinv = CountInverseCountAndSort(data, l, c, temp);
        long rightinv = CountInverseCountAndSort(data, c + 1, r, temp);
        long leftrightinv = 0;
        int i = l, j = c + 1, index = l;
        while(i <= c && j <= r){
            if(data[i] <= data[j]){
                temp[index++] = data[i++];
            }
            else{
                temp[index++] = data[j++];
                leftrightinv = (leftrightinv + c - i + 1) % 1000000007;
            }
        }
        while(i <= c)
            temp[index++] = data[i++];
        while(j <= r)
            temp[index++] = data[j++];
        for(int k = l; k <= r; k++)
            data[k] = temp[k];
        return (leftinv + rightinv + leftrightinv) % 1000000007;
    }
};