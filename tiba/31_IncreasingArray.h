#include <vector>
using namespace std;

class Solution {
public:
    long long IncreasingArray(vector<int>& array) {
        int target = array[0];
        long totalincreasement = 0;
        int previncreasement = 0, currincreasement = 0;
        for(int i = 0; i < array.size(); i++){
            if(array[i] >= target){
                currincreasement = 0;
                target = array[i] + 1;
            }
            else{
                currincreasement = target - array[i];
                target++;
            }
            if(previncreasement > currincreasement){
                totalincreasement += previncreasement - currincreasement;
            }
            previncreasement = currincreasement;
        }
        totalincreasement += currincreasement;
        return totalincreasement;
    }
};

class Solution {
public:
    long long IncreasingArray(vector<int>& array) {
        long increasement = 0;
        for(int i = 1; i < array.size(); i++){
            if(array[i] <= array[i - 1]) increasement += array[i - 1] - array[i] + 1;
        }
        return increasement;
    }
};