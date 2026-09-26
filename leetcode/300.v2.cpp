class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> tails = {nums[0]};

        for(int num: nums) {
            auto lb = lower_bound(tails.begin(), tails.end(), num);

            if(lb == tails.end()) {
                tails.push_back(num);
            }else {
                *lb = num;
            }
        }

        return tails.size();
    }
};
