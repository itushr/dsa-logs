class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();

        long long E1 = (1LL*n*(n+1))/2;
        long long E2 = (1LL*n*(n+1)*(2*n+1))/6;

        long long S1 = 0;
        long long S2 = 0;

        for(int num: nums) {
            S1 += num;
            S2 += num*num;
        }

        long long C1 = E1-S1;
        long long C2 = E2-S2;

        int R = (C2-C1*C1)/(2*C1);
        int M = C1+R;

        return {R, M};
    }
};