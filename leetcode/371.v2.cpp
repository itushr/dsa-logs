class Solution {
public:
    int getSum(int a, int b) {
        int ans = 0;
        int carry = 0;

        for (int i = 0; i < 32; i++) {
            int bit1 = a & 1;
            int bit2 = b & 1;

            int sum = bit1 ^ bit2 ^ carry;
            carry = (bit1 & bit2) | (bit1 & carry) | (bit2 & carry);

            if (sum)
                ans |= (1 << i);

            a >>= 1;
            b >>= 1;
        }

        return ans;
    }
};