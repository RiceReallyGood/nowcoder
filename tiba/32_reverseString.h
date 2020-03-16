#include <string>
using namespace std;

class Solution {
public:
    string change(string number) {
        int len = number.length();
        int i = 0, j = len - 1;
        while(i < j){
            while(i < j && ((number[i] - '0')& 1)) i++;
            while(i < j && ((number[j] - '0')& 1)) j--;
            swap(number[i], number[j]);
            i++, j--;
        }
        return number;
    }
};