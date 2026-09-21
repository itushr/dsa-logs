class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0;
        int r = 0;
        int maxi = 0;

        unordered_map<char, bool> ump;

        while(r < s.size()) {
            while(ump.find(s[r]) != ump.end()) {
                ump.erase(s[l]);
                l++;
            }

            ump[s[r]] = true;
            maxi = max(maxi, r-l+1);
            r++;
        }

        return maxi;
    }
};