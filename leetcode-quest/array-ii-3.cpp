class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<int> ans;

        int i = 1;
        int ptr = 0;

        while(i <= nums.size()) {
            if(ptr < nums.size() && nums[ptr] == i) {
                while(ptr < nums.size() && nums[ptr] == i) {
                    ptr++;
                }
                i++;
            }
            else {
                ans.push_back(i);
                i++;
            }
        }

        return ans;
    }
};