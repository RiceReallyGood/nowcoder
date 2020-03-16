#include <queue>
using namespace std;

class Solution {
public:
    void Insert(int num){
        if(pq1.empty() || num <= pq1.top()){
            pq1.push(num);
            if(pq1.size() == pq2.size() + 2){
                pq2.push(pq1.top());
                pq1.pop();
            }
        }
        else{
            pq2.push(num);
            if(pq2.size() > pq1.size()){
                pq1.push(pq2.top());
                pq2.pop();
            }
        }
    }

    double GetMedian(){ 
        if(pq1.size() == pq2.size())
            return (pq1.top() + pq2.top()) / 2.;
        return pq1.top();
    }

private:
    priority_queue<int, vector<int>, less<int>> pq1;
    priority_queue<int, vector<int>, greater<int>> pq2;
};