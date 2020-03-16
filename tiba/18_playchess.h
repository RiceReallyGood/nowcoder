#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string playchess(vector<string>& chessboard) {
        int m = chessboard.size(), n = chessboard[0].size();
        int jx = -1, jy = -1;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(chessboard[i][j] == 'j'){
                    jx = i, jy = j;
                    break;
                }
            }
        }

        int chesscount = 0;
        for(int i = jx - 1; i >= 0 && chesscount < 2; i--){
            if(chessboard[i][jy] == '.') continue;
            if((chessboard[i][jy] == 'B' || chessboard[i][jy] == 'J') && i == jx - 1)
                return "Happy";
            
            if(chessboard[i][jy] == 'C' && chesscount == 0) return "Happy";
            if(chessboard[i][jy] == 'P' && chesscount == 1) return "Happy";

            chesscount++;
        }

        chesscount = 0;
        for(int i = jx + 1; i < m && chesscount < 2; i++){
            if(chessboard[i][jy] == '.') continue;
            if((chessboard[i][jy] == 'B' || chessboard[i][jy] == 'J') && i == jx + 1)
                return "Happy";
            
            if(chessboard[i][jy] == 'C' && chesscount == 0) return "Happy";
            if(chessboard[i][jy] == 'P' && chesscount == 1) return "Happy";

            chesscount++;
        }

        chesscount = 0;
        for(int j = jy - 1; j >= 0 && chesscount < 2; j--){
            if(chessboard[jx][j] == '.') continue;
            if((chessboard[jx][j] == 'B' || chessboard[jx][j] == 'J') && j == jy - 1)
                return "Happy";
            
            if(chessboard[jx][j] == 'C' && chesscount == 0) return "Happy";
            if(chessboard[jx][j] == 'P' && chesscount == 1) return "Happy";

            chesscount++;
        }

        chesscount = 0;
        for(int j = jy + 1; j < n && chesscount < 2; j++){
            if(chessboard[jx][j] == '.') continue;
            if((chessboard[jx][j] == 'B' || chessboard[jx][j] == 'J') && j == jy + 1)
                return "Happy";
            
            if(chessboard[jx][j] == 'C' && chesscount == 0) return "Happy";
            if(chessboard[jx][j] == 'P' && chesscount == 1) return "Happy";

            chesscount++;
        }
        return "Sad";
    }
};