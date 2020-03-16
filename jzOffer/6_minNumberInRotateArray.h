#include <vector>
using namespace std;

class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        if(rotateArray.empty()) return 0;
        int l = 0, r= rotateArray.size() - 1;
        while(l < r){
            if(rotateArray[l] == rotateArray[r]){
                l++, r--;
            }
            else if(rotateArray[l] < rotateArray[r]){
                return rotateArray[l];
            }
            else{
                int c = l + (r - l) / 2;
                if(rotateArray[c] >= rotateArray[l])
                    l = c + 1;
                else
                    r = c;
            }
        }
        return rotateArray[l];
    }
};

class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        if(rotateArray.empty()) return 0;
        int l = 0, r= rotateArray.size() - 1;
        while(l < r){
            if(rotateArray[l] < rotateArray[r]) return rotateArray[l];
            int c = l + (r - l) / 2;
            if(rotateArray[c] > rotateArray[r]){
                l = c + 1;
            }
            else if(rotateArray[c] < rotateArray[l]){
                r = c;
            }
            else{
                l++, r--;
            }
        }
        return rotateArray[l];
    }
};