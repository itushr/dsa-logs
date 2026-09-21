class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0;
        int r = 0;
        int x = 0;

        int last[255] = {0};

        while(r < s.size()) {
            l = max(l, last[s[r]]);
            last[s[r]] = r+1;
            x = max(x, r-l+1);
            r++;
        }

        return x;
    }
};