#include <vector>
using namespace std;

class Solution {
public:
    int Holy(int n, int m, vector<int>& x) {
        long long maxvol = 0;
        for(int i = 0; i < m; i++){
            n -= x[i];
            if(n <= 0) return 0;
            maxvol = max<long long>(maxvol, x[i]);
        }
        int count = 0;
        while(n > 0){
            n -= maxvol;
            count++;
            maxvol *= 2;
        }
        return count;
    }
};