#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution { //神TM 字典序？？？
public:
    vector<string> Permutation(string str) {
        if(str.empty()) return vector<string>();
        vector<int> order(128, -1);
        for(char c = 'a'; c <= 'z'; c++) order[c] = (c - 'a') * 2 + 1;
        for(char c = 'A'; c <= 'Z'; c++) order[c] = (c - 'A') * 2;
        sort(str.begin(), str.end(), [order](const char& c1, const char& c2){ return order[c1] < order[c2]; });
        vector<string> ret;
        ret.push_back(str);
        while(next(str, order))
            ret.push_back(str);
        return ret;
    }

private:
    bool next(string& s, vector<int>& order){
        int len = s.length();
        int index = len - 2;
        while(index >= 0 && order[s[index]] >= order[s[index + 1]]) index--;
        if(index < 0) return false;
        for(int i = index + 1, j = len - 1; i < j; i++, j--)
            swap(s[i], s[j]);
        
        int l = index + 1, r = len - 1;
        while(l < r){
            int c = l + (r - l) / 2;
            if(order[s[c]] <= order[s[index]]) l = c + 1;
            else r = c;
        }
        swap(s[index], s[l]);
        return true;
    }
};

class Solution {
public:
    vector<string> Permutation(string str) {
        if(str.empty()) return vector<string>();
        sort(str.begin(), str.end());
        vector<string> ret;
        ret.push_back(str);
        while(next(str))
            ret.push_back(str);
        return ret;
    }

private:
    bool next(string& s){
        int len = s.length();
        int index = len - 2;
        while(index >= 0 && s[index] >= s[index + 1]) index--;
        if(index < 0) return false;
        for(int i = index + 1, j = len - 1; i < j; i++, j--)
            swap(s[i], s[j]);
        
        int l = index + 1, r = len - 1;
        while(l < r){
            int c = l + (r - l) / 2;
            if(s[c] <= s[index]) l = c + 1;
            else r = c;
        }
        swap(s[index], s[l]);
        return true;
    }
};