#include "class.h"
#include <iostream>

int main(){
    Solution s;
    vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};//{{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
    vector<int> nums = {5,2,3,4,1,6,7,0,8};
    for(int num : nums){
        s.Insert(num);
        cout << s.GetMedian() << endl;
    }
}