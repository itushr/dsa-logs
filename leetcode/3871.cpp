class Solution {
public:
    long long countCommas(long long n) {
        long long ans = 0;
        long long i = 1;
        int ncomma = 0;

        while(i <= n/1000) {
            i *= 1000;
            ncomma++;
        }

        while(i > 1) {
            ans += (n-(i-1))*ncomma;
            n = i-1;
            i /= 1000;
            ncomma--;
        }

        return ans;
    }
};
