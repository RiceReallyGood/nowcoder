#include <vector>
using namespace std;

class Solution {
public:
    void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
        int XOR = 0;
        for(int i = 0; i < data.size(); i++)
            XOR ^= data[i];
        int mask = 1;
        while((XOR & mask) == 0)
            mask <<= 1;
        *num1 = 0;
        *num2 = 0;
        for(int i = 0; i < data.size(); i++){
            if((data[i] & mask) == 0) (*num1) ^= data[i];
            else (*num2) ^= data[i];
        }
    }
};