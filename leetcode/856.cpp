class Solution {
public:
    int duck(string s, int l, int r) {
        if(s.size() == 2) {
            return 1;
        }

        int bal = 0;
        int ans = 0;
        int nextl = l;
        for(; l<=r; l++) {
            if(s[l] == '(') bal++;
            else bal--;

            if(bal == 0) {
                if(l-1 -nextl < 2) {
                    ans += 1;
                }else {
                    ans += 2*duck(s, nextl+1, l-1);
                }
                nextl = l+1;
            }
        }

        return ans;
    }

    int scoreOfParentheses(string s) {
        return duck(s, 0, s.size()-1);
    }
};