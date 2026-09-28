class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int zor = 0;

        for(int num: nums) {
            zor ^= num;
        }

        int dif = 0;

        while(!(zor&1)) {
            dif++;
            zor >>= 1;
        }

        int grp1zor = 0;
        int grp2zor = 0;

        for(int num: nums) {
            if((num>>dif)&1) grp1zor ^= num;
            else grp2zor ^= num;
        }

        return {grp1zor, grp2zor};
    }
};