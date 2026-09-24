class Solution {
public:
    int fib(int n) {
        if(n < 2) return n;

        int a = 0;
        int b = 1;

        for(int i=0; i<n-1; i++) {
            int tmp = b;
            b = a+b;
            a = tmp;
        }

        return b;
    }
};