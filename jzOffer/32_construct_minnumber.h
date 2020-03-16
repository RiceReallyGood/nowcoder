#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    string PrintMinNumber(vector<int> numbers) {
        int N = numbers.size();
        vector<string> nums(N);
        for(int i = 0; i < N; i++)
            nums[i] = to_string(numbers[i]);
        
        auto comp = [](const string& s1, const string& s2){
            return s1 + s2 < s2 + s1;
        };
        sort(nums.begin(), nums.end(), comp);
        string ret;
        for(int i = 0; i < N; i++)
            ret += nums[i];
        return ret;
    }
};