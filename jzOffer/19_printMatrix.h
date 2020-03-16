#include <vector>
using namespace std;

class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
        if(matrix.empty() || matrix[0].empty()) return vector<int>();
        int vertial = matrix.size();
        int horizontal = matrix[0].size();
        int cycle = min(vertial + 1, horizontal + 1);
        int vdir = 1, hdir = 1;
        int x = 0, y = -1;
        vector<int> ret;
        for(int c = 0; c < cycle; c++){
            for(int i = 0; i < horizontal; i++){
                y += hdir;
                ret.push_back(matrix[x][y]);
            }
            hdir = -hdir, vertial--;
            for(int i = 0; i < vertial; i++){
                x += vdir;
                ret.push_back(matrix[x][y]);
            }
            vdir = -vdir, horizontal--;
        }
        return ret;
    }
};