class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans = {0};
        vector<int> dp(n+1, 0);

        for(int i=1; i<=n; i++) {
            int count = 0;
            int x = i;
            while(x) {
                count++;
                x &= (x-1);
                if(dp[x] != 0) {
                    count += dp[x];
                    break;
                }
            }
            dp[i] = count;
            ans.push_back(count);
        }

        return ans;
    }
};