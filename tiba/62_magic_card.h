#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    int solve(int n, int k, vector<vector<int> >& card) {
        auto comp = [](const vector<int>& v1, const vector<int>& v2){
            return v1[1] < v2[1];
        };
        sort(card.begin(), card.end(), comp);

        vector<int> count(k, 0);
        int size = 0;

        int res = INT_MAX;
        for(int i = 0, j = 0; j < n; j++){
            if(count[card[j][0]] == 0) size++;
            count[card[j][0]]++;
            
            while(size == k){
                res = min(res, card[j][1] - card[i][1]);
                count[card[i][0]]--;
                if(count[card[i][0]] == 0) size--;
                i++;
            }
        }
        return res == INT_MAX ? -1 : res;
    }
};