class Solution {
public:
    int MinPrimeSum(int N) {
        if(N == 2) return 1;
        if(N % 2 == 0) return 2;

        if(isPrime(N)) return 1;
        if(isPrime(N - 2)) return 2;
        return 3;
    }

private:
    bool isPrime(int n){
        for(int i = 2; i * i <= n; i++)
            if(n % i == 0) return false;
        return true;
    }
};