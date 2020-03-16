#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    string Throwdice(int n, int m, int* a, int aLen, int* b, int bLen) {
        vector<int> A(aLen), B(bLen);
        for(int i = 0; i < aLen; i++){
            A[i] = a[i];
            B[i] = b[i];
        }
        sort(A.begin(), A.end());
        sort(B.begin(), B.end());
        long Abound = 1, Bbound = 1;
        for(int i = 0; i < aLen; i++){
            if(A[i] > Abound) break;
            Abound += A[i];
        }

        for(int i = 0; i < bLen; i++){
            if(B[i] > Bbound) break;
            Bbound += B[i];
        }
        if(Abound > Bbound) return "Happy";
        return "Sad";
    }
};

class Solution {
public:
    string Throwdice(int n, int m, int* a, int aLen, int* b, int bLen) {
        sort(a, a + aLen);
        sort(b, b + bLen);
        long Abound = 1, Bbound = 1;
        bool Afinish = false, Bfinish = false;
        for(int i = 0; i < aLen; i++){
            if(!Afinish){
                if(a[i] <= Abound)
                    Abound += a[i];
                else
                    Afinish = true;
            }
            
            if(!Bfinish){
                if(b[i] <= Bbound)
                    Bbound += b[i];
                else
                    Bfinish = true;
            }

            if(Afinish && Bbound >= Abound) return "Sad";
            if(Bfinish && Abound > Bbound) return "Happy";
        }
        if(Abound > Bbound) return "Happy";
        return "Sad";
    }
};

class Solution {
public:
    string Throwdice(int n, int m, int* a, int aLen, int* b, int bLen) {
        QuickSort(a, aLen);
        QuickSort(b, bLen);
        long abound = 1, bbound = 1;
        bool afinish = false, bfinish = false;
        for(int i = 0; i < aLen; i++){
            if(!afinish){
                if(a[i] <= abound)
                    abound += a[i];
                else
                    afinish = true;
            }
            
            if(!bfinish){
                if(b[i] <= bbound)
                    bbound += b[i];
                else
                    bfinish = true;
            }

            if(afinish && bbound >= abound) return "Sad";
            if(bfinish && abound > bbound) return "Happy";
        }
        if(abound > bbound) return "Happy";
        return "Sad";
    }

private:
    void QuickSort(int *a, int aLen){
        if(aLen < 10){
            InsertionSort(a, aLen);
            return;
        }

        swap(a[aLen / 2], a[aLen - 1]);
        int i = 0, j = aLen - 2;
        int achor = a[aLen - 1];
        while(i <= j){
            while(i <= j && a[i] <= achor) i++;
            while(i <= j && a[j] > achor) j--;
            if(i < j) swap(a[i], a[j]);
        }
        swap(a[i], a[aLen - 1]);
        QuickSort(a, i);
        QuickSort(a + i, aLen - i);
    }

    void InsertionSort(int *a, int aLen){
        for(int i = 1; i < aLen; i++){
            int temp = a[i];
            int j = i;
            while(j > 0 && a[j - 1] > temp){
                a[j] = a[j - 1];
                j--;
            }
            a[j] = temp;
        }
    }
};