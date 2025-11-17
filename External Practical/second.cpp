class Solution {
public:
    const long long MOD = 1e9 + 7;

    long long modpow(long long base, long long e) {
        long long result = 1;
        while (e > 0) {
            if (e & 1) result = (result * base) % MOD;
            base = (base * base) % MOD;
            e >>= 1;
        }
        return result;
    }

    int monkeyMove(int n) {
        long long total = modpow(2, n);    
        long long ans = (total - 2 + MOD) % MOD; 
        return ans;
    }
};
