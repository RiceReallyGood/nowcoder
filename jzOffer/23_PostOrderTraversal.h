#include <vector>
using namespace std;

class Solution {
public:
    bool VerifySquenceOfBST(vector<int> sequence) {
        if(sequence.empty()) return false;
        return IsPostOrder(sequence, 0, sequence.size() - 1);
    }

private:
    bool IsPostOrder(vector<int>& sequence, int l, int r){
        if(l >= r) return true;
        int index = l;
        while(sequence[index] < sequence[r]) index++;
        int righttree = index;
        while(sequence[index] > sequence[r]) index++;
        if(index != r) return false;
        return IsPostOrder(sequence, l, righttree - 1) && IsPostOrder(sequence, righttree, r - 1);
    }
};