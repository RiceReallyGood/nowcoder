class Solution {
public:
    long long solve(int a, int b, int n) {
        return mult_modP((fast_pow_modP(n, b + 1) - fast_pow_modP(n, a) + P) % P, fast_pow_modP(n - 1, P - 2));
    }

private:
    using ll = long long;
    const static ll P = 10000000033L;
    ll mult_modP(ll a, ll b){
        ll a1 = a / 4096, a2 = a % 4096;
        return (4096 * ((a1 * b) % P) + a2 * b) % P;
    }

    ll fast_pow_modP(ll x, int n){
        if(n == 0) return 1;
        if(x & 1) return mult_modP(x, fast_pow_modP(mult_modP(x, x), n / 2));
        else return fast_pow_modP(mult_modP(x, x), n / 2);
    }
};