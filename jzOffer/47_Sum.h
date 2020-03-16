class Solution {
public:
    int Sum_Solution(int n) {
        if(n && (n += Sum_Solution(n - 1)));
        return n;
    }
};