class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        
        if(sum%2) return false;

        vector<bool> dp(sum/2+1, false);

        dp[0] = true;

        for(int num: nums) {
            for(int x=sum/2; x >= num; x--) {
                dp[x] = dp[x] || dp[x-num];
            }
        }

        return dp[sum/2];
    }
};