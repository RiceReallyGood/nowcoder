#include <stack>
using namespace std;

class Solution {
public:
    void push(int value) {
        if(minsvalues.empty()){
            minsvalues.push(value);
        }
        else{
            minsvalues.push(std::min(value, minsvalues.top()));
        }
        values.push(value);
    }
    void pop() {
        values.pop();
        minsvalues.pop();
    }
    int top() {
        return values.top();
    }
    int min() {
        return minsvalues.top();
    }

private:
    stack<int> values;
    stack<int> minsvalues;
};