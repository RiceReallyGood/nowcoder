#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    /**
     * 
     * @param n int整型 
     * @param a int整型一维数组 
     * @param aLen int a数组长度
     * @param b int整型一维数组 
     * @param bLen int b数组长度
     * @return long长整型
     */
    long long EatingHamburger(int n, int* a, int aLen, int* b, int bLen) {
        vector<Node> v;
        for(int i = 0; i < n; i++){
            v.emplace_back(a[i], b[i]);
        }
        sort(v.begin(), v.end(), 
            [](const Node& n1, const Node& n2){
                return n1.sum > n2.sum;
            }
        );

        int index = 0, eatthisday = v[0].sum;
        long long beef = 0;
        priority_queue<Node, vector<Node>,comp> pq;
        while(eatthisday > 0){
            while(index < v.size() && v[index].sum >= eatthisday){
                pq.push(v[index]);
                index++;
            }
            if(!pq.empty()){
                Node n = pq.top();
                pq.pop();
                if(n.a < eatthisday) beef += eatthisday - n.a;
            }
            eatthisday--;
        }
        return beef;
    }

private:
    class Node{
    public:
        int a, b, sum;
        Node(int a_, int b_) :a(a_), b(b_), sum(a_ + b_) {}
    };

    class comp{
    public:
        bool operator()(const Node& n1, const Node& n2){
            return n1.a < n2.a;
        }
    };
};