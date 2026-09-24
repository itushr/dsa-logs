class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();

        int i_2 = 0;
        int i_1 = 0;

        for(int i=2; i<=n; i++) {
            int tmp = i_2;
            i_2 = i_1;
            i_1 = min(tmp+cost[i-2], i_1+cost[i-1]);
        }

        return i_1;
    }
};