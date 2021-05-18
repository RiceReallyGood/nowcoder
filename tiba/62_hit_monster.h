#include <vector>
using namespace std;


class Solution {
public:
    /**
     * 请你通过solve函数输出最后的答案
     * @param n int整型 n个怪兽
     * @param A int整型vector A数组代表每个怪兽的血量
     * @return int整型
     */
    int slove(int n, vector<int>& A) {
        if(A.size() < 3 || A.size() % 2 == 0) return -1;
        int count = 0;
        for(int r = A.size() - 1; r >= 2; r -= 2){
            int c = r - 1, l = r / 2 - 1;
            int del = max(A[c], A[r]);
            A[c] = A[r] = 0;
            A[l] = max(0, A[l] -del);
            count += del;
        }
        count += A[0];
        return count;
    }
};