#include <vector>
#include <algorithm>
using namespace std;

struct Point{
    int x;
    int y;
};

class Solution {
public:
    int CatchVirus(int Personid, vector<Point>& PeoplePosition) {
        int y = PeoplePosition[Personid].y;
        auto comp = [](const Point& p1, const Point& p2){
            return p1.x < p2.x;
        };
        sort(PeoplePosition.begin(), PeoplePosition.end(), comp);
        int rightbound = 0, count = 0;
        for(int i = 0; i < PeoplePosition.size(); i++){
            if(PeoplePosition[i].x <= rightbound){
                rightbound = max(rightbound, PeoplePosition[i].y);
                count++;
            }
            else{
                if(rightbound >= y) break;
                rightbound = PeoplePosition[i].y;
                count = 1;
            }
        }
        return count;
    }
};