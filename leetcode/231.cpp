class Solution {
public:
    bool isPowerOfTwo(int n) {
        n &= (n-1);
        if(n == 0) {
            return true;
        }else {
            return false;
        }
    }
};