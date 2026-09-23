class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int ans = 0;
        int ansl = 1;

        for(int i=0; i<n; i++) {
            int l=i-ansl/2-1;
            int r=i+ansl/2+1;

            while(l>=0 && r<n && s[l]==s[r]) {
                ans = l;
                ansl = r-l+1;
                l--;
                r++;
            }

            l=i-ans/2;
            r=i+1+ans/2;

            while(l>=0 && r<n && s[l]==s[r]) {
                ans = l;
                ansl = r-l+1;
                l--;
                r++;
            }
        }

        return s.substr(ans, ansl);
    }
};