class Solution {
public:
    //fibonacci[n + 6] - n * (n + 7) / 2 - 8
    int getSum(int n) {
        ll fibn6 = fast_pow(M22(1, 1, 1, 0), n + 5).m11;
        ll sub = (ll(n) * ll(n + 7) / 2l + 8l) % M22::P;
        return fibn6 >= sub ? fibn6 - sub : fibn6 - sub + M22::P;
    }

private:
    using ll = long long;
    struct M22{
        ll m11;
        ll m12;
        ll m21;
        ll m22;
        M22(ll m11_, ll m12_, ll m21_, ll m22_)
        : m11(m11_), m12(m12_), m21(m21_), m22(m22_) {}
        const static ll P = 1e9 + 7;
        friend M22 operator*(const M22& A, const M22& B){
            return M22(
                (A.m11 * B.m11 + A.m12 * B.m21) % P, (A.m11 * B.m12 + A.m12 * B.m22) % P,
                (A.m21 * B.m11 + A.m22 * B.m21) % P, (A.m21 * B.m12 + A.m22 * B.m22) % P
            );
        }
    };

    M22 fast_pow(const M22& M, int n){
        if(n == 0) return M22(1, 0, 0, 1);
        if(n & 1) return M * fast_pow(M * M, n / 2);
        else return fast_pow(M * M, n / 2);
    }
};