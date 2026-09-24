class Solution {
public:
    int robi(vector<int>& nums, int n, int offset) {
        if(n == 1) return nums[0+offset];
        if(n == 2) return max(nums[0+offset], nums[1+offset]);
        if(n == 3) return max(nums[0+offset]+nums[2+offset], nums[1+offset]);

        int a = nums[0+offset];
        int b = nums[1+offset];
        int c = nums[0+offset]+nums[2+offset];
        
        for(int i=3+offset; i<n+offset; i++) {
            int xa = a;
            int xb = b;
            a = b;
            b = c;
            c = max(xa+nums[i], xb+nums[i]);
        }

        return max(b, c);
    }

    int rob(vector<int>& nums) {
        return max(
            robi(nums, nums.size()-1, 0),
            robi(nums, nums.size()-1, 1)  
        );
    }
};