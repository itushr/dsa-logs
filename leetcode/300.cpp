class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        int ans = 1;

        vector<int> dp(n, 1);

        for(int i=0; i<n; i++) {
            int count = 1;
            for(int j= i-1; j>=0; j--) {
                if(nums[j] > nums[i]) {
                    continue;
                }

                if(nums[j] < nums[i]) {
                    count += dp[j];
                    break;
                }else if(nums[j] == nums[i]) {
                    count = dp[j];
                    break;
                }
            }

            ans = max(ans, count);
            dp[i] = count;
        }

        return ans;
    }
};
