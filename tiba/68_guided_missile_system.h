class Solution {
public:
    int solve(int A, int B, int M) {
        if(B % A == 0)
            return M * (1 + B / A) + 1;
        else
            return M * (1 + B / A + 1);
    }
};