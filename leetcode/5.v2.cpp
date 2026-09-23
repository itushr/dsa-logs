class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int ans = 0;
        int ansl = 1;

        for (int i = 0; i < n; i++) {
            int l = i - ansl / 2;
            int r = i + ansl / 2;

            while (l >= 0 && r < n && s[l] == s[r]) {
                if (r - l + 1 > ansl) {
                    ans = l;
                    ansl = r - l + 1;
                }
                l--;
                r++;
            }

            l = i - ansl / 2;
            r = i + 1 + ansl / 2;

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