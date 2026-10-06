class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int curr = 0;
        int maxi = 0;

        for(int num: nums) {
            if(num == 1) {
                curr++;
                maxi = max(maxi, curr);
            }else {
                curr = 0;
            }
        }

        return maxi;
    }
};