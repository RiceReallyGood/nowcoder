#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    long long minimumValueAfterDispel(vector<int>& nums) { //O(N^2) //incorrect
        int N = nums.size();
        sort(nums.begin(), nums.end());
        vector<long> reduction(N);
        for(int i = 0; i < N; i++) reduction[i] = long(N - i) * nums[i];
        vector<int> temp(N);
        long maxdelete = 0;
        // first deleted num in the list
        for(int i = 0; i < N; i++){
            if(i > 0 && nums[i] == nums[i - 1]) continue;
            int l = 0, r = i, index = 0;
            while(l < i && r < N){
                if(nums[l] <= nums[r] - nums[i])
                    temp[index++] = nums[l++];
                else
                    temp[index++] = nums[r++] - nums[i];
            }
            while(l < i) temp[index++] = nums[l++];
            while(r < N) temp[index++] = nums[r++] - nums[i];
            for(int j = 0; j < N; j++){
                if(j > 0 && temp[j] == temp[j - 1]) continue;
                if(temp[j] >= nums[i]) break;
                maxdelete = max(maxdelete, reduction[i] + long(N - j) * long(temp[j]));
            }
        }
        // first deleted num in the list
        for(int i = 0; i < N; i++){
            int aindex = i + 1;
            if(i > 0 && nums[i] == nums[i - 1]) continue;
            for(int j = i + 1; j < N; j++){
                if(nums[j] == nums[j - 1] ||nums[j] - nums[i] <= nums[i]) continue;
                while(nums[aindex] < nums[j] - nums[i]) aindex++;
                maxdelete = max(maxdelete, reduction[j]
                                         + long(j - aindex) * long(nums[j] - nums[i])
                                         + long(aindex - i) * long(nums[i]));
            }
        }
        long sum = 0;
        for(int i = 0; i < N; i++)
            sum += nums[i];
        return sum - maxdelete;
    }
};