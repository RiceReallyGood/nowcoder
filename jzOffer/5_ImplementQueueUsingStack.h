#include <stack>
using namespace std;

class Solution
{
public:
    void push(int node) {
        stack2.push(node);
    }

    int pop() {
        if(stack1.empty()){
            while(!stack2.empty()){
                stack1.push(stack2.top());
                stack2.pop();
            }
        }
        int ret = stack1.top();
        stack1.pop();
        return ret;
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};