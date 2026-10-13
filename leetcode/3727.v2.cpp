class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        int x = n/2 + n%2;

        for(int i=0; i<n; i++) {
            nums[i] = nums[i]*nums[i];
        }

        sort(nums.begin(), nums.end());

        long long ans = 0;

        int prt1 = 0;
        int prt2 = n-x;

        while (prt1 < n-x) {
            ans += nums[prt2];
            ans -= nums[prt1];
            prt1++;
            prt2++;
        }

        if(n%2) {
            ans += nums[prt2];
        }

        return ans;
    }
};