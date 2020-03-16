#include <vector>
using namespace std;

class Solution {
public:
    long long MinimumDistance(int n, int* x, int xLen, int* y, int yLen, int* w, int wLen) {
        int L = 0;
        for(int i = 0; i < xLen; i++){
            if(x[i] > L) L = x[i];
            if(y[i] > L) L = y[i];
        }
        vector<long> WeightInLine(L);
 
        long totalWight = 0;
        for(int i = 0; i < xLen; i++){
            WeightInLine[x[i] - 1] += w[i];
            totalWight += w[i];
        }
        long WeightInLeft = 0;
        int xpos = -1;
        for(int i = 0; i < L; i++){
            WeightInLeft += WeightInLine[i];
            if(WeightInLeft >= totalWight - WeightInLeft){
                xpos = i;
                break;
            }
        }
        long xdist = 0;
        for(int i = 0; i < xpos; i++) xdist += WeightInLine[i] * (xpos - i);
        for(int i = xpos + 1; i < L; i++) xdist += WeightInLine[i] * (i -xpos);
 
        for(int i = 0; i < L; i++) WeightInLine[i] = 0;
 
        for(int i = 0; i < yLen; i++) WeightInLine[y[i] - 1] += w[i];
        int ypos = -1;
        WeightInLeft = 0;
        for(int i = 0; i < L; i++){
            WeightInLeft += WeightInLine[i];
            if(WeightInLeft >= totalWight - WeightInLeft){
                ypos = i;
                break;
            }
        }
        long ydist = 0;
        for(int i = 0; i < ypos; i++) ydist += WeightInLine[i] * (ypos - i);
        for(int i = ypos + 1; i < L; i++) ydist += WeightInLine[i] * (i -ypos);
        return xdist + ydist;
    }
};

class Solution {
public:
    long long MinimumDistance(int n, int* x, int xLen, int* y, int yLen, int* w, int wLen) {
        int L = 0;
        for(int i = 0; i < xLen; i++){
            if(x[i] > L) L = x[i];
            if(y[i] > L) L = y[i];
        }

        vector<int> Weightx(L), Weighty(L);
        int TotalWeight = 0;
        for(int i = 0; i < n; i++){
            Weightx[x[i] - 1] += w[i];
            Weighty[y[i] - 1] += w[i];
            TotalWeight += w[i];
        }
        return mindist(Weightx, TotalWeight) + mindist(Weighty, TotalWeight);
    }

private:
    long mindist(vector<int>& Weight, int TotalWeight){
        int L = Weight.size();
        int LeftWeight = 0;
        long Leftdist = 0;
        int pos = -1;
        for(int i = 0; i < L; i++){
            Leftdist += LeftWeight;
            LeftWeight += Weight[i];
            if(LeftWeight >= TotalWeight - LeftWeight){
                pos = i;
                break;
            }          
        }

        int RightWeight = 0;
        long Rightdist = 0;
        for(int i = L - 1; i >= pos; i--){
            Rightdist += RightWeight;
            RightWeight += Weight[i];
        }
        return Leftdist + Rightdist;
    }
};