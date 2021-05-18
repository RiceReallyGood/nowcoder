#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <climits>
#include <queue>
using namespace std;

class Solution {
public:
    int work(int n, int* a, int aLen) {
        prime(100);
        return -1;
    }

private:
    vector<bool> prime(int n){
        vector<bool> res(n + 1, true);
        res[0] = false;
        for(int i = 2; i * i < n; i++){
            if(res[i] == true){
                for(int j = i; j * i <= n; j++){
                    res[i * j] = false;
                }
            }
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<int> nums = {2,0,2};
    vector<int> x = {1};
    vector<int> y = {2};
    vector<int> z = {1001, 3357};
    //vector<Point> edge = {{2,5}, {5,3}, {5,4},{5,1}};
    vector<vector<int>> card = {{1,5}, {2,4}};
    vector<int> ret;
    cout << s.work(0, nullptr, 0) << endl;
}