#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n = 0, m = 0;
    cin >> n >> m;
    int d = 0, p = 0;
    vector<pair<int,int>> data;
    for(int i = 0; i < n; i++){
        cin >> d >> p;
        data.emplace_back(d, p);
    }

    sort(data.begin(), data.end());
    for(int i = 1; i < n; i++)
        data[i].second = max(data[i - 1].second, data[i].second);

    vector<int> f(m);
    for(int i = 0; i < m; i++){
        cin >> f[i];
    }

    for(int i = 0; i < m; i++){
        int l = 0, r = n;
        while(l < r){
            int c = l + (r - l) / 2;
            if(data[c].first <= f[i])
                l = c + 1;
            else
                r = c;
        }
        if(l == 0) cout << 0 << endl;
        else cout << data[l - 1].second << endl;
    }
}