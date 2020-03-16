#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    int NumberOf1Between1AndN_Solution(int n)
    {
        if(n < 1) return 0;
        vector<int> digits;
        int num = n;
        while(num){
            digits.push_back(num % 10);
            num /= 10;
        }
        int len = digits.size();
        vector<int> pow10(len);
        pow10[0] = 1;
        for(int i = 1; i < len; i++)
            pow10[i] = 10 * pow10[i - 1];
        vector<int> onescount(len);
        onescount[1] = 1;
        for(int i = 2; i < len; i++)
            onescount[i] = onescount[i - 1] * 10 + pow10[i - 1];
        int count = 0;
        for(int i = len - 1; i >= 0; i--){
            count += digits[i] * onescount[i];
            if(digits[i] > 1) count += pow10[i];
            if(digits[i] == 1) count += n % pow10[i] + 1;
        }
        return count;
    }
};