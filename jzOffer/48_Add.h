class Solution {
public:
    int Add(int num1, int num2)
    {
        int ret = 0;
        int carry = 0;
        for(int i = 0; i < 32; i++){
            int a = (num1 >> i) & 1;
            int b = (num2 >> i) & 1;
            ret |= (a ^ b ^ carry) << i;
            if(carry) carry = a | b;
            else carry = a & b;
        }
        return ret;
    }
};