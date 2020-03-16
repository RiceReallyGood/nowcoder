#include <vector>
#include <queue>
using namespace std;

struct Point {
	int x;
	int y;
};


class Solution {
public:
    int Travel(int N, int V, int* A, int ALen, vector<Point>& list) {
        vector<int> prerequestscount(N);
        vector<vector<int>> lattertargets(N);
        for(int i = 0; i < list.size(); i++){
            prerequestscount[list[i].y - 1]++;
            lattertargets[list[i].x - 1].push_back(list[i].y - 1);
        }
        priority_queue<Node, vector<Node>, comp> pq;
        for(int i = 0; i < N; i++){
            if(prerequestscount[i] == 0){
                pq.push(Node(i, A[i]));
            }
        }
        int count = 0;
        while(!pq.empty() && pq.top().price <= V){
            Node n = pq.top();
            pq.pop();
            V -= n.price;
            count++;
            for(int latter : lattertargets[n.index]){
                if(--prerequestscount[latter] == 0){
                    pq.push(Node(latter, A[latter]));
                }
            }
        }
        return count;
    }

private:
    class Node{
    public:
        Node(int i, int p) : index(i), price(p) {}
        int index ;
        int price;
    };

    class comp{
    public:
        bool operator()(const Node& n1, const Node& n2){
            return n1.price > n2.price ? true : (n1.price == n2.price && n1.index > n2.index ? true : false);
        }
    };
};