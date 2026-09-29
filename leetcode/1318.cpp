class Solution {
public:
    int minFlips(int a, int b, int c) {
        int ans = 0;
        
        while(a || b || c) {
            int abit = a&1;
            int bbit = b&1;
            int cbit = c&1;

            if((abit | bbit) != cbit) {
                if(cbit == 1) {
                    ans++;
                }else {
                    if(abit == 1) ans++;
                    if(bbit == 1) ans++;
                }
            }

            a >>= 1;
            b >>= 1;
            c >>= 1;
        }

        return ans;
    }
};