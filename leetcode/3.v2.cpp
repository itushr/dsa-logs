class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0;
        int r = 0;
        int maxi = 0;

        vector<bool> arr(255, false);

        while(r < s.size()) {
            while(arr[s[r]]) {
                arr[s[l]] = false;
                l++;
            }

            arr[s[r]] = true;
            maxi = max(maxi, r-l+1);
            r++;
        }

        return maxi;
    }
};