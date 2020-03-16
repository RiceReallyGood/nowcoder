#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int countDislocation(int n, vector<int>& cutIn) {
        if(n == 0 || cutIn.size() == 0) return 0;
        if(cutIn.size() == 1) return cutIn[0] == 1 ? 0 : cutIn[0];
        ListNode* dumhead = new ListNode();
        ListNode* last = dumhead;
        vector<ListNode*> persons(n);
        for(int i = 0; i < n; i++){
            persons[i] = new ListNode();
            last->next = persons[i];
            persons[i]->prev = last;
            last = persons[i];
        }
        last->next = dumhead;
        dumhead->prev = last;

        for(int i = 0; i < cutIn.size(); i++){
            ListNode* node = persons[cutIn[i] - 1];
            node->prev->next = node->next;
            node->next->prev = node->prev;
            node->next = dumhead->next;
            dumhead->next->prev = node;
            dumhead->next = node;
            node->prev = dumhead;
        }

        last = dumhead->next;
        int count = 0;
        for(int i = 0; i < n; i++){
            if(last != persons[i]) count++;
            last = last->next;
        }
        for(int i = 0; i < n; i++)
            delete persons[i];
        delete dumhead;
        return count;
    }

private:
    class ListNode{
    public:
        ListNode() : prev(nullptr), next(nullptr) {}
        ListNode(ListNode* p, ListNode* n) : prev(p), next(n) {}
        ListNode* prev;
        ListNode* next;
    };
};

class Solution {
public:
    int countDislocation(int n, vector<int>& cutIn) {
        if(n == 0 || cutIn.size() == 0) return 0;
        if(cutIn.size() == 1) return cutIn[0] == 1 ? 0 : cutIn[0];
        dumhead = new ListNode();
        dumhead->next = dumhead->prev = dumhead;
        for(int i = 0; i < cutIn.size(); i++){
            if(persons.size() < cutIn[i]) enlarge(cutIn[i]);
            movetohead(persons[cutIn[i] - 1]);
        }

        ListNode* last = dumhead->next;
        int count = 0;
        for(int i = 0; i < persons.size(); i++){
            if(last != persons[i]) count++;
            last = last->next;
        }
        for(int i = 0; i < persons.size(); i++)
            delete persons[i];
        delete dumhead;
        return count;
    }

private:
    class ListNode{
    public:
        ListNode() : prev(nullptr), next(nullptr) {}
        ListNode(ListNode* p, ListNode* n) : prev(p), next(n) {}
        ListNode* prev;
        ListNode* next;
    };

    void enlarge(int sz){
        ListNode* last = dumhead->prev;
        while(persons.size() < sz){
            last->next = new ListNode(last, nullptr);
            last = last->next;
            persons.push_back(last);
        }
        last->next = dumhead;
        dumhead->prev = last;
    }

    void movetohead(ListNode* node){
        node->prev->next = node->next;
        node->next->prev = node->prev;
        node->next = dumhead->next;
        dumhead->next->prev = node;
        dumhead->next = node;
        node->prev = dumhead;
    }

    ListNode* dumhead;
    vector<ListNode*> persons;
};

class Solution {
public:
    int countDislocation(int n, vector<int>& cutIn) {
        int m = cutIn.size();
        if(n == 0 || m == 0) return 0;
        int dislocation = 0;
        for(int i = 0; i < m; i++)
            dislocation = max(dislocation, cutIn[i]);
        unordered_set<int> LatterCutIns;
        for(int i = m - 1; i >= 0; i--){
            if(LatterCutIns.find(cutIn[i]) == LatterCutIns.end()){
                if(LatterCutIns.size() + 1 == cutIn[i]) dislocation--;
                LatterCutIns.insert(cutIn[i]);
            }
        }
        return dislocation;
    }
};