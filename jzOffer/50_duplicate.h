#include <algorithm>
using namespace std;

class Solution {
public:
    bool duplicate(int numbers[], int length, int* duplication) {
        for(int i = 0; i < length; i++){
            while(numbers[numbers[i]] != numbers[i]) std::swap(numbers[numbers[i]], numbers[i]);
            if(numbers[i] != i){
                *duplication = numbers[i];
                return true;
            }
        }
        return false;
    }
};