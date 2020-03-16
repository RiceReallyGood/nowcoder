#include <cstring>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    bool isNumeric(char* string){
        vector<unordered_map<char, int>> states = {
            {{'b', 0}, {'s', 1}, {'n', 2}, {'d', 3}}, //S0
            {{'n', 2}, {'d', 3}},                     //S1
            {{'n', 2}, {'d', 4}, {'e', 5}, {'b', 8}}, //S2
            {{'n', 4}},                               //S3
            {{'n', 4}, {'e', 5}, {'b', 8}},           //S4
            {{'s', 6}, {'n', 7}},                     //S5
            {{'n', 7}},                               //S6
            {{'n', 7}, {'b', 8}},                     //S7
            {{'b', 8}}                                //S8
        };
        unordered_set<int> ValidStates = {2, 4, 7, 8};
        int CurrentState = 0;
        int c;
        int len = strlen(string);
        for (int i = 0; i < len; i++)
        {
            if (string[i] >= '0' && string[i] <= '9')
                c = 'n';
            else if (string[i] == '+' || string[i] == '-')
                c = 's';
            else if (string[i] == '.')
                c = 'd';
            else if (string[i] == 'e' || string[i] == 'E')
                c = 'e';
            else if (string[i] == ' ')
                c = 'b';
            else
                return false;
            if (states[CurrentState].find(c) == states[CurrentState].end())
                return false;
            CurrentState = states[CurrentState][c];
        }
        if (ValidStates.find(CurrentState) == ValidStates.end())
            return false;
        return true;
    }
};