#include <vector>
using namespace std;

class Solution {  //Time: O(n log(n)) Space: O(1) (recurse takes o(n) stack space)
public:
    void reOrderArray(vector<int> &array) {
        if(!array.empty())
            RearrangeAndCountOdd(array, 0, array.size() - 1);
    }

private:
    int RearrangeAndCountOdd(vector<int> &array, int l, int r){
        if(l == r) return (array[l] & 1) == 1 ? 1 : 0;
        int c = l + (r - l) / 2;
        int leftodd = RearrangeAndCountOdd(array, l, c);
        int rightodd = RearrangeAndCountOdd(array, c + 1, r);
        rotate(array, l + leftodd, c + rightodd, rightodd);
        return leftodd + rightodd;
    }

    void rotate(vector<int> &array, int l, int r, int k){
        for(int i = l, j = r; i < j; i++, j--)
            swap(array[i], array[j]);
        for(int i = l, j = l + k - 1; i < j; i++, j--)
            swap(array[i], array[j]);
        for(int i = l + k, j = r; i < j; i++, j--)
            swap(array[i], array[j]);
    }
};

class Solution {  //Time: O(n) Space: O(n)
public:
    void reOrderArray(vector<int> &array) {
        vector<int> rearranged;
        for(int& num : array)
            if(num & 1) rearranged.push_back(num);
        for(int& num : array)
            if(!(num & 1)) rearranged.push_back(num);
        swap(array, rearranged);
    }
};