#include <vector>
using namespace std;

class Solution {
public:
    int Fibonacci(int n) {
        static vector<int> fib = {0, 1};
        while(fib.size() < n + 1){
            int sz = fib.size();
            fib.push_back(fib[sz - 2] + fib[sz - 1]);
        }
        return fib[n];
    }
};