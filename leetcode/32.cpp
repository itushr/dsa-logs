class Solution {
public:
    int longestValidParentheses(string s) {
        vector<bool> breakpoint(s.size(), false);

        int balance = 0;

        for(int i=0; i<s.size(); i++) {
            if(s[i] == '(') {
                balance++;
                continue;
            }

            balance--;
            if(balance < 0) {
                breakpoint[i] = true;
                balance = 0;
            }
        }

        balance = 0;

        for(int i=s.size()-1; i>=0; i--) {
            if(breakpoint[i]) {
                balance = 0;
                continue;
            }

            if(s[i] == ')') {
                balance++;
                continue;
            }

            balance--;
            if(balance < 0) {
                breakpoint[i] = true;
                balance = 0;
            }
        }

        int curr = 0;
        int maxi = 0;

        for(bool b: breakpoint) {
            if(!b) {
                curr++;
                maxi = max(maxi, curr);
            } else {
                curr = 0;
            }
        }

        return maxi;
    }
};