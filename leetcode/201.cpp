class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int nbits = 0;
        int copy = right;

        while(copy) {
            nbits++;
            copy >>= 1;
        }

        long long range = (long long)right-left+1;
        vector<int> bits(nbits, 0);

        for(int i=0; i<nbits; i++) {
            if(range > (1 << i)) continue;
            if(((left>>i)&1) == 0) continue;
            bits[i] = (right>>i)&1;
        }

        int ans = 0;

        for(int i=bits.size()-1; i>=0; i--) {
            ans <<= 1;
            ans |= bits[i];
        }

        return ans;
    }
};