#include <vector>
#include <queue>
using namespace std;

class Solution{
public:
    Solution() : count(128, 0) {}
    //Insert one char from stringstream
    void Insert(char ch){
        count[ch]++;
        if(count[ch] == 1) q.push(ch);
    }
    //return the first appearence once char in current stringstream
    char FirstAppearingOnce(){
        while(!q.empty() && count[q.front()] > 1) q.pop();
        if(q.empty()) return '#';
        else return q.front();
    }

private:
    vector<int> count;
    queue<char> q;
};