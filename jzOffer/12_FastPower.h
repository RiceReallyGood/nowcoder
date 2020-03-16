class Solution {
public:
    double Power(double base, int exponent) {
        if(exponent >= 0) return FastPower(base, exponent);
        else return FastPower(1./base, -exponent);
    }

private:
    double FastPower(double base, int exponent){
        if(exponent == 0) return 1;
        if(exponent & 1) return base * FastPower(base * base, exponent / 2);
        else return FastPower(base * base, exponent / 2);
    }
};