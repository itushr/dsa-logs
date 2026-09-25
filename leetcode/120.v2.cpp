class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if(triangle.size() < 2) {
            return triangle[0][0];
        }

        vector<int> dp = {triangle[0][0]};

        for (int i = 1; i < triangle.size() - 1; i++) {
            vector<int> newDp;
            newDp.push_back(dp[0] + triangle[i][0]);
            for (int j = 1; j < triangle[i].size() - 1; j++) {
                newDp.push_back(
                    min(dp[j - 1] + triangle[i][j], dp[j] + triangle[i][j]));
            }
            newDp.push_back(dp[dp.size() - 1] +
                            triangle[i][triangle[i].size() - 1]);
            dp = newDp;
        }

        int minsum = INT_MAX;

        vector<int> newDp;
        newDp.push_back(dp[0] + triangle[triangle.size() - 1][0]);
        minsum = min(minsum, newDp[0]);

        for (int j = 1; j < triangle[triangle.size() - 1].size() - 1; j++) {
            int minval = min(dp[j - 1] + triangle[triangle.size() - 1][j],
                                dp[j] + triangle[triangle.size() - 1][j]);
            newDp.push_back(minval);
            minsum = min(minsum, minval);
        }

        newDp.push_back(dp[dp.size() - 1] +
                        triangle[triangle.size() - 1]
                                [triangle[triangle.size() - 1].size() - 1]);
        minsum = min(minsum, newDp[newDp.size()-1]);
        dp = newDp;

        return minsum;
    }
};