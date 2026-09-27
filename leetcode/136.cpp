class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int zor = 0;
        for(int num: nums) {
            zor ^= num;
        }

        return zor;
    }
};