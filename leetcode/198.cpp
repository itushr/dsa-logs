class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        if(n == 1) return nums[0];
        if(n == 2) return max(nums[0], nums[1]);
        if(n == 3) return max(nums[0]+nums[2], nums[1]);

        int a = nums[0];
        int b = nums[1];
        int c = nums[0]+nums[2];
        
        for(int i=3; i<n; i++) {
            int xa = a;
            int xb = b;
            a = b;
            b = c;
            c = max(xa+nums[i], xb+nums[i]);
        }

        return max(b, c);
    }
};