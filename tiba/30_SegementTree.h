#include <vector>
using namespace std;

class Solution {
public:
    vector<int> wwork(int T, int* a, int aLen) {
        vector<int> ret(T);
        int nums, ans;
        for(int i = 0; i < T; i++){
            nums = a[i], ans = 1;
            while(nums > 1){
                if((nums & 1) && ispowof2(nums / 2)){
                    nums = nums / 2 + 1;
                    ans = 2 * ans;
                }
                else{
                    nums = nums / 2;
                    ans = 2 * ans + 1;
                }
            }
            ret[i] = ans;
        }
        return ret;
    }

private:
    bool ispowof2(int n){
        while(n % 2 == 0)
            n /= 2;
        return n == 1;
    }
};