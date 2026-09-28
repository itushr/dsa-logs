class Solution {
public:
    int findComplement(int num) {
        if(!num) return 0;
        
        int res = findComplement(num>>1);
        res <<= 1;
        res |= !(num&1);

        return res;
    }
};