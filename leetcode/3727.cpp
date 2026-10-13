class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        int x = n/2 + n%2;

        for(int i=0; i<n; i++) {
            nums[i] = nums[i]*nums[i];
        }

        sort(nums.begin(), nums.end());

        int ans = 0;

        for(int i=n-x; i<n; i++) {
            ans += nums[i];
        }

        cout << ans;

        for(int i=0; i<n-x; i++) {
            ans -= nums[i];
        }

        return ans;
    }
};