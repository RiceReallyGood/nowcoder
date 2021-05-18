#include <iostream>
using namespace std;

int main(){
    int l = 0, r = 0;
    cin >> l >> r;
    cout << ((r - 1) / 3 - (l - 1)/ 3) * 2 - ((l - 1) % 3 > 1 ? 1 : 0) + ((r - 1) % 3) << endl;
}