#include <vector>
using namespace std;

class Solution {
public:
    int largestSubTriangle(int a, vector<int>& maps) {
        vector<bool> new_maps(8 * a * a);
        convert(a, maps, new_maps);
        int upper = largestUpperTriangle(a, new_maps);
        for(int i = 0, j = new_maps.size() - 1; i < j; i++, j--)
            swap(new_maps[i], new_maps[j]);
        int lower = largestUpperTriangle(a, new_maps);
        return max(lower, upper);
    }

private:
    void convert(int a, vector<int>& maps, vector<bool>& new_maps){
        int linestart = 0, lineend;
        for(int i = 0; i < a; i++){
            lineend = linestart + 2 * a + 1 + i * 2;
            int index = i * 4 * a;
            for(int j = linestart; j < lineend; j++)
                new_maps[index++] = maps[j] == 1 ? true : false;
            linestart = lineend;
        }

        for(int i = 0; i < a; i++){
            lineend = linestart + 2 * a + 1 + (a - 1 - i) * 2;
            int index = (i + a) * 4 * a + 2 * i + 1;
            for(int j = linestart; j < lineend; j++)
                new_maps[index++] = maps[j] == 1 ? true : false;
            linestart = lineend;
        }
    }

    int largestUpperTriangle(int a, vector<bool>& new_maps){
        vector<int> dp(4 * a);
        int ret = 0;
        for(int i = 0; i < 4 * a; i += 2){
            if(new_maps[i]){
                dp[i] = 1;
                ret = 1;
            }
        }
        for(int i = 1; i < 2 * a; i++){
            vector<int> temp(4 * a, 0);
            int continousTrangles = 0;
            if(new_maps[i * 4 * a]){
                temp[0] = 1;
                continousTrangles = 1;
            }
            for(int j = 2; j < 4 * a; j += 2){
                if(!new_maps[i * 4 * a + j - 1]) continousTrangles = 0;
                if(!new_maps[i * 4 * a + j]){
                    temp[j] = 0;
                    continousTrangles = 0;
                }
                else{
                    continousTrangles++;
                    temp[j] = min(continousTrangles, dp[j - 2] + 1);
                    ret = max(ret, temp[j]);
                }

            }
            swap(dp, temp);
        }
        return ret;
    }
};