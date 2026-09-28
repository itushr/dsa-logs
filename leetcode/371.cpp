class Solution {
public:
    int fullAdder(int a, int b, int xcarry) {
        if(!(a | b)) {
            if(xcarry) return 1;
            else return 0;
        }

        int bit1 = a&1;
        int bit2 = b&1;
        int sum = 0;
        int carry = 0;

        if(xcarry) {
            if(bit1 | bit2) carry = 1;
            if(bit1 & bit2) sum = 1;
            else if(!(bit1 | bit2)) sum = 1;
        }else {
            if(bit1 & bit2) {
                sum = 0;
                carry = 1;
            }else if(bit1 | bit2) {
                sum = 1;
            }
        }

        a >>= 1;
        b >>= 1;

        int xsum = fullAdder(a, b, carry);
        xsum <<= 1;
        return sum | xsum;
    }

    int getSum(int a, int b) {
        return fullAdder(a, b, 0);
    }
};