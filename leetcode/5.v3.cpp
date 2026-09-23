class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int ans = 0;
        int ansl = 1;

        for (int i = 0; i < n; i++) {
            int l = i;
            int r = i;

            while (l >= 0 && r < n && s[l] == s[r]) {
                if (r - l + 1 > ansl) {
                    ans = l;
                    ansl = r - l + 1;
                }
                l--;
                r++;
            }

            l = i;
            r = i + 1;

            while (l >= 0 && r < n && s[l] == s[r]) {
                if (r - l + 1 > ansl) {
                    ans = l;
                    ansl = r - l + 1;
                }
                l--;
                r++;
            }
        }

        return s.substr(ans, ansl);
    }
};