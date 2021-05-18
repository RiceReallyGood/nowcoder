#include <vector>
using namespace std;

class Solution { //哥德巴赫猜想:
public:
    int work(int n, int* a, int aLen) {
        int maxdiff = 0;
        for(int i = 1; i < n; i++)
            maxdiff = max(maxdiff, a[i] - a[i - 1]);
        vector<bool> isprime(maxdiff + 1, true);
        vector<int> primes;
        for(int i = 2; i <= maxdiff; i++){
            if(isprime[i]) primes.push_back(i);
            for(int j = 0; j < primes.size() && i * primes[j] <= maxdiff; j++){
                isprime[i * primes[j]] = false;
                if(i % primes[j] == 0) break;
            }
        }

        int count = 1;
        for(int i = 1; i < n; i++){
            int diff = a[i] - a[i - 1];
            if(isprime[diff]) count += 1;
            else{
                if(diff % 2 == 0 || isprime[diff - 2])
                    count += 2;
                else
                    count += 3;
            }
        }
        return count;
    }
};