#include <vector>
using namespace std;

struct Point {
	int x;
	int y;
};

class Solution {
public:
    int Travel(int N, int V, int* A, int ALen, vector<Point>& List) {
        vector<int> dp(1 << N, -1);
        vector<bool> visited(N, false);
        vector<int> prerequestcount(N);
        vector<vector<int>> latterCities(N);
        for(int i = 0; i < List.size(); i++){
            prerequestcount[List[i].y - 1]++;
            latterCities[List[i].x - 1].push_back(List[i].y - 1);
        }
        return dfs(N, V, A, 0, dp, prerequestcount, latterCities);
    }

private:
    int dfs(int N, int V, int *A, int state, vector<int>& dp,
                    vector<int>& prerequestcount, vector<vector<int>>& latterCities){
        if(dp[state] != -1) return dp[state];
        int count = 0;
        for(int i = 0; i < N; i++){
            if(prerequestcount[i] == 0 && A[i] <= V && (state & (1 << i)) == 0){
                for(int latter : latterCities[i]) prerequestcount[latter]--;
                count = max(count, 1 + dfs(N, V - A[i], A, state ^ (1 << i), dp, prerequestcount, latterCities));
                for(int latter : latterCities[i]) prerequestcount[latter]++;
            }
        }
        return dp[state] = count;
    }
};