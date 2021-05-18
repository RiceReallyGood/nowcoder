#include <vector>
#include <random>
using namespace std;

class Solution {
public:
    int solve(int n, int m, int P, vector<int>& a, vector<int>& d, int k) {
        vector<int> count(n);
        for(int i = 0; i < n; i++){
            int x = 0, y = 0;
            exgcd(d[i], P, x, y);
            count[i] = (ll(k - a[i]) * x % P + P) % P;
        }
        partition_3way(count, m - 1, 0, n - 1);
        return count[m - 1];
    }

private:
    using ll = long long;
    int exgcd(int a, int b, int& x, int& y){
        if(b == 0){
            x = 1;
            y = 0;
            return a;
        }

        int res = exgcd(b, a % b, y, x);
        y -= (a / b) * x;
        return res;
    }

    void partition_3way(vector<int>& a, int k, int l, int r){
        swap(a[l], a[l + rand() % (r - l + 1)]);

        int lt = l, gt = r + 1;
        int i = l + 1;
        while(i < gt){
            if(a[i] < a[l]) swap(a[i++], a[++lt]);
            else if(a[i] > a[l]) swap(a[i], a[--gt]);
            else i++;
        }
        swap(a[lt], a[l]);

        if(k < lt) partition_3way(a, k, l, lt - 1);
        else if(k >= gt) partition_3way(a, k, gt, r);
    }
};

class Solution {
public:
    int solve(int n, int m, int P, vector<int>& a, vector<int>& d, int k) {
        vector<int> count(n);
        for(int i = 0; i < n; i++){
            count[i] = (ll(k - a[i]) * inverse(d[i], P) % P + P) % P;
        }
        partition_3way(count, m - 1, 0, n - 1);
        return count[m - 1];
    }

private:
    using ll = long long;
    int inverse(int x, int P){
        return PowModP(x, P - 2, P);
    }

    int PowModP(ll x, int n, int P){
        if(n == 0) return 1;
        if(n & 1) return x * PowModP((x * x) % P, n / 2, P) % P;
        else return PowModP((x * x) % P, n / 2, P);
    }

    void partition_3way(vector<int>& a, int k, int l, int r){
        swap(a[l], a[l + rand() % (r - l + 1)]);

        int lt = l, gt = r + 1;
        int i = l + 1;
        while(i < gt){
            if(a[i] < a[l]) swap(a[i++], a[++lt]);
            else if(a[i] > a[l]) swap(a[i], a[--gt]);
            else i++;
        }
        swap(a[lt], a[l]);

        if(k < lt) partition_3way(a, k, l, lt - 1);
        else if(k >= gt) partition_3way(a, k, gt, r);
    }
};