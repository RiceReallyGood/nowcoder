class Solution {
public:
    int LastRemaining_Solution(int n, int m)
    {
        if(n < 1 || m  < 1) return -1;
        int shift = 0;
        for(int len = 2; len <= n; len++)
            shift = (m + shift) % len;
        return shift;
    }
};